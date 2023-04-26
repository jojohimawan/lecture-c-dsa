//
// Created by jordan on 4/16/2023.
//
#include <stdio.h>
#include <stdlib.h>

typedef char itemType;
typedef struct queue antrian;
struct queue {
    antrian *next;
    itemType item;
    int prio;
} ;
antrian *head = NULL, *q;

void menu();
void enqueue(itemType, int);
itemType dequeue();
void fifo();

int main()
{
    menu();
    return 0;
}

void menu()
{
    char flag = 0; int option = 0, prioritas; itemType data;

    do {
        puts("Menu Priority Queue Using SLL");
        printf("1. Mengisi Queue\n2. Ambil Isi Queue\n3. Tampilkan Isi Queue\n4. keluar\n");
        printf("Masukkan pilihan = ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                fflush(stdin);
                printf("Masukkan data: ");
                scanf("%c", &data);
                fflush(stdin);
                printf("Nilai prioritas: ");
                scanf("%d", &prioritas);
                fflush(stdin);
                enqueue(data, prioritas);
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


void enqueue(itemType x, int p)
{
    antrian *ptr;
    q = (antrian *) malloc(sizeof(antrian));

    if(q == NULL) {
        puts("Gagal Inisialisasi Queue");
        exit(0);
    } else {
        q->item = x;
        q->prio = p;
        q->next = NULL;
    }


    if(head == NULL || q->prio < head->prio) { // jika head kosong atau prioritas baru < prioritas head
        // insert awal
        if(head != NULL) {
            q->next = head;
        }
        head = q;
    } else {
        ptr = head;
        while(ptr->next != NULL && q->prio > ptr->next->prio) {
            // geser ptr jika bukan node akhir dan prioritas baru > prioritas node setelah ptr
            ptr = ptr->next;
        }

        // insert after
        q->next = ptr->next;
        ptr->next = q;
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
    printf("Data\t\tPrioritas\n");
    while(read != NULL) {
        printf("%c\t\t%d\n", read->item, read->prio);
        read = read->next;
    }
    printf("\n");
}