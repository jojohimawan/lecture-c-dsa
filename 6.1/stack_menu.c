//
// Created by jordan on 3/29/2023.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int itemType;
typedef struct {
    itemType data[MAX];
    int count;
} stack;

void menu();
void stackInit(stack *);
int isFull(stack *);
int isEmpty(stack *);
void stackPush(itemType, stack *);
itemType stackPop(stack *);
void stackPrint(stack *);

int main() {
    menu();
    return 0;
}

void menu() {
    stack dummyStack; itemType x;
    int option, flag = 0;
    stackInit(&dummyStack);

    do{
        puts("Menu STACK Using ARRAY");
        printf("1. Mengisi Stack (PUSH)\n2. Mengambil Isi Stack (POP)\n3. Menampilkan Isi Stack (LIFO)\n4. Exit\n\n");
        printf("Masukkan pilihan anda: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Masukkan data: ");
                scanf("%d", &x);
                stackPush(x, &dummyStack);
                break;
            case 2:
                printf("Item yang diambil = %d\n", stackPop(&dummyStack));
                break;
            case 3:
                stackPrint(&dummyStack);
                break;
            case 4:
                flag = 1;
                break;
            default:
                puts("Invalid");
                exit(0);
        }
    }while(!flag);
}

void stackInit(stack *s) {
    s->count = 0;
}

int isFull(stack *s) {
    return s->count == MAX ? 1 : 0;
}

int isEmpty(stack *s) {
    return s->count == 0 ? 1 : 0;
}

void stackPush(itemType x, stack *s) {
    if(isFull(s)) {
        puts("Stack Penuh");
    } else {
        s->data[s->count] = x;
        s->count++;
    }
}

itemType stackPop(stack *s) {
    itemType tmp;

    if(isEmpty(s)) {
        puts("Stack Kosong");
    } else {
        --s->count;
        tmp = s->data[s->count];
        return(tmp);
    }
}

void stackPrint(stack *s) {
    if(isEmpty(s)) {
        puts("Stack Kosong");
    } else {
        printf("Isi stack adalah:\n");
        for(int i = s->count-1; i >= 0; i--) {
            printf("%d\n", s->data[i]);
        }
    }
}