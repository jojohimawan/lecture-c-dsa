//
// Created by jordan on 5/2/2023.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

char orderBy;

void menu();
void selectOrder();
void printBaseArray(int []);
void sortSelection(int []);
void sortInsertion(int []);
void swapElement(int *, int *);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int array[MAX] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
    int option;

    printf("MENU METODE SORTING\n1. Insertion Sort\n2. Selection Sort\n3. Keluar\n");
    printf("Pilihan anda [1/2/3]: ");
    scanf("%d", &option);
    fflush(stdin);

    selectOrder();
    printBaseArray(array);

    switch(option) {
        case 1:
            sortInsertion(array);
            break;
        case 2:
            sortSelection(array);
            break;
        case 3:
            puts("Keluar");
            exit(0);
        default:
            puts("Invalid");
            exit(0);
    }

}

void selectOrder()
{
    printf("Pengurutan [a = asc, d = desc]: ");
    scanf("%c", &orderBy);
}

void printBaseArray(int A[])
{
    printf("Array sebelum sort = ");
    for(int i = 0; i < MAX; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void sortInsertion(int A[])
{
    int i, j, key;

    for( i = 1; i < MAX; i++ ) {
        key = A[i];
        j = i - 1;
        if(orderBy == 'a' || orderBy == 'A') {
            while( (j >= 0) && (A[j]) > key ) {
                swapElement(&A[j+1], &A[j]);
                j--;
            }
        } else if(orderBy == 'd' || orderBy == 'D') {
            while( (j >= 0) && (A[j]) < key ) {
                swapElement(&A[j+1], &A[j]);
                j--;
            };
        } else {
            puts("Order invalid");
            exit(0);
        }
        A[j+1] = key;
    }

    printf("Array setelah insertion sort = ");
    for(int i = 0; i < MAX; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void sortSelection(int A[])
{
    int peak_index;

    for( int i = 0; i < MAX-1; i++ ) {
        for( int j = i+1; j <= MAX-1; j++ ) {
            if(orderBy == 'a' || orderBy == 'A') {
                if(A[j] < A[i]) {
                    peak_index = j;
                    swapElement(&A[peak_index], &A[i]);
                };
            } else if(orderBy == 'd' || orderBy == 'D') {
                if(A[j] > A[i]) {
                    peak_index = j;
                    swapElement(&A[peak_index], &A[i]);
                };
            } else {
                puts("Order invalid");
                exit(0);
            }
        }
    }

    printf("Array setelah selection sort = ");
    for(int i = 0; i < MAX; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

}

void swapElement(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}