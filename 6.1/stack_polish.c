//
// Created by jordan on 3/29/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

typedef char itemType;
typedef struct {
    itemType data[MAX];
    int count;
}stack;

void stackInit(stack *);
void infixToPostfix(itemType *);
int degree(char);
int isFull(stack *);
int isEmpty(stack *);
void stackPush(itemType, stack *);
itemType stackPop(stack *);


int main() {
    itemType infix[MAX], flag;

    puts("MENGUBAH NOTASI INFIX MENJADI POSTFIX");

    do {
        printf("Masukkan infix: ");
        scanf("%s", &infix);
        infixToPostfix(&infix);
        fflush(stdin);
        printf("Lagi? (y/t) ");
        scanf("%c", &flag);
        fflush(stdin);
    } while(flag == 'y' || flag == 'Y');

    return 0;
}

void infixToPostfix(itemType *inf) {
    int len = strlen(inf), i;
    itemType p;

    stack tumpukan;
    stackInit(&tumpukan);

    for(i = 0; i < len; i++) {
        if(isalnum(inf[i])) {
            printf("%c ", inf[i]);
        } else if(inf[i] == '(') {
            stackPush(inf[i], &tumpukan);
        } else if(inf[i] == ')') {
            do {
                p = stackPop(&tumpukan);
                if(p != '(') {
                    printf("%c ", p);
                }
            } while(tumpukan.data[tumpukan.count-1] != '(');
            stackPop(&tumpukan);
        } else {
            if(isEmpty(&tumpukan) || (degree(inf[i]) > degree(tumpukan.data[tumpukan.count-1]))) {
                stackPush(inf[i], &tumpukan);
            } else {
                do {
                    p = stackPop(&tumpukan);
                    printf("%c ", p);
                } while (degree(inf[i]) < degree(tumpukan.data[tumpukan.count-1]));
                stackPush(inf[i], &tumpukan);
            }
        }
    }

    while(!isEmpty(&tumpukan)) {
        p = stackPop(&tumpukan);
        printf("%c ", p);
    }
    printf("\n\n");
}

int degree(char opr) {
    switch(opr) {
        case '+':
        case'-':
            return 1;
        case '*':
        case '/' :
            return 2;
        case '^' :
            return 3;
        default:
            return 0;
    }
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
        puts("Stack Full");
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