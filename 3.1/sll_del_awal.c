#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};

Node *head = NULL, *p;

void alokasi();
void insert_akhir();
void del_akhir();
void baca();

int main(int argc, char const *argv[])
{
    char flag; printf("SLL Insert Akhir\n");
    do {
        alokasi(); insert_akhir();
        fflush(stdin);
        printf("lagi? ");
        scanf("%c", &flag);
        fflush(stdin);
    } while((flag == 'y') || (flag == 'Y'));
    printf("Isi dari SLL\n");
    baca();
    del_awal();


    return 0;
}

void alokasi() {
    p = (Node *) malloc(sizeof(Node));
    if(p != NULL) {
        printf("Data yang mau diinput: "); scanf("%d", &p->data); p->next = NULL;
    } else {
        printf("Gagal alloc\n"); exit(0);
    }
}

void insert_akhir() {
    Node *tail;
    if(head == NULL) {
        head = p;
    } else {
        tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = p; tail=p;
    }
}

void del_awal()
{
    Node *delete;
    printf("\nDelete awal\n");
    if(head == NULL) {
        printf("SLL kosong\n");
    }

    while(head != NULL) {
        if(head->next == NULL) {
            free(head);
            head = NULL;
            baca();
        } else {
            delete = head;
            head = head->next;
            free(delete);
            delete = head;
            baca();
        }
    }
    printf("SLL kosong\n");
}

void baca()
{
    Node *baca; baca = head;
    while(baca != NULL)
    {
        printf("%d ", baca->data);
        baca = baca->next;
    }
    printf("\n");
    
}