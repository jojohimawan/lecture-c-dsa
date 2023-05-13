//
// Created by jordan on 5/2/2023.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

char orderBy;

void sortInsertion(int []);
void swapElement(int *, int *);

int main()
{
    int arr_1[MAX] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
    int arr_2[MAX] = {1, 2, 3, 4, 5, 9, 7, 6, 8, 10};
    int arr_3[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr_4[MAX] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    printf("Pengurutan (a = asc, d = desc): ");
    scanf("%c", &orderBy);
    for(int i = 0; i < MAX; i++){
        printf("%d ", arr_1[i]);
    }
    printf("\n");

    sortInsertion(arr_1);

    for(int i = 0; i < MAX; i++){
        printf("%d ", arr_1[i]);
    }
    printf("\n");


    return 0;
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
}

void swapElement(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}