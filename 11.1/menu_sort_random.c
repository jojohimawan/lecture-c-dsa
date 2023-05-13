//
// Created by jordan on 5/2/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#define MAX 50000

int orderBy;

void menu();
void generateRandom(int []);
void printArray(int []);
void selectOrder();
void sortSelection(int []);
void sortInsertion(int []);
void sortBubble(int []);
void sortShell(int []);
void swapElement(int *, int *);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int array[MAX], array_backup[MAX];
    int option, flag = 0;
    clock_t start, end;
    double diff;

    srand(time(NULL));
    generateRandom(array);

    do {

        memcpy( array_backup, array, sizeof(array) );

        printf("MENU METODE SORTING\n1. Insertion Sort\n2. Selection Sort\n3. Shell Sort\n4. Bubble Sort\n5. Keluar\n");
        printf("Pilihan anda [1/2/3/4/5]: ");
        scanf("%d", &option);
        fflush(stdin);

        selectOrder();

        start = time(NULL);
        switch(option) {
            case 1:
                sortInsertion(array_backup);
                break;
            case 2:
                sortSelection(array_backup);
                break;
            case 3:
                sortShell(array_backup);
                break;
            case 4:
                sortBubble(array_backup);
                break;
            case 5:
                puts("Keluar");
                exit(0);
            default:
                puts("Invalid");
                exit(0);
        }
        end = time(NULL);
        diff = difftime(end,start)*1000;

        if(MAX <= 10) {
            printArray(array_backup);
        }
        printf("Waktu eksekusi = %.2f ms\n", diff);
    } while( !flag );

}

void generateRandom(int A[])
{
    for( int i = 0; i < MAX; i++ ) {
        A[i] = rand() / 1000;
    }
}

void printArray(int A[])
{
    for(int i = 0; i < MAX; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectOrder()
{
    printf("Pengurutan [1 = asc, 2 = desc]: ");
    scanf("%d", &orderBy);
    fflush(stdin);
}

void sortInsertion(int A[])
{
    int i, j, key;

    for( i = 1; i < MAX; i++ ) {
        key = A[i];
        j = i - 1;
        if(orderBy == 1) {
            while( (j >= 0) && (A[j]) > key ) {
                swapElement(&A[j+1], &A[j]);
                j--;
            }
        } else if(orderBy == 2) {
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

void sortSelection(int A[])
{
    int peak_index;

    for( int i = 0; i < MAX-1; i++ ) {
        for( int j = i+1; j <= MAX-1; j++ ) {
            if(orderBy == 1) {
                if(A[j] < A[i]) {
                    peak_index = j;
                    swapElement(&A[peak_index], &A[i]);
                };
            } else if(orderBy == 2) {
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
}

void sortBubble(int A[])
{
    int indexAkhir = MAX - 2, didSwap = 1;

    while( didSwap ) {
        didSwap = 0;
        for( int i = 0; i <= indexAkhir; i++ ) {

            if(orderBy == 1) {
                if( A[i] > A[i + 1] ) {
                    swapElement( &A[i], &A[i + 1] );
                    didSwap = 1;
                }
            } else if(orderBy == 2) {
                if( A[i] < A[i + 1] ) {
                    swapElement( &A[i], &A[i + 1] );
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
                if( orderBy == 1 ) {
                    if( A[i] > A[i + jarak ] ) {
                        swapElement( &A[i], &A[i + jarak] );
                        didSwap = 1;
                    }
                } else if(orderBy == 2) {
                    if( A[i] < A[i + jarak ] ) {
                        swapElement( &A[i], &A[i + jarak] );
                        didSwap = 1;
                    }
                } else {
                    puts("Mode pengurutan invalid");
                    exit(0);
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