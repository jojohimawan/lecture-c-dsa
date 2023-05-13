//
// Created by jordan on 5/2/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#define MAX 30000

int orderBy;

void menu();
void generateRandom(int []);
void inputArray(int []);
void printArray(int []);
void selectOrder();
void sortSelection(int []);
void sortInsertion(int []);
void sortBubble(int []);
void sortShell(int []);
void sortMerge(int, int, int []);
void arrayMerge(int, int, int, int[]);
void sortQuick(int, int, int []);
int partitionQuick(int, int, int []);
void swapElement(int *, int *);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int array[MAX], array_backup[MAX];
    int option, flag = 0, random = 0;
    clock_t start, end;
    double diff;

    printf("Random? [1/0]: ");
    scanf("%d", &random);

    if(random) {
        srand(time(NULL));
        generateRandom(array);
    } else {
        inputArray(array);
    }

    do {

        memcpy( array_backup, array, sizeof(array) );

        printf("MENU METODE SORTING\n1. Insertion Sort\n2. Selection Sort\n3. Shell Sort\n4. Bubble Sort\n5. Merge Sort\n6. Quick Sort\n7. Keluar\n");
        printf("Pilihan anda [1/2/3/4/5/6/7]: ");
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
                sortMerge(0, MAX-1, array_backup);
                break;
            case 6:
                sortQuick(0, MAX-1, array_backup);
                break;
            case 7:
                puts("Keluar");
                flag = 1;
                break;
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

void inputArray(int A[])
{
    for(int i = 0; i < MAX; i++) {
        printf("i-%d: ", i);
        scanf("%d", &A[i]);
        fflush(stdin);
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
            if(orderBy <= 0 || orderBy > 2) {
                puts("Mode pengurutan invalid");
                exit(0);
            } else {
                if((orderBy == 1 && A[j] < A[i]) || (orderBy == 2 && A[j] > A[i])) {
                    peak_index = j;
                    swapElement(&A[peak_index], &A[i]);
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
            if(orderBy <= 0 || orderBy > 2) {
                puts("Mode pengurutan invalid");
                exit(0);
            } else {
                if((orderBy == 1 && A[i] > A[i+1]) || (orderBy == 2 && A[i] < A[i+1])) {
                    swapElement( &A[i], &A[i + 1] );
                    didSwap = 1;
                }
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
                if(orderBy <= 0 || orderBy > 2) {
                    puts("Mode pengurutan invalid");
                    exit(0);
                } else {
                    if((orderBy == 1 && A[i] > A[i+jarak]) || (orderBy == 2 && A[i] < A[i+jarak])) {
                        swapElement( &A[i], &A[i + jarak] );
                        didSwap = 1;
                    }
                }
            }
        }
    }
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
        if((orderBy == 1 && A[left1] <= A[left2]) || (orderBy == 2 && A[left1] >= A[left2])) {
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
        while((orderBy == 1 && A[j] > pivot) || (orderBy == 2 && A[j] < pivot)) {
            j--;
        }
        while((orderBy == 1 && A[i] < pivot) || (orderBy == 2 && A[i] > pivot)) {
            i++;
        }

        if( i<j ) {
            swapElement(&A[i], &A[j]);
            j--;
            i++;
        } else {
            return j;
        }
    } while(i <= j);

    return j;
}

void swapElement(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}