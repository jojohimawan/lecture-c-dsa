//
// Created by jordan on 6/7/2023.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// prepare queue and stack
typedef struct queue Queue;
typedef struct stack Stack;

struct queue {
    int dataQueue[MAX];
    int count, front, rear;
}; Queue q;

struct stack {
    int dataStack[MAX];
    int count;
}; Stack s;

// queue functions
void queueInit();
int queueIsFull();
int queueIsEmpty();
void enqueue(int);
int dequeue();
int queueSearch(int);

// stack functions
void stackInit();
int stackIsFull();
int stackIsEmpty();
void stackPush(int);
int stackPop();

// graph functions
void inputGraph();
void inputTQR();
void dijkstra();
void cetakRute();

// matrix and variables
/*
 * Q = matrix beban
 * TQ = matrix beban total minimal
 * R = matrix rute
 */
int R[MAX], TQ[MAX],Q[MAX][MAX], n, asal, tujuan;


int main()
{
    int jawab = 1;
    queueInit();
    stackInit();

    inputGraph();

    do {
        printf("Posisi awal: ");
        scanf("%d", &asal);
        printf("Posisi tujuan: ");
        scanf("%d", &tujuan);

        inputTQR(asal, tujuan);
        dijkstra();
        cetakRute();

        printf("lagi? [1/0]");
        scanf("%d", &jawab);
    } while(jawab);


    return 0;
}

void inputGraph()
{
    printf("Masukkan jumlah node: ");
    scanf("%d", &n);
    fflush(stdin);

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Masukkan nilai Q[%d][%d]: ", i, j);
            scanf("%d", &Q[i][j]);

            if(Q[i][j] == 0) {
                Q[i][j] = MAX;
            }

            fflush(stdin);
        }
    }
}

void inputTQR()
{
    // input TQ
    for(int i = 0; i < n; i++) {
        if(i == asal-1) { // asal -1 karena menurut index
            TQ[i] = 0;
        } else {
            TQ[i] = MAX;
        }
    }

    // input R
    for(int i = 0; i < n; i++) {
        R[i] = -1;
    }
}

void dijkstra()
{
    int cn;
    // asal dan tujuan -1 karena menurut index
    asal -= 1;
    tujuan -= 1;

    // algo 6
    enqueue(asal);

    //algo 7
    while(!queueIsEmpty()) {
        // algo 8
        cn = dequeue();

        // algo 9 - 10
        for(int i = 0; i < n; i++) {
            // algo 11
            if(Q[cn][i] != MAX) {
                //algo 12
                if(Q[cn][i] + TQ[cn] < TQ[i]) {
                    // algo 13
                    TQ[i] = Q[cn][i] + TQ[cn];
                    // algo 14
                    R[i] = cn;
                    // algo 15
                    if(i != asal && i != tujuan && queueSearch(i)) {
                        enqueue(i);
                    }
                }
            }
        }

    }
}

void cetakRute()
{
    for(int i = tujuan; i > asal; i--) {
        if(R[i] != 0) {
            stackPush(R[i]);
        } else {
            break;
        }
    }

    printf("Rute tersingkat : %d - ", asal + 1);
    while(!stackIsEmpty()) {
        printf("%d ", stackPop() + 1);
        if(!stackIsEmpty()) {
            printf("- ");
        }
    }
    printf("- %d\n", tujuan + 1);
    printf("\nTotal beban = %d\n\n", TQ[tujuan]);

    printf("Matriks TQ\n");
    for (int i = 0; i < n; i++) {
        if(TQ[i] == MAX) {
            printf("M ");
        } else {
            printf("%d ", TQ[i]);
        }
    }
    printf("\n\n");

    printf("Matriks R\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", R[i]);
    }
    printf("\n\n");
}

void queueInit()
{
    q.count = 0;
    q.front = 0;
    q.rear = 0;
}

int queueIsFull()
{
    return q.count == MAX ? 1 : 0;
}

int queueIsEmpty()
{
    return q.count == 0 ? 1 : 0;
}

void enqueue(int x)
{
    if(queueIsFull()) {
        puts("Queue Penuh");
    } else {
        q.dataQueue[q.rear] = x;
        q.rear = (q.rear + 1) % MAX;
        q.count++;
    }
}

int dequeue()
{
    int tmp;
    if(queueIsEmpty()) {
        puts("Queue Kosong");
        return(' ');
    } else {
        tmp = q.dataQueue[q.front];
        q.front = (q.front + 1) % MAX;
        q.count--;
        return tmp;
    }
}

int queueSearch(int key)
{
    int index = q.front;

    do {
        if(q.dataQueue[index] == key) {
            return 0;
        }
        index = (index + 1) % MAX;
    } while(index != q.rear);

    return 1;
}

void stackInit() {
    s.count = 0;
}

int stackIsFull() {
    return s.count == MAX ? 1 : 0;
}

int stackIsEmpty() {
    return s.count == 0 ? 1 : 0;
}

void stackPush(int x) {
    if(stackIsFull()) {
        puts("Stack Penuh");
    } else {
        s.dataStack[s.count] = x;
        s.count++;
    }
}

int stackPop() {
    int tmp;

    if(stackIsEmpty()) {
        puts("Stack Kosong");
    } else {
        --s.count;
        tmp = s.dataStack[s.count];
        return tmp;
    }
}