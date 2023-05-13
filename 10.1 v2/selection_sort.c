//
// Created by jordan on 4/27/2023.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

char orderBy;

void sortSelection(int []);
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

    sortSelection(arr_1);



    for(int i = 0; i < MAX; i++){
        printf("%d ", arr_1[i]);
    }
    printf("\n");


    return 0;
}

void sortSelection(int A[])
{
    for( int i = 0; i < MAX-1; i++ ) {
        for( int j = i+1; j <= MAX-1; j++ ) {
            if(orderBy == 'a' || orderBy == 'A') {
                if(A[j] < A[i]) { swapElement(&A[i], &A[j]); };
            } else if(orderBy == 'd' || orderBy == 'D') {
                if(A[j] > A[i]) { swapElement(&A[i], &A[j]); };
            } else {
                puts("Order invalid");
                exit(0);
            }
        }
    }
}

void swapElement(int *a, int *b)
{
    // peak adalah variabel utk min atau max
    int temp, peak;

    peak = *b;
    temp = *a;
    *a = peak;
    *b = temp;
}