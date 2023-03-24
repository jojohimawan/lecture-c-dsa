//
// Created by jordan on 3/24/2023.
//
//
// Created by jordan on 3/24/2023.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul {
    int no;
    char nama[30];
    float nilai;
    Dnode *prev, *next;
};
Dnode *head = NULL; Dnode *p;

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
    p = (Dnode *) malloc(sizeof(Dnode));

    if(p == NULL) {
        puts("Gagal alokasi");
        exit(0);
    } else {
        printf("Nomor: ");
        scanf("%d", &p->no);
        fflush(stdin);
        printf("Nama: ");
        scanf(" %[^\n]%*c", &p->nama);
        printf("Nilai: ");
        scanf("%f", &p->nilai);
        fflush(stdin);
        p->next = NULL; p->prev = NULL;
    }
}

void insert_ascending() {
    Dnode *ptr;

    if(head == NULL || p->no< head->no) {
        // insert awal
        if(head == NULL) {
            head = p;
        } else {
            p->next = head;
            head->prev = p;
            head = p;
        }
    } else {
        ptr = head;
        while(ptr->next != NULL && p->no > ptr->next->no) {
            ptr = ptr->next;
        }

        if(ptr->next == NULL) {
            ptr->next = p;
            p->prev = ptr;
            ptr = p;
        } else {
            p->next = ptr->next;
            p->prev = ptr;
            ptr->next->prev = p;
            ptr->next = p;
        }

    }
}

void searching() {
    Dnode *search;
    int count = 0, key;

    printf("Masukkan key pencarian: ");
    scanf("%d", &key);

    if(head == NULL) {
        puts("DLL Kosong");
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

void delete() {
    Dnode *erase; int key;
    printf("Masukkan key delete: "); scanf("%d", &key);

    if(head == NULL) {
        puts("DLL Kosong");
        exit(0);
    } else {
        if(head->no == key) {
            if(head->next == NULL) {
                free(head);
                head = NULL;
            } else {
                erase = head;
                head = erase->next;
                erase->next->prev = NULL;
                free(erase);
                erase = NULL;
            }
        } else {
            erase = head;
            while(erase->no != key) {
                if(erase->next == NULL) {
                    puts("Key tidak ada");
                    exit(0);
                } else {
                    erase = erase->next;
                }
            }

            if(erase->next == NULL) {
                erase->prev->next = NULL;
                free(erase);
                erase = NULL;
            } else {
                erase->prev->next = erase->next;
                erase->next->prev = erase->prev;
                free(erase);
                erase = NULL;
            }
        }
    }
}

void average() {
    Dnode *avg;
    int count = 0, sum = 0, avgs = 0;

    if(head == NULL) {
        puts("DLL Kosong");
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

void output() {
    Dnode *baca;

    if(head == NULL) {
        puts("DLL Kosong");
        exit(0);
    } else {
        baca = head;
        puts("Data SLL\nNo\tNama\t\tNilai\n");
        while(baca != NULL) {
            printf("%d\t%s\t\t%.1f\n\n", baca->no, baca->nama, baca->nilai);
            baca =  baca->next;
        }
    }
}