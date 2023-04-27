//
// Created by jordan on 4/26/2023.
//
#include <stdio.h>

int fpb(int, int);

int main()
{
    int a, b;

    printf("Masukkan a: ");
    scanf("%d", &a);
    printf("Masukkan b: ");
    scanf("%d", &b);

    printf("FPB dari %d dan %d adalah = %d", a, b, fpb(a, b));

    return 0;
}

int fpb(int x, int y)
{
    if(y == 0) {
        return x;
    } else {
        return fpb(y, x % y);
    }
}