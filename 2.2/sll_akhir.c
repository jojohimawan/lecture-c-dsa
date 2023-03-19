#include <stdio.h>
#include <stdlib.h>

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

void akhir()
{
    Node *tail;
    
    if(head == NULL) {
        // jika head kosong, jadikan node baru sebagai head
        head = p;
    } else {
        // assign tail dengan head
        tail = head;

        // looping pada setiap node
        while(tail->next != NULL) {
            /* jika next pada node yg ditunjuk tail not NULL, maka geser
            tail hingga ketemu NULL */
            tail = tail->next;
        }
        // assign next pada node terakhir dengan node baru
        tail->next = p;
        
        // assign tail dengan node terbaru yg telah disambungkan (line 72)
        tail = p;
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