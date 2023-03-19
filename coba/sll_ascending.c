//
// Created by jordan on 3/15/2023.
//
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertNode(struct Node **headRef, int newData) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL || newData < (*headRef)->data) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        struct Node *currentNode = *headRef;
        while (currentNode->next != NULL && currentNode->next->data < newData) {
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    insertNode(&head, 8);
    insertNode(&head, 8);
    insertNode(&head, 8);
    insertNode(&head, 9);
    insertNode(&head, 1);
    printf("Ascending order singly linked list: ");
    printList(head);
    return 0;
}