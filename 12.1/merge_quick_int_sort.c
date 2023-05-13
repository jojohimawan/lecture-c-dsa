//
// Created by jordan on 5/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX 10

void printArray(int []);
void sortMerge(int, int, int []);
void arrayMerge(int, int, int, int[]);
void sortQuick(int, int, int []);
int partitionQuick(int, int, int []);
void swapElement(int *, int *);

int main()
{
    int arr_1[MAX] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
    int arr_2[MAX] = {1, 2, 3, 4, 5, 9, 7, 6, 8, 10};
    int arr_3[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // best
    int arr_4[MAX] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // worst
    int arr_5[MAX] = { 5, 1, 1, 4, 7, 7, 8, 9, 10, 6 };
    int left = 0, right = MAX-1;


    printArray(arr_5);
    sortQuick(left, right, arr_5);
    printArray(arr_5);

    return 0;
}

void printArray(int A[])
{
    for(int i = 0; i < MAX; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void sortMerge(int l, int r, int A[])
{
    int med;

    if(l < r) {
        med = (l + r) / 2;
        sortMerge(l, med, A);
        sortMerge(med+1, r, A);
        arrayMerge(l, med, r, A);
    }
}

void arrayMerge(int l, int m, int r, int A[])
{
    int left1, right1, left2, right2, i, A_backup[MAX];
    left1 = l;
    right1 = m;
    left2 = m+1;
    right2 = r;
    i = l;

    while ((left1 <= right1) && (left2 <= right2)) {
        if(A[left1] <= A[left2]) {
            A_backup[i] = A[left1];
            left1++;
        } else {
            A_backup[i] = A[left2];
            left2++;
        }
        i++;
    }

    while(left1 <= right1) {
        A_backup[i] = A[left1];
        left1++;
        i++;
    }

    while(left2 <= right2) {
        A_backup[i] = A[left2];
        i++;
        left2++;
    }


    int j = l;
    while (j <= r) {
        A[j] = A_backup[j];
        j++;
    }

}

void sortQuick(int p, int r, int A[])
{
    int q;

    if( p < r ) {
        q = partitionQuick(p, r, A);
        sortQuick(p, q, A);
        sortQuick(q+1, r, A);
    }
}

int partitionQuick(int p, int r, int A[])
{
    int pivot, i, j;

    pivot = A[p];
    i = p;
    j = r;

    do {
        while(A[j] > pivot) {
            j--;
        }
        while(A[i] < pivot) {
            i++;
        }

        if( i<j ) {
            swapElement(&A[i], &A[j]);
            j--;
            i++;
        } else {
            return j;
        }
    }while( i <= j);

    return j;
}

void swapElement(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}