//
// Created by jordan on 3/20/2023.
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
void delete_begin();
void delete_end();
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
    printf("Hapus node akhir?");
    scanf("%c", &jawab);
    fflush(stdin);

    while((jawab == 'y') || (jawab == 'Y')) {
        printf("\nDelete akhir\n");
        delete_end();
        output();
        printf("Hapus node khir?");
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

void delete_begin() {
    Dnode *erase;

    if(head == NULL) {
        puts("DLL Kosong");
        exit(0);
    } else {
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
