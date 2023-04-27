//
// Created by jordan on 4/26/2023.
//
#include <stdio.h>
#include <stdlib.h>

void cetakAngka(int);

int main()
{
    int angka;
    printf("Masukkan angka n: ");
    scanf("%d", &angka);
    cetakAngka(angka);
    return 0;
}

void cetakAngka(int n)
{
    if(n < 0) {
        exit(0);
    } else {
        printf("%d ", n);
        cetakAngka(n - 1);
    }
}