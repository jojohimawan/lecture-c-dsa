//
// Created by jordan on 5/17/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

int MAX;

void menu();
void generateRandom(int []);
void sortShell(int []);
void sortBubble(int []);
void swapElement(int *, int *);
void sequenceSearch(int [], int);
void binarySearch(int [], int);

int main()
{
    printf("Masukkan jumlah data: ");
    scanf("%d", &MAX);
    menu();

    return 0;
}

void menu()
{
    int array[MAX], array_backup[MAX];
    int option, flag = 0, key;
    clock_t start, end;
    double diff;

    srand(time(NULL));
    generateRandom(array);

    do {

        memcpy( array_backup, array, sizeof(array) );

        sortBubble(array_backup);
        if(MAX <= 10) {
            for(int i = 0; i < MAX; i++) {
                printf("%d ", array[i]);
            }
            printf("\n");
            for(int i = 0; i < MAX; i++) {
                printf("%d ", array_backup[i]);
            }
            printf("\n\n");
        }

        printf("MENU METODE SEARCHING\n1. Sequential Search (Unsorted)\n2. Sequential Search (Sorted)\n3. Binary Search\n4. Keluar\n");
        printf("Pilihan anda [1/2/3/4]: ");
        scanf("%d", &option);
        fflush(stdin);
        printf("Masukkan key pencarian: ");
        scanf("%d", &key);
        fflush(stdin);

        sortBubble(array_backup);
        for(int i = 0; i < MAX; i++) {
            printf("%d ", array_backup[i]);
        }
        printf("\n");

        start = time(NULL);
        switch(option) {
            case 1:
                sequenceSearch(array, key);
                break;
            case 2:
                sequenceSearch(array_backup, key);
                break;
            case 3:
                binarySearch(array_backup, key);
                break;
            case 4:
                puts("Keluar");
                flag = 1;
                exit(0);
                break;
            default:
                puts("Invalid");
                exit(0);
        }
        end = time(NULL);
        diff = difftime(end,start)*1000;
        printf("Waktu eksekusi = %.5f ms\n\n", diff);
    } while( !flag );
}

void generateRandom(int A[])
{
    for( int i = 0; i < MAX; i++ ) {
        A[i] = rand() / 1000;
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
                if(A[i] > A[i+jarak]) {
                    swapElement( &A[i], &A[i + jarak] );
                    didSwap = 1;
                }
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
            if(A[i] > A[i+1]) {
                swapElement( &A[i], &A[i + 1] );
                didSwap = 1;
            }
        }
        indexAkhir--;
    }
}

void swapElement(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sequenceSearch(int A[], int key)
{
    int i  = 0, count = 0;

    while (i < MAX) {
        if (A[i] == key) {count++;}
        i++;
    }

    if(!count) {
        printf("Key %d tidak ada\n", key);
    } else {
        printf("Key %d ditemukan sebanyak %d\n", key, count);
    }
}

void binarySearch(int A[], int key)
{
    int l = 0, r = MAX - 1, found = 0, idx = 0;

    while(!found && l <= r) {
        int mid = (l + r) / 2;
        if(key == A[mid]) {
            found++;
            for(int i = mid - 1; i >= l; i--) { // loop to left
                if(key == A[i]) {
                    found++;
                } else if(key != A[i]) {
                    break;
                }
            }
            for(int i = mid + 1; i <= r; i++) { // loop to right
                if(key == A[i]) {
                    found++;
                } else if(key != A[i]) {
                    break;
                }
            }
        } else if(key < A[mid]) {
            r = mid - 1;
        } else if(key > A[mid]) {
            l = mid + 1;
        }
    }

    if(!found) {
        printf("Key %d tidak ada\n", key);
    } else {
        printf("Key %d ditemukan sebanyak %d\n", key, found);
    }
}