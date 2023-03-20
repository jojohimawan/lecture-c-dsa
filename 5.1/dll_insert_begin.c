//
// Created by jordan on 3/19/2023.
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
void insert_begin();
void output();

int main() {
    menu();
    return 0;
}

void menu() {
    char answer;

    do {
        fflush(stdin);
        allocation();
        insert_begin();
        fflush(stdin);
        printf("Input lagi? ");
        scanf("%c", &answer);
    } while ((answer == 'y') || (answer == 'Y'));

    output();
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

void insert_begin() {
    if(head == NULL) {
        head = p;
    } else {
        p->next = head;
        head->prev = p;
        head = p;
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
    }
}