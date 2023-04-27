//
// Created by jordan on 4/26/2023.
//
#include <stdio.h>

int faktorialIterasi(int);

int main()
{
    int n;

    printf("Angka n: ");
    scanf("%d", &n);
    if(n <= 0) {
        puts("Masukkan bilangan positif");
    } else {
        printf("Faktorial %d = %d", n, faktorialIterasi(n));
    }

    return 0;
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