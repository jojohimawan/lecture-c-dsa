//
// Created by jordan on 5/4/2023.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int orderBy, c, m, s;
typedef struct murid {
    int no;
    char nama[20];
    int nilai;
} Data;

void printArray(Data []);
void sortShell(Data []);
void swapElement(Data *, Data *);

int main()
{
    Data students[MAX] = {5,"Seulgi",77,3,"Irene",90,10,"Yerim",60,2,"Joy",63,7,"Wendy",89};

    printArray(students);

    sortShell( students );

    printArray( students );

    printf("Movement = %d Compare = %d Swap = %d\n", m, c, s);
}

void printArray(Data A[])
{
    printf("Array sebelum sorting\nNO\tNAMA\tNILAI\n");
    for(int i = 0; i < MAX; i++){
        printf("%d\t%s\t%d\n", A[i].no, A[i].nama, A[i].nilai);
    }
    printf("\n");
}

void sortShell(Data A[])
{
    int jarak = MAX, didSwap;

    while( jarak > 1) {
        jarak /= 2;
        didSwap = 1;
        while( didSwap ) {
            didSwap = 0;
            for( int i = 0; i < MAX - jarak; i++ ) {
                c++;
                if(A[i].no > A[i + jarak].no) {
                    swapElement(&A[i], &A[i + jarak]);
                    s++;
                    m+=3;
                    didSwap = 1;
                }
            }
        }
    }
}

void swapElement(Data *a, Data *b)
{
    Data temp;

    temp = *a;
    *a = *b;
    *b = temp;
}