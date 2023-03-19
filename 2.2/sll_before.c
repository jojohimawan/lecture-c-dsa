#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct siswa Node;
struct siswa {
    int no;
    char nama[30];
    float nilai;
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
    int no; char nama[30]; float nilai;
    printf("Nomor: ");
    scanf("%d", &no);
    fflush(stdin);
    printf("Nama: ");
    scanf(" %[^\n]%*c", &nama);
    fflush(stdin);
    printf("Nilai: ");
    scanf("%f", &nilai);

    // alloc and assign
    p = (Node *) malloc(sizeof(Node));
    if(p == NULL) {
        printf("Gagal\n");
        exit(0);
    } else {
        p->no = no;
        strcpy(p->nama, nama);
        p->nilai = nilai;
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

void before()
{
    Node *before, *prevBefore;
    int key;

    printf("Disisipkan sebelum nomor? ");
    scanf("%d", &key);
    
    if(head == NULL) {
        printf("Gagal\n");
        exit(0);
    } else {
        before = head;
        if(before->no == key) {
            p->next = before;
            head = p;
        } else {
            while(before->no != key) {
                if(before->next == NULL) {
                    printf("Key tidak ada\n");
                } else {
                prevBefore = before;
                before = before->next; 
                }
            } 
            p->next = before;
            prevBefore->next = p;
        }
        

    }
}

void output()
{
    Node *baca;
    baca = head;

    while(baca != NULL) {
        printf("%d\t%s\t\t%.2f\n", baca->no, baca->nama, baca->nilai);
        baca = baca->next;
    }
}