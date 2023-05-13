//
// Created by jordan on 5/5/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 5

int orderBy, sortBy, c, m, s;
typedef struct murid {
    int no;
    char nama[20];
    int nilai;
} Data;

void selectSortBy();
void selectOrder();
void printArray(Data []);
void sortBubble(Data []);
void swapElement(Data *, Data *);
void forceLowerCase(Data []);

int main()
{
    Data students[MAX] = {5,"Seulgi",77,3,"Irene",90,10,"Yerim",60,2,"Joy",63,7,"Wendy",89};

    selectSortBy();

    selectOrder();

    forceLowerCase(students);

    printArray(students);

    sortBubble( students );

    printArray( students );

    printf("Movement = %d Compare = %d Swap = %d\n", m, c, s);
}


void selectSortBy()
{
    printf("Sorting berdasarkan: \n1.No\n2. Nama\n3.Nilai\n[1/2/3]: ");
    scanf("%d", &sortBy);
}

void selectOrder()
{
    printf("Pengurutan yang dipilih: \n1.Ascending\n2. Descending\nPilihan anda [1/2]: ");
    scanf("%d", &orderBy);
}

void printArray(Data A[])
{
    printf("Array sebelum sorting\nNO\tNAMA\tNILAI\n");
    for(int i = 0; i < MAX; i++){
        printf("%d\t%s\t%d\n", A[i].no, A[i].nama, A[i].nilai);
    }
    printf("\n");
}

void sortBubble(Data A[])
{
    int indexAkhir = MAX - 2, didSwap = 1;

    if( orderBy < 1 || orderBy > 2 ) { puts("Pengurutan invalid"); exit(0); }

    while( didSwap) {
        didSwap = 0;
        for(int i = 0; i <= indexAkhir; i++) {
            if( sortBy == 1 ) {
                c++;
                int compare = (orderBy == 1) ? (A[i].no > A[i + 1].no) : (A[i].no < A[i + 1].no);
                if(compare) {
                    swapElement(&A[i], &A[i + 1]);
                    s++;
                    m += 3;
                    didSwap = 1;
                }
            } else if( sortBy == 2 ) {
                c++;
                int compare = (orderBy == 1) ? strcmp(A[i].nama, A[i + 1].nama) > 0 : strcmp(A[i].nama, A[i + 1].nama) < 0;
                if(compare) {
                    swapElement(&A[i], &A[i + 1]);
                    s++;
                    m += 3;
                    didSwap = 1;
                }
            } else if( sortBy == 3 ) {
                c++;
                int compare = (orderBy == 1) ? (A[i].nilai > A[i + 1].nilai) : (A[i].nilai < A[i + 1].nilai);
                if(compare) {
                    swapElement(&A[i], &A[i + 1]);
                    s++;
                    m += 3;
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

void forceLowerCase(Data A[])
{
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; A[i].nama[j] != '\0'; j++) {
            A[i].nama[j] = tolower(A[i].nama[j]);
        }
    }
}