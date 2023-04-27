//
// Created by jordan on 4/26/2023.
//
#include <stdio.h>

void fibonacciIterasi(int);

int main()
{
    int angka;

    printf("Masukkan angka: ");
    scanf("%d", &angka);
    fibonacciIterasi(angka);

    return 0;
}

void fibonacciIterasi(int n)
{
    int index1 = 0, index2 = 1, nextIndex = index1 + index2;

    printf("%d %d ", index1, index2);
    for(int i = 3; i <= n; i++) {
        printf("%d ", nextIndex);
        index1 = index2;
        index2 = nextIndex;
        nextIndex = index1 + index2;
    }
}