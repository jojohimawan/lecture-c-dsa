//
// Created by jordan on 4/26/2023.
//

#include <stdio.h>

int faktorialRekursiTail(int, int);

int main()
{
    int n;

    printf("Angka n: ");
    scanf("%d", &n);
    if(n <= 0) {
        puts("Masukkan bilangan positif");
    } else {
        printf("Faktorial %d = %d", n, faktorialRekursiTail(n, 1));
    }

    return 0;
}

int faktorialRekursiTail(int n, int hasil)
{
    if(n == 0) {
        return hasil;
    } else {
        return faktorialRekursiTail(n - 1, n * hasil);
    }
}