#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};

Node *head = NULL, *p;

void alokasi();
void akhir();
void after();
void output();

int main(int argc, char const *argv[])
{
    char jawab;

    do {
        fflush(stdin);
        alokasi();
        akhir();
        fflush(stdin);
        printf("Input lagi? ");
        scanf("%c", &jawab);
    } while ((jawab == 'y') || (jawab == 'Y'));

    output();

    alokasi();
    after();
    output();

    return 0;
}

void alokasi()
{
    // get user input
    int num;
    printf("Input angka: ");
    scanf("%d", &num);

    // alloc and assign
    p = (Node *) malloc(sizeof(Node));
    if(p == NULL) {
        printf("Gagal\n");
        exit(0);
    } else {
        p->data = num;
        p->next = NULL;
    }

    
}

void akhir()
{
    Node *tail;
    
    if(head == NULL) {
        head = p;
    } else {
        tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = p;
        tail = p;
    }

}

void after()
{
    Node *after;
    int key;

    printf("Disisipkan setelah? ");
    scanf("%d", &key);
    
    if(head == NULL) {
        // jika head kosong, jadikan node baru sebagai head
        head = p;
    } else {
        // assign after dengan head
        after = head;

        // looping pada setiap head dan cek pada field data
        while(after->data != key) {
            if(after->next == NULL) {
                // jika field data tidak ada yang cocok dengan key, maka gagal
                printf("Key tidak ada\n");
            } else {
                // geser after jika next not NULL
                after = after->next; 
            }
        }

        // jika field after->data = key, assign next pada node baru dengan after next
        p->next = after->next;

        // assign p pada node dengan field yang = key
        after->next = p;
    }
}

void output()
{
    Node *baca;
    baca = head;

    printf("Isi dari SLL\n");
    while(baca != NULL) {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}