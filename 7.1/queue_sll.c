//
// Created by jordan on 4/11/2023.
//
#include <stdio.h>
#include <stdlib.h>

typedef char itemType;
typedef struct queue antrian;
struct queue {
    antrian *next;
    itemType item;
} ;
antrian *head = NULL, *q;

void menu();
void enqueue(itemType);
itemType dequeue();
void fifo();

int main()
{
    menu();
    return 0;
}

void menu()
{
    char flag = 0; int option = 0; itemType data;

    do {
        puts("Menu Queue Using SLL");
        printf("1. Mengisi Queue (ENQUEUE)\n2. Ambil Isi Queue (DEQUEUE)\n3. Tampilkan Isi Queue (FIFO)\n4. keluar\n");
        printf("Masukkan pilihan = ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                fflush(stdin);
                printf("Masukkan data: ");
                scanf("%c", &data);
                enqueue(data);
                break;
            case 2:
                printf("Item yang anda ambil = %c\n", dequeue());
                break;
            case 3:
                fifo();
                break;
            case 4:
                exit(0);
                break;
            default:
                puts("Opsi Invalid");
                break;
        }
    } while(!flag);
}


void enqueue(itemType x)
{
    q = (antrian *) malloc(sizeof(antrian));
    antrian *tail;
    if(q == NULL) {
        puts("Gagal Inisialisasi Queue");
        exit(0);
    } else {
        q->item = x;
        q->next = NULL;
    }

    if(head == NULL) {
        head = q;
    } else {
        tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = q;
        tail = q;
    }
}

itemType dequeue()
{
    itemType tmp;
    antrian *delete;
    if(head == NULL) {
        puts("Queue Kosong");
        return(' ');
    } else {
        if(head->next == NULL) {
            tmp = head->item;
            free(head);
            head = NULL;
            return tmp;
        } else {
            tmp = head->item;
            delete = head;
            head = head->next;
            free(delete);
            delete = NULL;
            return tmp;
        }
    }
}

void fifo()
{
    antrian *read; read = head;
    printf("Isi Queue Saat Ini Adalah:\n");
    while(read != NULL) {
        printf("%c\n", read->item);
        read = read->next;
    }
    printf("\n");
}