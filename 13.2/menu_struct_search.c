//
// Created by jordan on 5/18/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int MAX, orderBy, sortBy;
typedef struct murid {
    int no;
    char nama[10];
    int nilai;
} mhs;

void menu();
void functionSearch(int, int, int, mhs [], mhs []);
void inputSiswa(mhs []);
void sortShell(mhs []);
void swapElement(mhs *, mhs *);
void printArray(mhs []);
void sequenceSearchNo(mhs [], int);
void binarySearchNo(mhs [], int);
void sequenceSearchNama(mhs [], char []);
void binarySearchNama(mhs [], char []);

int main()
{
    printf("Berapa jumlah data? <MAKS 30>: ");
    scanf("%d", &MAX);
    fflush(stdin);

    if(MAX > 30) {puts("Melebihi jumlah maksimal data"); exit(0);}
    menu();

    return 0;
}

void menu()
{
    mhs mhs_arr[MAX], mhs_sorted[MAX];
    int optionMenu, optionSort, optionSearch, flag = 0;

    inputSiswa(mhs_arr);

    memcpy(mhs_sorted, mhs_arr, sizeof(mhs_arr));
    sortShell(mhs_sorted);

    do {
        printf("MENU SEARCHING\n1. Tampilkan Data\n2. Sequential Search\n3. Binary Search\n4. Keluar\n");
        printf("Pilihan anda [1/2/3/4]: ");
        scanf("%d", &optionMenu);
        fflush(stdin);

        if(optionMenu == 1) {
            printf("BENTUK DATA\n1. Tidak terurut\n2. Terurut berdasarkan no\n");
            printf("Pilihan anda [1/2]: ");
            scanf("%d", &optionSort);
            fflush(stdin);

            if(optionSort == 1) { printArray(mhs_arr); } else if(optionSort == 2) { printArray(mhs_sorted); }
            else { puts("Invalid"); exit(0); }

        } else if(optionMenu == 2 || optionMenu == 3) {
            printf("PENCARIAN BERDASARKAN\n1. No\n2. Nama\n");
            printf("Pilihan anda [1/2]: ");
            scanf("%d", &optionSearch);
            fflush(stdin);

            functionSearch(optionSort, optionSearch, optionMenu, mhs_arr, mhs_sorted);
        } else {
            puts("Keluar/Invalid");
            exit(0);
        }




    } while(!flag);
}

void inputSiswa(mhs A[])
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

void functionSearch(int dataOpt, int searchOpt, int optionMenu, mhs mhs_arr[MAX], mhs mhs_sorted[MAX])
{
    char keyNama[10]; int keyNo;

    if(searchOpt == 1) {
        printf("Key nomor: ");
        scanf("%d", &keyNo);
    } else if(searchOpt == 2) {
        printf("Key nama: ");
        scanf("%[^\n]%*c", &keyNama);
    }

    if(dataOpt == 1) {
        if(optionMenu == 2) {
            if(searchOpt == 1) {
                // sequential no (mhs_arr, keyNo)
                sequenceSearchNo(mhs_arr, keyNo);
            } else if(searchOpt == 2) {
                // sequential nama (mhr_arr)
                sequenceSearchNama(mhs_arr, keyNama);
            }
        } else if(optionMenu == 3) {
            if(searchOpt == 1) {
                // binary no (mhs_arr)
                binarySearchNo(mhs_arr, keyNo);
            } else if(searchOpt == 2) {
                // binary nama (mhs_arr)
                binarySearchNama(mhs_arr, mhs_arr);
            }
        } else {
            puts("Invalid"); exit(0);
        }
    } else if (dataOpt == 2) {
        if(optionMenu == 2) {
            if(searchOpt == 1) {
                // sequential no (mhs_backup)
                sequenceSearchNo(mhs_sorted, keyNo);
            } else if(searchOpt == 2) {
                // sequential nama (mhr_backup)
                sequenceSearchNama(mhs_sorted, keyNama);
            }
        } else if(optionMenu == 3) {
            if(searchOpt == 1) {
                // binary no (mhs_backup)
                binarySearchNo(mhs_sorted, keyNo);
            } else if(searchOpt == 2) {
                // binary nama (mhs_backup)
                binarySearchNama(mhs_sorted, keyNama);
            }
        } else {
            puts("Invalid"); exit(0);
        }
    }
}

void sortShell(mhs A[])
{
    int jarak = MAX, didSwap;

    while( jarak > 1) {
        jarak /= 2;
        didSwap = 1;
        while( didSwap ) {
            didSwap = 0;
            for( int i = 0; i < MAX - jarak; i++ ) {
                if(A[i].no > A[i + jarak].no) {
                    swapElement(&A[i], &A[i + jarak]);
                    didSwap = 1;
                }
            }
        }
    }
}

void printArray(mhs A[])
{
    printf("NO\tNAMA\tNILAI\n");
    for(int i = 0; i < MAX; i++){
        printf("%d\t%s\t%d\n", A[i].no, A[i].nama, A[i].nilai);
    }
    printf("\n");
}

void swapElement(mhs *a, mhs *b)
{
    mhs temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sequenceSearchNo(mhs A[], int key)
{
    int i  = 0, idx = 0, found = 0;

    while (i < MAX) {
        if (A[i].no == key) {
            idx = i;
            found = 1;
            break;
        } else {
            i++;
        }
    }

    if(!found) {
        printf("Key %d tidak ada\n", key);
    } else {
        printf("Key %d ditemukan pada index-%d\n", key, idx);
    }
}

void binarySearchNo(mhs A[], int key)
{
    int l = 0, r = MAX - 1, found = 0, idx = 0;

    while(!found && l <= r) {
        int mid = (l + r) / 2;
        if(key == A[mid].no) {
            found++;
            idx = mid;
        } else if(key < A[mid].no) {
            r = mid - 1;
        } else if(key > A[mid].no) {
            l = mid + 1;
        }
    }

    if(!found) {
        printf("Key %d tidak ada\n", key);
    } else {
        printf("Key %d pada index-%d\n", key, idx);
    }
}

void sequenceSearchNama(mhs A[], char key[10])
{
    int i  = 0, idx = 0, found = 0;

    while (i < MAX) {
        if (strcmp(A[i].nama, key) == 0) {
            idx = i;
            found = 1;
            break;
        } else {
            i++;
        }
    }

    if(!found) {
        printf("Key %s tidak ada\n", key);
    } else {
        printf("Key %s ditemukan pada index-%d\n", key, idx);
    }
}

void binarySearchNama(mhs A[], char key[10])
{
    int l = 0, r = MAX - 1, found = 0, idx = 0;

    while(!found && l <= r) {
        int mid = (l + r) / 2;
        if(strcmp(A[mid].nama, key) == 0) {
            found++;
            idx = mid;
        } else if(strcmp(A[mid].nama, key) > 0) {
            r = mid - 1;
        } else if(strcmp(A[mid].nama, key) < 0) {
            l = mid + 1;
        }
    }

    if(!found) {
        printf("Key %s tidak ada\n", key);
    } else {
        printf("Key %s pada index-%d\n", key, idx);
    }
}