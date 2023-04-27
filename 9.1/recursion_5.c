//
// Created by jordan on 4/26/2023.
//
#include <stdio.h>
#include <stdlib.h>

int faktorial(int);
int permutasi(int, int);
int kombinasi(int, int);

int main()
{
    int a, b;

    printf("Input a: ");
    scanf("%d", &a);
    printf("Input b: ");
    scanf("%d", &b);

    if(a < b) {
        puts("a harus lebih dari b");
    } else {
        printf("Permutasi %d dan %d = %d\n", a, b, permutasi(a, b));
        printf("Kombinasi %d dan %d = %d\n", a, b, kombinasi(a, b));
    }

    return 0;
}

int faktorial(int f)
{
    if(f == 0) {
        return 1;
    } else {
        return f * faktorial(f - 1);
    }
}

int permutasi(int f, int p)
{
    return faktorial(f) / faktorial(f - p);
}

int kombinasi(int f, int k)
{
    return faktorial(f) / (faktorial(f) * faktorial(f - k));
}