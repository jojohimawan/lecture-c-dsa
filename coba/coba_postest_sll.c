//
// Created by jordan on 3/14/2023.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};
Node *head = NULL, *p;

void menu();
void alokasi();
void baca();
void ascending();
void searching();
void insert_awal();
void insert_akhir();
void insert_after(int);
void insert_before(int);
void delete_awal();
void delete_akhir();
void delete_tertentu();
void __TEST__();

int main() {
    menu();

    return 0;
}

void __TEST__() {
    char jawab;

    do {
        fflush(stdin);
        alokasi();
//        insert_awal();
        insert_akhir();
        fflush(stdin);
        printf("Input lagi? ");
        scanf("%c", &jawab);
    } while ((jawab == 'y') || (jawab == 'Y'));

    baca();

//    alokasi();
//    insert_after();
//    insert_before();
//    delete_awal();
//    delete_akhir();
    delete_tertentu();

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
                alokasi();
                ascending();
                break;
            case 2:
                searching();
                break;
            case 3:
                delete_tertentu();
                break;
            case 4:
                flag = 1;
                break;
            default:
                puts("Invalid");
                exit(0);
        }
        baca();
    }
}

void alokasi() {
    p = (Node *) malloc(sizeof(Node));
    if(p == NULL) {
        puts("Gagal alokasi");
        exit(0);
    } else {
        printf("Masukkan data: ");
        scanf("%d", &p->data);
        p->next = NULL;
    }
}

void ascending() {
    Node *ptr;

    if(head == NULL || p->data < head->data) {
        insert_awal();
    } else {
        ptr = head;
        while(ptr->next != NULL && ptr->next->data < p->data) {
            ptr = ptr->next;
        }
        p->next = ptr->next;
        ptr->next = p;
    }
}

void searching() {
    Node *search;
    int count = 0, key;
    printf("Data yg dicari: ");
    scanf("%d", &key);

    if(head == NULL) {
        puts("SLL Kosong");
    } else {
        search = head;
        while(search->next != NULL) {
            if(search->data == key) {
                count++;
            }
            search = search->next;
        }

        if(count != 0) {
            printf("Data %d ditemukan sebanyak %d\n", key, count);
        } else {
            printf("Data %d tidak ada\n", key);
        }
    }
}

void insert_awal() {
    if(head != NULL) {
        p->next = head;
    }
    head = p;
}

void insert_akhir() {
    Node *tail;
    if(head == NULL) {
        head = p;
    } else {
        tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = p;
        tail = head;
    }
}

void insert_after(int data) {
    Node *after; int key = data;
//    printf("key = %d", key);

    if(head == NULL) {
        puts("SLL Kosong");
        exit(0);
    } else {
            puts("TEST2");
            after = head;
            while(after->data != key) {
                puts("TEST3");
                if(after->next == NULL) {
                    printf("%d tidak ada\n", key);
                    exit(0);
                } else {
                    after = after->next;
                }
            }
            p->next = after->next;
            after->next = p;
    }
}

void insert_before(int data) {
    Node *prevBefore, *before; int key;
    key = data;
    printf("key = %d\n", key);

    if(head == NULL) {
        puts("SLL Kosong");
        exit(0);
    } else {
        if(head->data == key) {
            insert_awal();
        } else {
            before = head;
            while(before->data != key) {
                if(before->next == NULL) {
                    printf("%d tidak ada", key);
                    exit(0);
                } else {
                    prevBefore = before;
                    before = before->next;
                }
            }
            prevBefore->next = p;
            p->next = before;
        }
    }
}

void delete_awal() {
    Node *delete;

    if(head == NULL) {
        puts("SLL Kosong");
        exit(0);
    } else {
        delete = head;
        head = head->next;
        free(delete);
        delete = NULL;
        baca();
    }
}

void delete_akhir() {
    Node *prevDelete, *delete;

    if(head == NULL) {
        puts("SLL Kosong");
        exit(0);
    } else {
        delete = head;
        while(delete->next != NULL) {
            prevDelete = delete;
            delete = delete->next;
        }
        prevDelete->next = NULL;
        free(delete);
        delete = NULL;
        baca();
    }
}

void delete_tertentu() {
    int flag=1;
    Node *prevDelete, *delete; int key;
    printf("Masukkan key: ");
    scanf("%d", &key);
    fflush(stdin);

    if(head == NULL) {
        puts("SLL Kosong");
        exit(0);
    } else {
        if(head->data == key) {
            delete_awal();
        } else {
            delete = head;
            while(delete->data != key) {
                if(delete->next == NULL) {
                    printf("%d tidak ada", key);
                    flag=0;
                    break;
                } else {
                    prevDelete = delete;
                    delete = delete->next;
                }
            }
        }
        if(flag){
            prevDelete->next = delete->next;
            free(delete);
            delete = NULL;
        }


    }
}

void baca() {
    Node *baca;
    baca = head;

    if(baca == NULL) {
        puts("SLL Kosong");
        exit(0);
    } else {
        while(baca != NULL) {
            printf("%d ", baca->data);
            baca = baca->next;
        }
        printf("\n\n");
    }
}