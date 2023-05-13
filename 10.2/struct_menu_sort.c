//
// Created by jordan on 5/2/2023.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int orderBy;
typedef struct murid {
    int no;
    char nama[MAX];
    char nilai;
} Data;

void menu();
void inputSiswa(Data []);
void selectOrder();
void printBaseArray(Data []);
void sortSelection(Data []);
void sortInsertion(Data []);
void swapElement(Data *, Data *);


int main()
{
    menu();
    return 0;
}

void menu()
{
    Data siswa[MAX];
    int option;

    printf("MENU METODE SORTING\n1. Insertion Sort\n2. Selection Sort\n3. Keluar\nPilihan anda [1/2/3]: ");
    scanf("%d", &option);
    fflush(stdin);

    selectOrder();
    inputSiswa(siswa);
    printBaseArray(siswa);

    switch(option) {
        case 1:
            sortInsertion(siswa);
            break;
        case 2:
            sortSelection(siswa);
            break;
        case 3:
            puts("Keluar");
            exit(0);
        default:
            puts("Invalid");
            exit(0);
    }
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
        scanf("%c", &A[i].nilai);
        fflush(stdin);
    }
}

void selectOrder()
{
    printf("Pengurutan yang dipilih: \n1.Ascending\n2. Descending\nPilihan anda [1/2]: ");
    scanf("%d", &orderBy);
}

void printBaseArray(Data A[])
{
    printf("Array sebelum sorting\nNO\tNAMA\tNILAI\n");
    for(int i = 0; i < MAX; i++){
        printf("%d\t%s\t%c\n", A[i].no, A[i].nama, A[i].nilai);
    }
    printf("\n");
}

void sortInsertion(Data A[])
{
    int i, j, key;

    for( i = 1; i < MAX; i++ ) {
        key = A[i].no;
        j = i - 1;
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
    }

    printf("Array setelah insertion sort = \nNO\tNAMA\tNILAI\n");
    for(int i = 0; i < MAX; i++){
        printf("%d\t%s\t%c\n", A[i].no, A[i].nama, A[i].nilai);
    }
    printf("\n");
}

void sortSelection(Data A[])
{
    int peak_index;

    for( int i = 0; i < MAX-1; i++ ) {
        for( int j = i+1; j <= MAX-1; j++ ) {
            if(orderBy == 1) {
                if(A[j].no < A[i].no) {
                    peak_index = j;
                    swapElement(&A[peak_index], &A[i]);
                };
            } else if(orderBy == 2) {
                if(A[j].no > A[i].no) {
                    peak_index = j;
                    swapElement(&A[peak_index], &A[i]);
                };
            } else {
                puts("Order invalid");
                exit(0);
            }
        }
    }

    printf("Array setelah selection sort = \nNO\tNAMA\tNILAI\n");
    for(int i = 0; i < MAX; i++){
        printf("%d\t%s\t%c\n", A[i].no, A[i].nama, A[i].nilai);
    }
    printf("\n");
}

void swapElement(Data *a, Data *b)
{
    Data temp;

    temp = *a;
    *a = *b;
    *b = temp;
}