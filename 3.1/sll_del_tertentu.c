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
void del_tertentu();
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
    del_tertentu();


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

void del_tertentu()
{
    Node *delete, *prevDelete;
    int key;
    printf("\nDelete akhir\n");
    printf("Input key: "); scanf("%d", &key);
    if(head == NULL) {
        printf("SLL kosong\n");
    }

    if(head->data == key) {
        free(head);
        head = NULL;
    } else {
        delete = head;
        while(delete->data != key) {
            if(delete->next == NULL) {
                printf("key %d tidak ada\n", key);
                exit(0);
            } else {
                prevDelete = delete;
                delete = delete->next;
            }
        }
        prevDelete->next = delete->next;
        free(delete);
        delete = NULL;
    }
    baca();

    printf("SLL telah dihapus\n");
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