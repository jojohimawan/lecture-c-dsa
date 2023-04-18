//
// Created by jordan on 4/11/2023.
//
#include <stdio.h>
#define MAX 5

typedef char itemType;
typedef struct {
    int count;
    int front;
    int rear;
    itemType item[MAX];
} queue;

void menu();
void initQueue(queue *);
int isFull(queue *);
int isEmpty(queue *);
void enqueue(queue *, itemType);
itemType dequeue(queue *);
void fifo(queue *);

int main()
{
    menu();
    return 0;
}

void menu()
{
    char flag = 0; int option = 0; itemType data;
    queue antrian;
    initQueue(&antrian);

    do {
        puts("Menu Queue Using ARRAY");
        printf("1. Mengisi Queue (ENQUEUE)\n2. Ambil Isi Queue (DEQUEUE)\n3. Tampilkan Isi Queue (FIFO)\n4. Keluar\n");
        printf("Masukkan pilihan = ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                fflush(stdin);
                printf("Masukkan data: ");
                scanf("%c", &data);
                enqueue(&antrian, data);
                break;
            case 2:
                printf("%c\n", dequeue(&antrian));
                break;
            case 3:
                fifo(&antrian);
                break;
            case 4:
                flag = 1;
                break;
            default:
                puts("Opsi Invalid");
                break;
        }
    } while(!flag);
}

void initQueue(queue *q)
{
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

int isFull(queue *q)
{
    return q->count == MAX ? 1 : 0;
}

int isEmpty(queue *q)
{
    return q->count == 0 ? 1 : 0;
}

void enqueue(queue *q, itemType x)
{
    if(isFull(q)) {
        puts("Queue Penuh");
    } else {
        q->item[q->rear] = x;
        q->rear = (q->rear + 1) % MAX;
        q->count++;
    }
}

itemType dequeue(queue *q)
{
    itemType tmp;
    if(isEmpty(q)) {
        puts("Queue Kosong");
        return(' ');
    } else {
        tmp = q->item[q->front];
        q->front = (q->front + 1) % MAX;
        q->count--;
        return(tmp);
    }
}

void fifo(queue *q)
{
    if(isEmpty(q)) {
        puts("Queue Kosong");
    } else {
        int temp = q->front;
        puts("Isi Queue Saat Ini Adalah: ");
        for(int i = 0; i < q->count ; i++) {
            printf("%c\n", q->item[temp]);
            temp = (temp + 1) % MAX;
        }
    }
}