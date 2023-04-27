//
// Created by jordan on 4/26/2023.
//
#include <stdio.h>

void menu();
void fibonacciIterasi(int);
int fibonacciRekursi(int);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int opsi, flag = 0, angka;

    do {
        printf("MENU FIBONACCI\n1. Fibonacci Iterasi\n2. Fibonacci Rekursi\n3. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &opsi);
        fflush(stdin);
        printf("Masukkan n: ");
        scanf("%d", &angka);

        switch(opsi) {
            case 1:
                fibonacciIterasi(angka);
                printf("\n");
                break;
            case 2:
                for(int i = 0; i < angka; i++) {
                    printf("%d ", fibonacciRekursi(i));
                }
                printf("\n");
                break;
            case 3:
                flag = 1;
                break;
            default:
                puts("Invalid");
                break;
        }

    } while(!flag);
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

int fibonacciRekursi(int x)
{
    if(x == 0 || x == 1) {
        return x;
    } else {
        return fibonacciRekursi(x - 1) + fibonacciRekursi(x - 2);
    }
}