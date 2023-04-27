//
// Created by jordan on 4/26/2023.
//
#include <stdio.h>
#include <math.h>


int cekPrima(int, int);

int main()
{
    int angka;

    printf("Masukkan angka: ");
    scanf("%d", &angka);

    if(!cekPrima(angka, sqrt(angka))) {
        printf("%d BUKAN bilangan prima\n", angka);
    } else {
        printf("%d adalah bilangan PRIMA\n", angka);
    }
}

int cekPrima(int x, int y)
{
    if(y == 1) {
        return 1;
    } else {
        if(x % y == 0) {
            return 0;
        } else {
            return cekPrima(x, y - 1);
        }

    }
}