//
// Created by jordan on 4/26/2023.
//
#include <stdio.h>

int fibonacciRekursi(int);

int main()
{
    int n;

    printf("Masukkan n: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("%d ", fibonacciRekursi(i));
    }

    return 0;
}

int fibonacciRekursi(int x)
{
    if(x == 0 || x == 1) {
        return x;
    } else {
        return fibonacciRekursi(x - 1) + fibonacciRekursi(x - 2);
    }
}