//
// Created by jordan on 3/30/2023.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int itemType;
typedef struct {
    itemType data[MAX];
    int count;
} stack;

void menu();
void stackInit(stack *);
int isEmpty(stack *);
int isFull(stack *);
void stackPush(itemType, stack *);
itemType stackPop(stack *);
void converter(itemType, itemType, stack *);

int main() {
    menu();
    return 0;
}

void menu() {
    stack tumpukan;
    itemType decimal, option, flag = 0;

    puts("KONVERSI BILANGAN DESIMAL");
    printf("Masukkan desimal: ");
    scanf("%d", &decimal);

    stackInit(&tumpukan);
    while(!flag) {
        printf("1. BINARY\n2. OCTAL\n3. HEXADECIMAL\n4. Keluar\n");
        printf("Masukkan pilihan anda: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                converter(decimal, option, &tumpukan);
                printf("Konversi %d ke BINARY adalah = ", decimal);
                break;
            case 2:
                converter(decimal, option, &tumpukan);
                printf("Konversi %d ke OCTAL adalah = ", decimal);
                break;
            case 3:
                converter(decimal, option, &tumpukan);
                printf("Konversi %d ke HEXADECIMAL adalah = ", decimal);
                break;
            case 4:
                flag = 1;
                break;
            default:
                puts("Invalid");
        }

        while(!isEmpty(&tumpukan)) {
            printf("%d", stackPop(&tumpukan));
        }
        printf("\n");
    }
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

void stackPush(itemType x, stack *s) {
    if(isFull(s)) {
        puts("Stack Penuh");
    } else {
        s->data[s->count] = x;
        s->count++;
    }
}

itemType stackPop(stack *s) {
    itemType x;

    if(isEmpty(s)) {
        puts("Stack Kosong");
        return(' ');
    } else {
            --s->count;
            x = s->data[s->count];
            return(x);
    }
}

void converter(itemType dec, itemType conv, stack *s) {
    int divider;

    switch(conv) {
        case 1:
            divider = 2;
            break;
        case 2:
            divider = 8;
            break;
        case 3:
            divider = 16;
            break;
        default:
            puts("Invalid");
            exit(0);
    }

    while(dec != 0) {
        stackPush(dec % divider, s);
        dec /= divider;
    }
}
