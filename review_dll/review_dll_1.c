//
// Created by jordan on 3/24/2023.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul {
    int data;
    Dnode *prev, *next;
};
Dnode *head = NULL; Dnode *p;

void menu();
void allocation();
void insert_ascending();
void searching();
void delete();
void output();

int main() {
    menu();
    return 0;
}

void menu() {
    int flag = 0, option;

    while(!flag) {
        printf("MENU UTAMA\n1. Penambahan terurut\n2. Pencarian data\n3. Penghapusan data\n4. Keluar\n");
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
        printf("Input data: ");
        scanf("%d", &p->data);
        p->prev = NULL;
        p->next = NULL;
    }
}

void insert_ascending() {
    Dnode *ptr;

    if(head == NULL || p->data < head->data) {
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
        while(ptr->next != NULL && p->data > ptr->next->data) {
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
            if(search->data == key) {
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
        if(head->data == key) {
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
            while(erase->data != key) {
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

void output() {
    Dnode *read;

    if(head == NULL) {
        puts("DLL Kosong");
        exit(0);
    } else {
        read = head;
        puts("Isi DLL");
        while(read != NULL) {
            printf("%d ", read->data);
            read = read->next;
        }
        printf("\n");
    }
}