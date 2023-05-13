//
// Created by jordan on 5/3/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

#define MAX 10

int orderBy, m, c, s;

void generateRandom(int []);
void selectOrder();
void printArray(int []);
void printTrace();
void sortBubble(int []);
void sortShell(int []);
void swapElement(int *, int *);

int main()
{
    int arr_1[MAX] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
    int arr_2[MAX] = {1, 2, 3, 4, 5, 9, 7, 6, 8, 10};
    int arr_3[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // best
    int arr_4[MAX] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // worst
    int arr_5[MAX] = { 5, 1, 3, 4, 2, 7, 8, 9, 10, 6 };
//    int arr[20000];
    clock_t start, end;
    double execution_time;

    int arr_backup[MAX];
    memcpy(arr_backup, arr_4, sizeof(arr_3));

    srand(time(NULL));
    generateRandom(arr_backup);

    selectOrder();

    puts("Array sebelum sort = ");
    printArray(arr_backup);

    start = clock();
    sortShell(arr_backup);
    end = clock();

    puts("Array setelah sort = ");
    printArray(arr_backup);

    printTrace();

    printf("Waktu eksekusi = %.2f detik\n", ( (double) ( end - start )) / CLOCKS_PER_SEC );

    return 0;
}

void generateRandom(int A[])
{
    for( int i = 0; i < MAX; i++ ) {
        A[i] = rand() / 1000;
    }
}

void selectOrder()
{
    printf("Pengurutan [1 = asc, 2 = desc]: ");
    scanf("%d", &orderBy);
}

void printArray(int A[])
{
    for(int i = 0; i < MAX; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void printTrace()
{
    printf("Comparison = %d, Swap = %d, Movement = %d\n", c, s, m);
}

void sortBubble(int A[])
{
    int indexAkhir = MAX - 2, didSwap = 1;

        while( didSwap ) {
            didSwap = 0;
            for( int i = 0; i <= indexAkhir; i++ ) {

                if(orderBy == 1) {
                    c++;
                    if( A[i] > A[i + 1] ) {
                        swapElement( &A[i], &A[i + 1] );
                        s++;
                        m += 3;
                        didSwap = 1;
                    }
                } else if(orderBy == 2) {
                    c++;
                    if( A[i] < A[i + 1] ) {
                        swapElement( &A[i], &A[i + 1] );
                        s++;
                        m += 3;
                        didSwap = 1;
                    }
                } else {
                    puts("Mode pengurutan invalid");
                    exit(0);
                }
            }
            indexAkhir--;
        }
}

void sortShell(int A[])
{
    int jarak = MAX, didSwap = 1;

    while( jarak > 1 ) {
        jarak = jarak / 2;
        didSwap = 1;
        while( didSwap ) {
            didSwap = 0;
            for( int i = 0; i < MAX - jarak; i++ ) {
                c++;
                int ascdesc = (orderBy == 1) ? (A[i] > A[i + jarak]) : (A[i] < A[i + jarak]);
                if( ascdesc ) {
                    swapElement(&A[i], &A[i + jarak]);
                    s++;
                    m += 3;
                    didSwap = 1;
                }
            }
        }
    }
}

void swapElement(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}