#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int tambah(int a, int b){ 
    return a + b; 
}

int kurang(int a, int b){
    return a - b;
}

int kali(int a, int b){
    return a * b;
}

float bagi(int a, int b){
    if (b == 0) {
        printf("Error: ga bisa dibagi 0\n");
        exit(1);
    }
    return (float)a / b;
}

int faktorial(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return 1;
    return n * faktorial(n - 1);
}

int fpb(int a, int b) {
    if (b == 0) return a;
    return fpb(b, a % b);
}


int kpk(int a, int b) {
    return (a * b) / fpb(a, b);
}

int main() {
    char input[100];
    char *token;
    int a, b;
    float hasilDiv;

    printf("Kalkulator Sederhana\n");
    printf("kalku untuk menghitung ADD(tambah), SUB(kurang), TIMES(kali), DIV(bagi), KPK, FPB, FAC(faktorial)\n");
    printf("Ketik 'EXIT' jika mau keluar\n");

    while (1) {
        printf("\ninput operasi co: 5 ADD 5:\n");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        //cek exit ga
        if (strcmp(input, "EXIT") == 0) {
            printf("akhirnya program berhenti hehe\n");
            break;
        }

        token = strtok(input, " ");
        if (token == NULL) {
            printf("input salah\n");
            continue;
        }
        a = atoi(token);

        while ((token = strtok(NULL, " ")) != NULL) {
            char operasi[10];
            strcpy(operasi, token); 

            if (strcmp(operasi, "FAC") == 0) {
                a = faktorial(a);
                break;
            }

            token = strtok(NULL, " ");
            if (token == NULL) {
                printf("Error mang, angkamu cuma 1\n");
                break;
            }
            b = atoi(token);

            if (strcmp(operasi, "ADD") == 0) {
                a = tambah(a, b);
            } else if (strcmp(operasi, "SUB") == 0) {
                a = kurang(a, b);
            } else if (strcmp(operasi, "TIMES") == 0) {
                a = kali(a, b);
            } else if (strcmp(operasi, "DIV") == 0) {
                hasilDiv = bagi(a, b);
                a = (int)hasilDiv; // Gunakan bagian bilangan bulat
            } else if (strcmp(operasi, "KPK") == 0) {
                a = kpk(a, b);
            } else if (strcmp(operasi, "FPB") == 0) {
                a = fpb(a, b);
            } else {
                printf("operasimu salah woe\n");
                break;
            }
        }

        printf("Hasil akhirnya %d\n", a);
    }

    return 0;
}
