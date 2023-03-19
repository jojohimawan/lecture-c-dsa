//
// Created by jordan on 3/16/2023.
//
//
// Created by jordan on 3/16/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct siswa Node;
struct siswa {
    int no, nilai;
    char nama[30];
    Node *next;
};

Node *head = NULL, *p;

void menu();
void allocation();
void insert_ascending();
void searching();
void average();
void delete();
void output();

int main() {
    menu();
    return 0;
}

void menu() {
    int flag = 0, option;

    while(!flag) {
        printf("MENU UTAMA\n1. Penambahan terurut\n2. Pencarian data\n3. Penghapusan data\n4. Rata-rata\n5. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &option);
        fflush(stdin);

        switch(option) {
            case 1:
                allocation();
                insert_ascending();
                break;
            case 2:
                searching();
                break;
            case 3:
                delete();
                break;
            case 4:
                average();
                break;
            case 5:
                flag = 1;
                break;
            default:
                puts("Invalid");
                exit(0);
        }
        output();
    }
}

void allocation() {
    p = (Node *) malloc(sizeof(Node));

    if(p == NULL) {
        puts("Gagal");
        exit(0);
    } else {
        printf("No: ");
        scanf("%d", &p->no);
        printf("Nama: ");
        scanf(" %[^\n]%*c", &p->nama);
        printf("Nilai: ");
        scanf("%d", &p->nilai);
        p->next = NULL;
    }
}

void insert_ascending() {
    Node *ptr;

    if(head == NULL || p->no < head->no) { // jika head kosong atau data baru < data head
        // insert awal
        if(head != NULL) {
            p->next = head;
        }
        head = p;
    } else {
        ptr = head;
        while(ptr->next != NULL && p->no > ptr->next->no) {
            // geser ptr jika bukan node akhir dan data baru > data node setelah ptr
            ptr = ptr->next;
        }
        // insert after
        p->next = ptr->next;
        ptr->next = p;
    }
}

void searching() {
    Node *search;
    int count = 0, key;

    printf("Masukkan key pencarian: ");
    scanf("%d", &key);

    if(head == NULL) {
        puts("SLL Kosong");
    } else {
        search = head;
        while(search != NULL) {
            if(search->no == key) {
                count++;
            }
            search = search->next;
        }
        if(count != 0) {
            printf("Key %d ada sebanyak %d\n", key, count);
        } else {
            puts("Key tidak ditemukan");
        }
    }
}

void average() {
    Node *avg;
    int count = 0, sum = 0, avgs = 0;

    if(head == NULL) {
        puts("SLL Kosong");
        exit(0);
    } else {
        avg = head;
        while(avg != NULL) {
            count++;
            sum += avg->nilai;
            avg = avg->next;
        }
        avgs = sum / count;
        printf("Rata-rata nilai = %d\n", avgs);
    }
}

void delete() {
    Node *prevDelete, *delete; int key, flag = 0;

    printf("Masukkan key delete: ");
    scanf("%d", &key);

    if(head == NULL) {
        puts("SLL Kosong");
        exit(0);
    } else {
        if(head->no == key) {
            // delete awal
            delete = head;
            head = head->next;
            free(delete);
            delete = NULL;
        } else {
            // delete tertentu
            delete = head;
            while(delete->no != key) {
                if(delete->next == NULL) {
                    puts("Key tidak ditemukan");
                    flag = 1;
                    break;
                } else {
                    prevDelete = delete;
                    delete = delete->next;
                }
            }
            if(!flag) {
                prevDelete->next = delete->next;
                free(delete);
                delete = NULL;
            }
        }
    }
}

void output() {
    Node *baca;

    if(head == NULL) {
        puts("SLL Kosong");
        exit(0);
    } else {
        baca = head;
        puts("Data SLL\nNo\tNama\t\tNilai\n");
        while(baca != NULL) {
            printf("%d\t%s\t\t%d\n\n", baca->no, baca->nama, baca->nilai);
            baca =  baca->next;
        }
    }
}