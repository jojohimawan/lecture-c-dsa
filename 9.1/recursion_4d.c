//
// Created by jordan on 4/26/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu();
int faktorialIterasi(int);
int faktorialRekursi(int);
int faktorialRekursiTail(int, int);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int opsi, flag = 0, angka;
    time_t t1, t2;
    long waktuIterasi, waktuRekursi, waktuRekursiTail;

    do {
        printf("MENU REKURSI\n1. Faktorial Iterasi\n2. Faktorial Rekursi\n3. Faktorial Rekursi Tail\n4. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &opsi);
        fflush(stdin);
        printf("Masukkan angka: ");
        scanf("%d", &angka);

        switch (opsi) {
            case 1:
                time(&t1);
                printf("Faktorial %d = %d\n", angka, faktorialIterasi(angka));
                time(&t2);
                waktuIterasi = difftime(t1, t2);
                printf("Waktu komputasi iterasi = %ld\n", waktuIterasi);
                break;
            case 2:
                time(&t1);
                printf("Faktorial %d = %d\n", angka, faktorialRekursi(angka));
                time(&t2);
                waktuRekursi = difftime(t2, t1);
                printf("Waktu komputasi rekursi = %ld\n", waktuRekursi);
                break;
            case 3:
                time(&t1);
                printf("Faktorial %d = %d\n", angka, faktorialRekursiTail(angka, 1));
                time(&t2);
                waktuRekursiTail = difftime(t2, t1);
                printf("Waktu komputasi rekursi tail = %ld\n", waktuRekursiTail);

                break;
            case 4:
                flag = 1;
                break;
            default :
                puts("Invalid");
                exit(0);
        }

    }while(!flag);
}

int faktorialIterasi(int n)
{
    int hasil = 1;
    while(n != 0) {
        hasil *= n;
        n--;
    }
    return hasil;
}

int faktorialRekursi(int n)
{
    if(n == 0) {
        return 1;
    } else {
        return n * faktorialRekursi(n - 1);
    }
}

int faktorialRekursiTail(int n, int hasil)
{
    if(n == 0) {
        return hasil;
    } else {
        return faktorialRekursiTail(n - 1, n * hasil);
    }
}