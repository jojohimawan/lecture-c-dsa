//
// Created by jordan on 4/26/2023.
//
#include <stdio.h>

int faktorialRekursi(int);

int main()
{
    int n;

    printf("Angka n: ");
    scanf("%d", &n);
    if(n <= 0) {
        puts("Masukkan bilangan positif");
    } else {
        printf("Faktorial %d = %d", n, faktorialRekursi(n));
    }

    return 0;
}

int faktorialRekursi(int n)
{
    if(n == 0) {
        return 1;
    } else {
        return n * faktorialRekursi(n - 1);
    }
}