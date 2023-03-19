#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};

Node *head = NULL, *p;

void alokasi();
void awal();
void output();

int main(int argc, char const *argv[])
{
    char jawab;

    do {
        fflush(stdin);
        alokasi();
        awal();
        fflush(stdin);
        printf("Input lagi? ");
        scanf("%c", &jawab);
    } while ((jawab == 'y') || (jawab == 'Y'));

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

void awal()
{
    // jika head tidak kosong
    if(head != NULL) {
        // assign next dengan node sebelumnya
        p->next = head;
    }

    // head menunjuk pada node baru yang telah disambungkan (line 57)
    head = p;
}

void output()
{
    Node *baca;
    baca = head;

    printf("\nIsi dari SLL\n");
    while(baca != NULL) {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}