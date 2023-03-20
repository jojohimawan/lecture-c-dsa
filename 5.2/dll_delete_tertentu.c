//
// Created by jordan on 3/20/2023.
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
void insert_begin();
void insert_end();
void delete_begin();
void delete_key();
void output();

int main() {
    menu();
    return 0;
}

void menu() {
    char jawab;

    do {
        fflush(stdin);
        allocation();
        insert_end();
        fflush(stdin);
        printf("Input lagi? ");
        scanf("%c", &jawab);
    } while ((jawab == 'y') || (jawab == 'Y'));

    printf("No\tNama\t\tNilai\n");
    output();

    fflush(stdin);
    printf("Hapus node tertentu?");
    scanf("%c", &jawab);
    fflush(stdin);

    while((jawab == 'y') || (jawab == 'Y')) {
        printf("\nDelete node tertentu\n");
        delete_key();
        output();
        printf("Hapus node tertentu?");
        scanf("%c", &jawab);
        fflush(stdin);
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
        fflush(stdin);
        printf("Nilai: ");
        scanf("%f", &p->nilai);
        fflush(stdin);
        p->next = NULL; p->prev = NULL;
    }
}

void insert_begin() {
    if(head == NULL) {
        head = p;
    } else {
        p->next = head;
        head->prev = p;
        head = p;
    }
}

void insert_end() {
    Dnode *tail;

    if(head == NULL) {
        insert_begin();
    } else {
        tail = head;

        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = p;
        p->prev = tail;
        tail = p;
    }
}

void delete_begin() {
    Dnode *erase;

    if(head == NULL) {
        puts("DLL Kosong");
        exit(0);
    }
    if(head->next == NULL) {
        free(head);
        head = NULL;
        output();
    } else {
        erase = head;
        head = erase->next;
        erase->next->prev = NULL;
        free(erase);
        erase = NULL;
    }
}

void delete_end() {
    Dnode *erase;

    if(head == NULL) {
        puts("DLL Kosong");
        exit(0);
    } else {
        if(head->next == NULL) {
            delete_begin();
        } else {
            erase = head;

            while(erase->next != NULL) {
                erase = erase->next;
            }
            erase->prev->next = NULL;
            free(erase);
            erase = NULL;
        }
    }
}

void delete_key() {
    Dnode *erase; int key;
    printf("Input key: "); scanf("%d", &key);

    if(head == NULL) {
        puts("DLL Kosong");
        exit(0);
    } else {
        if(head->no == key) {
            delete_begin();
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
                delete_end();
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
            printf("%d\t%s\t\t%.2f\n", read->no, read->nama, read->nilai);
            read = read->next;
        }
    }
}