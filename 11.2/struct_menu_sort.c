//
// Created by jordan on 5/5/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define MAX 5

int orderBy, sortBy;
typedef struct murid {
    int no;
    char nama[10];
    int nilai;
} Data;

void menu();
void selectSortBy();
void inputSiswa(Data []);
void selectOrder();
void printArray(Data []);
void sortSelection(Data []);
void sortInsertion(Data []);
void sortShell(Data []);
void sortBubble(Data []);
void swapElement(Data *, Data *);


int main()
{
    menu();
    return 0;
}

void menu()
{
    Data siswa[MAX], siswa_backup[MAX];
    int option, flag = 0;

    inputSiswa(siswa);

    do {
        printf("MENU METODE SORTING\n1. Insertion Sort\n2. Selection Sort\n3. Shell Sort\n4. Bubble Sort\n5. Keluar\nPilihan anda [1/2/3/4/5]: ");
        scanf("%d", &option);
        fflush(stdin);

        selectOrder();
        selectSortBy();
        memcpy(siswa_backup, siswa, sizeof(siswa));
        printArray(siswa_backup);

        switch(option) {
            case 1:
                sortInsertion(siswa_backup);
                break;
            case 2:
                sortSelection(siswa_backup);
                break;
            case 3:
                sortShell(siswa_backup);
                break;
            case 4:
                sortBubble(siswa_backup);
                break;
            case 5:
                puts("Keluar");
                flag = 1;
                break;
            default:
                puts("Invalid");
                exit(0);
        }
        printArray(siswa_backup);
    } while(!flag);
}

void inputSiswa(Data A[])
{
    for(int i = 0; i < MAX; i++) {
        printf("No: ");
        scanf("%d", &A[i].no);
        fflush(stdin);
        printf("Nama: ");
        scanf("%[^\n]%*c", &A[i].nama);
        fflush(stdin);
        printf("Nilai: ");
        scanf("%d", &A[i].nilai);
        fflush(stdin);
    }
}

void selectSortBy()
{
    printf("Sorting berdasarkan: \n1. No\n2. Nama\n3. Nilai\n[1/2/3]: ");
    scanf("%d", &sortBy);
}

void selectOrder()
{
    printf("Pengurutan yang dipilih: \n1.Ascending\n2. Descending\nPilihan anda [1/2]: ");
    scanf("%d", &orderBy);
}

void printArray(Data A[])
{
    printf("NO\tNAMA\tNILAI\n");
    for(int i = 0; i < MAX; i++){
        printf("%d\t%s\t%d\n", A[i].no, A[i].nama, A[i].nilai);
    }
    printf("\n");
}

void sortInsertion(Data A[])
{
    int i, j, key;
    char keyName[10];

    for( i = 1; i < MAX; i++ ) {
        j = i - 1;
        if(sortBy == 1) {
            key = A[i].no;
            if(orderBy == 1) {
                while( (j >= 0) && (A[j].no) > key ) {
                    swapElement(&A[j+1], &A[j]);
                    j--;
                }
            } else if(orderBy == 2) {
                while( (j >= 0) && (A[j].no) < key ) {
                    swapElement(&A[j+1], &A[j]);
                    j--;
                };
            } else {
                puts("Order invalid");
                exit(0);
            }
            A[j+1].no = key;
        } else if(sortBy == 2) {
            memcpy(keyName, A[i].nama, sizeof(A[i].nama));
            if(orderBy == 1) {
                while( (j >= 0) && strcmp(A[j].nama, keyName) > 0) {
                    swapElement(&A[j+1], &A[j]);
                    j--;
                }
            } else if(orderBy == 2) {
                while( (j >= 0) && strcmp(A[j].nama, keyName) < 0 ) {
                    swapElement(&A[j+1], &A[j]);
                    j--;
                };
            } else {
                puts("Order invalid");
                exit(0);
            }
            memcpy(A[j+1].nama, keyName, sizeof(A[j+1].nama));
        } else if(sortBy == 3) {
            key = A[i].nilai;
            if(orderBy == 1) {
                while( (j >= 0) && (A[j].nilai) > key ) {
                    swapElement(&A[j+1], &A[j]);
                    j--;
                }
            } else if(orderBy == 2) {
                while( (j >= 0) && (A[j].nilai) < key ) {
                    swapElement(&A[j+1], &A[j]);
                    j--;
                };
            } else {
                puts("Order invalid");
                exit(0);
            }
            A[j+1].nilai = key;
        } else {

        }
    }
}

void sortSelection(Data A[])
{
    int peak_index, didSwap = 1, compare;

   while(didSwap) {
       for( int i = 0; i < MAX-1; i++ ) {
           didSwap = 0;
           for( int j = i+1; j <= MAX-1; j++ ) {
               if(sortBy == 1) {
                   compare = (orderBy == 1) ? (A[j].no < A[i].no) : (A[j].no > A[i].no);
                   if(compare) {
                       peak_index = j;
                       swapElement(&A[peak_index], &A[i]);
                       didSwap = 1;
                   }
               } else if(sortBy == 2) {
                   compare = (orderBy == 1) ? strcmp(A[j].nama, A[i].nama) < 0 : strcmp(A[j].nama, A[i].nama) > 0;
                   if(compare) {
                       peak_index = j;
                       swapElement(&A[peak_index], &A[i]);
                       didSwap = 1;
                   }
               } else if (sortBy == 3) {
                   compare = (orderBy == 1) ? (A[j].nilai < A[i].nilai) : (A[j].nilai > A[i].nilai);
                   if(compare) {
                       peak_index = j;
                       swapElement(&A[peak_index], &A[i]);
                       didSwap = 1;
                   }
               } else {
                   puts("Opsi sorting invalid");
               }
           }
       }
   }
}

void sortShell(Data A[])
{
    int jarak = MAX, didSwap, compare;

    if( orderBy < 1 || orderBy > 2 ) { puts("Pengurutan invalid"); exit(0); }

    while( jarak > 1) {
        jarak /= 2;
        didSwap = 1;
        while( didSwap ) {
            didSwap = 0;
            for( int i = 0; i < MAX - jarak; i++ ) {
                if(sortBy == 1) {
                    compare = (orderBy == 1) ? (A[i].no > A[i + jarak].no) : (A[i].no < A[i + jarak].no);
                    if(compare) {
                        swapElement(&A[i], &A[i + jarak]);
                        didSwap = 1;
                    }
                } else if(sortBy == 2) {
                    compare = (orderBy == 1) ? strcmp(A[i].nama, A[i + 1].nama) > 0 : strcmp(A[i].nama, A[i + 1].nama) < 0;
                    if(compare) {
                        swapElement(&A[i], &A[i + 1]);
                        didSwap = 1;
                    }
                } else if(sortBy == 3) {
                    compare = (orderBy == 1) ? (A[i].nilai > A[i + 1].nilai) : (A[i].nilai < A[i + 1].nilai);
                    if(compare) {
                        swapElement(&A[i], &A[i + 1]);
                        didSwap = 1;
                    }
                } else {
                    puts("Opsi sorting invalid");
                }
            }
        }
    }
}

void sortBubble(Data A[])
{
    int indexAkhir = MAX - 2, didSwap = 1, compare;

    if( orderBy < 1 || orderBy > 2 ) { puts("Pengurutan invalid"); exit(0); }

    while( didSwap) {
        didSwap = 0;
        for(int i = 0; i <= indexAkhir; i++) {
            if( sortBy == 1 ) {
                compare = (orderBy == 1) ? (A[i].no > A[i + 1].no) : (A[i].no < A[i + 1].no);
                if(compare) {
                    swapElement(&A[i], &A[i + 1]);
                    didSwap = 1;
                }
            } else if( sortBy == 2 ) {
                compare = (orderBy == 1) ? strcmp(A[i].nama, A[i + 1].nama) > 0 : strcmp(A[i].nama, A[i + 1].nama) < 0;
                if(compare) {
                    swapElement(&A[i], &A[i + 1]);
                    didSwap = 1;
                }
            } else if( sortBy == 3 ) {
                compare = (orderBy == 1) ? (A[i].nilai > A[i + 1].nilai) : (A[i].nilai < A[i + 1].nilai);
                if(compare) {
                    swapElement(&A[i], &A[i + 1]);
                    didSwap = 1;
                }
            } else {
                puts("Opsi sorting invalid");
                exit(0);
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