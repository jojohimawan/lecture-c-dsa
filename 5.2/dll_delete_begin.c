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
    printf("Hapus node awal?");
    scanf("%c", &jawab);
    fflush(stdin);

    while((jawab == 'y') || (jawab == 'Y')) {
        printf("\nDelete awal\n");
        delete_begin();
        output();
        printf("Hapus node awal?");
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