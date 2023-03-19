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

    printf("No\tNama\t\tNilai\n");
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

    while(baca != NULL) {
        printf("%d\t%s\t\t%.2f\n", baca->no, baca->nama, baca->nilai);
        baca = baca->next;
    }
}