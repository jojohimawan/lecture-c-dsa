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
void insert_end();
void insert_after();
void insert_before();
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
        insert_end();
        fflush(stdin);
        printf("Input lagi? ");
        scanf("%c", &answer);
    } while ((answer == 'y') || (answer == 'Y'));

    output();
    allocation();
    insert_before();
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

void insert_before() {
    Dnode *before; int key;

    if(head == NULL) {
        puts("DLL Kosong");
        exit(0);
    } else {
        printf("Masukkan key: ");
        scanf("%d", &key);

        before = head;
        if(before->data == key) {
            insert_begin();
        } else {
            while(before->data != key) {
                if(before->next == NULL) {
                    puts("Key tidak ada");
                    exit(0);
                } else {
                    before = before->next;
                }
            }

            if(before->next == NULL) {
                insert_end();
            } else {
                p->prev = before->prev;
                p->next = before;
                before->prev->next = p;
                before->prev = p;
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