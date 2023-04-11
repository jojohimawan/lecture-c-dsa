//
// Created by jordan on 3/30/2023.
//
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef char itemType;
typedef struct {
    itemType data[MAX];
    int count;
}stack;

void menu();
void stackInit(stack *);
int isEmpty(stack *);
int isFull(stack *);
void stackPush(itemType *, stack *);
itemType stackPop(stack *);
void checkPalindrom(stack *, itemType *);

int main() {
    menu();
    return 0;
}

void menu() {
    stack tumpukan;
    itemType palindrom[MAX], flag;

    stackInit(&tumpukan);
    puts("MENGECEK PALINDROM");

    do {
        printf("Masukkan kata: ");
        scanf(" %[^\n]%*c", &palindrom);
        stackPush(&palindrom, &tumpukan);
        fflush(stdin);
        printf("%c", stackPop(&tumpukan));
        checkPalindrom(&tumpukan, &palindrom);
        while(!isEmpty(&tumpukan)) {
            stackPop(&tumpukan);
        }
        printf("Lagi? (y/t) ");
        scanf("%c", &flag);
        fflush(stdin);
    } while(flag == 'y' || flag == 'Y');
}

void stackInit(stack *s) {
    s->count = 0;
}

int isEmpty(stack *s) {
    return s->count == 0 ? 1 : 0;
}

int isFull(stack *s) {
    return s->count == MAX ? 1 : 0;
}

void stackPush(itemType *p, stack *s) {
    if(isFull(s)) {
        puts("Stack Penuh");
    } else {
        for(int i = 0; i <= strlen(p); i++) {
            s->data[s->count] = p[i];
            s->count++;
        }

    }
}

itemType stackPop(stack *s) {
    if(isEmpty(s)) {
        puts("Stack Kosong");
    } else {
        itemType x;
        --s->count;
        x = s->data[s->count];
        return(x);
    }
}

void checkPalindrom(stack *s, itemType *p) {
    int stackLen = s->count, j = stackLen-1, isPalindrom = 1;
//    for(int i = 0; i <= stackLen-1; i++) {
//        if(s->data[i] != s->data[j]) {
//            isPalindrom = 0;
//            break;
//        } else {
//            isPalindrom = 1;
//            j--;
//        }
//    }
    for(int i = 0; i <= j;) {
        if(s->data[i] != stackPop(s)) {
            isPalindrom = 0;
            break;
        } else {
            i++;
        }
    }

    if(isPalindrom) {
        printf("%s adalah PALINDROM\n", s);
    } else {
        printf("%s BUKAN palindrom\n", s);
    }
}