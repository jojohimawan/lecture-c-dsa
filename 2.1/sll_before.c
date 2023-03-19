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
void before();
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
    before();
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
    
    // jika head kosong
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

void before()
{
    Node *before, *prevBefore;
    int key;

    // get user input
    printf("Disisipkan sebelum? ");
    scanf("%d", &key);
    
    // jika head kosong
    if(head == NULL) {
        // insert tidak bisa dilakukan
        printf("Gagal\n");
        exit(0);
    } else {
        // assign before dengan head
        before = head;
        if((before->data == key)) { // jika node awal langsung cocok dengan key
            // assign node awal kedalam node baru->next (sambungkan node)
            p->next = before;
            // jadikan node baru yg telah disambung sebagai head
            head = p;
        } else {
            while(before->data != key) { // looping mencari node->data == key
                if(before->next == NULL) {
                    // jika tidak ditemukan data cocok, gagal
                    printf("Key tidak ada\n");
                    exit(0);
                } else {
                    // assign bef kedalam pbef
                    prevBefore = before;
                    // geser bef
                    before = before->next; 
                }
            }
            // sambungkan node baru kepada node yang ditunjuk bef
            p->next = before;
            // sambungkan node yg ditunjuk pbef kepada node baru
            prevBefore->next = p;
        }
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