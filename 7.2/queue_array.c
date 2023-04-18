//
// Created by jordan on 4/13/2023.
//
//
// Created by jordan on 4/11/2023.
//
#include <stdio.h>
#define MAX 5

typedef int itemType;
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
void minmax(queue *);
void findItem(queue *, itemType);

int main()
{
    menu();
    return 0;
}

void menu()
{
    char flag = 0; int option = 0; itemType data; int key;
    queue antrian;
    initQueue(&antrian);

    do {
        puts("Menu Queue Using ARRAY");
        printf("1. Tambah Data\n2. Hapus Data\n3. Tampilkan Min & Max\n4. Cari Data\n5. Cetak Isi Queue\n6. Keluar\n");
        printf("Masukkan pilihan = ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                fflush(stdin);
                printf("Masukkan data: ");
                scanf("%d", &data);
                enqueue(&antrian, data);
                break;
            case 2:
                printf("%d\n", dequeue(&antrian));
                break;
            case 3:
                minmax(&antrian);
                break;
            case 4:
                fflush(stdin);
                printf("Masukkan data yang dicari: ");
                scanf("%d", &key);
                findItem(&antrian, key);
                break;
            case 5:
                fifo(&antrian);
                break;
            case 6:
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
        return 0;
    } else {
        tmp = q->item[q->front];
        q->front = (q->front + 1) % MAX;
        q->count--;
        return(tmp);
    }
}

void minmax(queue *q)
{
    int temp = q->front;
    itemType min = q->item[temp]; itemType max = 0;
    puts("Isi Queue Saat Ini Adalah: ");
    for(int i = 0; i < q->count ; i++) {
        if(min > q->item[temp]) {
            min = q->item[temp];
        }
        if(max < q->item[temp]) {
            max = q->item[temp];
        }
        temp = (temp + 1) % MAX;
    }

    printf("Data Terkecil = %d\n", min);
    printf("Data Terbesar = %d\n", max);
}

void findItem(queue *q, itemType x)
{
    int count = 0;
    int temp = q->front;
    for(int i = 0; i < q->count; i++){
        if (q->item[temp] == x) {
            count++;
        }
        temp = (temp + 1) % MAX;
    }

    if(count == 0) {
        printf("Data %d tidak ada dalam queue\n", x);
    } else {
        printf("Data %d berjumlah sebanyak %d\n", x, count);
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