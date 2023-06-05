//
// Created by jordan on 6/5/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char itemType;
typedef struct pohon Tree;
struct pohon
{
    Tree *left;
    itemType data;
    Tree *right;
};

typedef struct {
    Tree **items;
    int top;
} Stack;

void initializeStack(Stack *stack, int capacity);
void push(Stack *stack, Tree *item);
Tree *pop(Stack *stack);
Tree *top(Stack *stack);
int isEmpty(Stack *stack);
int isOperator(itemType item);
int getOperatorPriority(itemType operator);
Tree *createNode(itemType data);
Tree *buildExpressionTree(const char *expression);
void preorder(Tree *root);
void inorder(Tree *root);
void postorder(Tree *root);

int main() {
    char expression[100];
    printf("Masukkan ekspresi aritmatika dalam notasi infix: ");
    scanf("%[^\n]", expression);

    Tree *root = buildExpressionTree(expression);

    printf("\nHasil penelusuran menggunakan Preorder: ");
    preorder(root);

    printf("\nHasil penelusuran menggunakan Inorder: ");
    inorder(root);

    printf("\nHasil penelusuran menggunakan Postorder: ");
    postorder(root);

    puts("");

    return 0;
}

void initializeStack(Stack *stack, int capacity) {
    stack->items = (Tree **)malloc(capacity * sizeof(Tree *));
    stack->top = -1;
}

void push(Stack *stack, Tree *item) {
    stack->top++;
    stack->items[stack->top] = item;
}

Tree *pop(Stack *stack) {
    Tree *item = stack->items[stack->top];
    stack->top--;
    return item;
}

Tree *top(Stack *stack) {
    return stack->items[stack->top];
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isOperator(itemType item) {
    return item == '+' || item == '-' || item == '*' || item == '/';
}

int getOperatorPriority(itemType operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    else
        return 0;
}

Tree *createNode(itemType data) {
    Tree *node = (Tree *)malloc(sizeof(Tree));
    if (node == NULL) {
        printf("Alokasi memori gagal");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Tree *buildExpressionTree(const char *expression) {
    Stack stOperator;
    initializeStack(&stOperator, strlen(expression));
    Stack stOperand;
    initializeStack(&stOperand, strlen(expression));

    int length = strlen(expression);
    int i;

    for (i = 0; i < length; i++) {
        itemType current = expression[i];

        if (current == '(') {
            push(&stOperator, createNode(current));
        } else if (isdigit(current)) {
            push(&stOperand, createNode(current));
        } else if (isOperator(current)) {
            while (!isEmpty(&stOperator) && isOperator(top(&stOperator)->data) && getOperatorPriority(top(&stOperator)->data) >= getOperatorPriority(current)) {
                Tree *operator = pop(&stOperator);
                Tree *rightOperand = pop(&stOperand);
                Tree *leftOperand = pop(&stOperand);

                operator->left = leftOperand;
                operator->right = rightOperand;

                push(&stOperand, operator);
            }
            push(&stOperator, createNode(current));
        } else if (current == ')') {
            while (!isEmpty(&stOperator) && top(&stOperator)->data != '(') {
                Tree *operator = pop(&stOperator);
                Tree *rightOperand = pop(&stOperand);
                Tree *leftOperand = pop(&stOperand);

                operator->left = leftOperand;
                operator->right = rightOperand;

                push(&stOperand, operator);
            }

            if (!isEmpty(&stOperator) && top(&stOperator)->data == '(') {
                pop(&stOperator); // Discard '('
            }
        }
    }

    while (!isEmpty(&stOperator)) {
        Tree *operator = pop(&stOperator);
        Tree *rightOperand = pop(&stOperand);
        Tree *leftOperand = pop(&stOperand);

        operator->left = leftOperand;
        operator->right = rightOperand;

        push(&stOperand, operator);
    }

    Tree *root = pop(&stOperand);

    return root;
}

void preorder(Tree *root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Tree *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void postorder(Tree *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}
