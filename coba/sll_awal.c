#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};

int main(int argc, char const *argv[])
{
    Node *head = NULL, *p;

    // awal
    p = (Node *) malloc(sizeof(Node));
    if(p == NULL) {
        printf("Gagal alloc\n");
        exit(0);
    } else {
        p->data = 1;
        p->next = NULL;
    }

    if(head == NULL) {
        head = p;
    }

    // insert
    p = (Node *) malloc(sizeof(Node));
    if(p == NULL) {
        printf("Gagal alloc\n");
        exit(0);
    } else {
        p->data = 2;
        p->next = NULL;
    }

    if(head != NULL) {
        p->next = head;
    }
    head = p;

    // insert
    p = (Node *) malloc(sizeof(Node));
    if(p == NULL) {
        printf("Gagal alloc\n");
        exit(0);
    } else {
        p->data = 3;
        p->next = NULL;
    }

    if(head != NULL) {
        p->next = head;
    }
    head = p;

    // cetak
    Node *baca;
    baca = head;
    while(baca != NULL) {
        printf("%d\n", baca->data);
        baca = baca->next;
    }

    return 0;
}
