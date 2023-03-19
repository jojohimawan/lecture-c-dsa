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
    del_akhir();


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

void del_akhir()
{
    Node *delete, *prevDelete;
    printf("\nDelete akhir\n");
    if(head == NULL) {
        // jika sll kosong, tidak bisa
        printf("SLL kosong\n");
        exit(0);
    }

    while(head != NULL) { // selama SLL belum kosong
        if(head->next == NULL) { // jika hanya ada satu node
            free(head);
            head = NULL;
        } else {
            // assign head kedalam node
            delete = head;
            while(delete->next != NULL) { // selama delete belum mencapai node akhir
                // assign delete kedalam pdelete
                prevDelete = delete;
                // geser delete
                delete = delete->next;
            }
            // jadikan node yg ditunjuk pdelete sbg node akhir
            prevDelete->next = NULL;
            // bebaskan
            free(delete);
            delete = NULL;
        }
        baca();
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