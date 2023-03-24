//
// Created by jordan on 3/23/2023.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef char itemType;
typedef struct {
    itemType data[MAX];
    int count;
}stack;

void stackInit(stack *);
int isEmpty(stack *);
int isFull(stack *);
void stackPush(itemType, stack *);
itemType stackPop(stack *);

int main() {
    stack dummyStack;
    char answer; itemType x;

    puts("Stack application using array");
    stackInit(&dummyStack);
    puts("Mengisi stack");
    do{
        fflush(stdin);
        printf("Masukkan data: ");
        scanf("%c", &x);
        stackPush(x, &dummyStack);
        fflush(stdin);
        printf("Lagi?");
        scanf("%c", &answer);
    } while((answer == 'y') || (answer == 'Y'));
    puts(" ");
    while(!isEmpty(&dummyStack)) {
        printf("%c\n", stackPop(&dummyStack));
    }

    return 0;
}

void stackInit(stack *s) {
    s->count = 0;
}

int isEmpty(stack *s) {
    if(s->count == 0) {
        return(1);
    } else {
        return(0);
    }
}

int isFull(stack *s) {
    if(s->count == MAX) {
        return(1);
    } else {
        return(0);
    }
}

void stackPush(itemType x, stack *s) {
    if(isFull(s)) {
        puts("Stack penuh");
    } else {
        s->data[s->count] = x;
        s->count++;
    }
}

itemType stackPop(stack *s) {
    itemType x;

    if(isEmpty(s)) {
        puts("Stack kosong");
        return(' ');
    } else {
        --s->count;
        x = s->data[s->count];
        return(x);
    }
}