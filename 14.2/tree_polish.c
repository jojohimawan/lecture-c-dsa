//
// Created by jordan on 3/29/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

typedef char itemType;
typedef struct tree Leaf;

struct tree {
    itemType data;
    Leaf *left, *right;
};
Leaf *root, *new, *temp, *left, *right;

// stack of tree
typedef struct {
    Leaf *data[MAX];
    int count;
}stack;

void stackInit(stack *, stack *);
void infixToPostfix(itemType *);
int isFull(stack *);
int isEmpty(stack *);
void stackPush(stack *);
Leaf *stackPop(stack *);
void bentuk(itemType);
void preorder(Leaf *);
void inorder(Leaf *);
void postorder(Leaf *);


int main() {
    itemType expression[MAX];
    printf("Masukkan notasi infix: ");
    scanf("%s", &expression);

    infixToPostfix(&expression);

    printf("\nHasil penelusuran Preorder: ");
    preorder(root);

    printf("\nHasil penelusuran Inorder: ");
    inorder(root);

    printf("\nHasil penelusuran Postorder: ");
    postorder(root);

    return 0;
}

void infixToPostfix(itemType *inf) {
    int len = strlen(inf), i;

    stack operator, operand;
    stackInit(&operator, &operand);

    for(i = 0; i < len; i++) {
        if(inf[i] == '(') { // jika kurung buka
            bentuk(inf[i]); stackPush(&operator);
        } else if(isalnum(inf[i])){ // jika operand
            bentuk(inf[i]); stackPush(&operand);
        }else if(!isalnum(inf[i]) && inf[i] != '(' && inf[i] != ')') { // jika operator
            bentuk(inf[i]); stackPush(&operator);
        } else if(inf[i] == ')') { // jika kurung tutup
            temp = stackPop(&operator); // pop operator
            right = stackPop(&operand); // pop operand untuk sisip left
            left = stackPop(&operand); // pop operator untuk sisip right

            if(temp->data != '(') {
                temp->left = left; // bentuk node sisip kiri
                temp->right = right; // bentuk node sisip kanan

                operand.data[operand.count] = temp;
                operand.count++;
            }

            stackPop(&operator); // buang (
        }
    }

    while(!isEmpty(&operator)) { // akhir notasi infix
        temp = stackPop(&operator);
        right = stackPop(&operand);
        left = stackPop(&operand);

        temp->left = left;
        temp->right = right;

        operand.data[operand.count] = temp;
        operand.count++;
    }

    root = temp;
}

void stackInit(stack *opr, stack *opd) {
    opr->count = 0;
    opd->count = 0;
}

int isFull(stack *s) {
    return s->count == MAX ? 1 : 0;
}

int isEmpty(stack *s) {
    return s->count == 0 ? 1 : 0;
}

void stackPush(stack *s) {
    if(isFull(s)) {
        puts("Stack Full");
    } else {
        s->data[s->count] = new; // push new leaf kedalam stack
        s->count++;
    }
}

Leaf *stackPop(stack *s) {
    if(isEmpty(s)) {
        puts("Stack Kosong");
    } else {
        --s->count;
        return s->data[s->count]; // return sebuah leaf (pointer)
    }
}

void bentuk(itemType n)
{
    // prepare new leaf
    new = (Leaf *) malloc(sizeof(Leaf));

    // check for leaf
    if(new == NULL) {
        puts("Gagal");
        exit(0);
    } else {
        new->data = n;
        new->left = NULL;
        new->right = NULL;
    }
}

void preorder(Leaf *akar)
{
    if(akar != NULL) {
        printf("%c ", akar->data);
        preorder(akar->left);
        preorder(akar->right);
    }
}

void inorder(Leaf *akar)
{
    if(akar != NULL) {
        inorder(akar->left);
        printf("%c ", akar->data);
        inorder(akar->right);
    }
}

void postorder(Leaf *akar)
{
    if(akar != NULL) {
        postorder(akar->left);
        postorder(akar->right);
        printf("%c ", akar->data);
    }
}