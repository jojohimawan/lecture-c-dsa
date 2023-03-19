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
void insert_akhir();
void del_akhir();
void baca();

int main(int argc, char const *argv[])
{
    char jawab;

    do {
        fflush(stdin);
        alokasi();
        insert_akhir();
        fflush(stdin);
        printf("Input lagi? ");
        scanf("%c", &jawab);
    } while ((jawab == 'y') || (jawab == 'Y'));

    printf("No\tNama\t\tNilai\n");
    baca();
    
    fflush(stdin);
    printf("Hapus node akhir?");
    scanf("%c", &jawab);
    fflush(stdin);

    while((jawab == 'y') || (jawab == 'Y')) {
        printf("\nDelete akhir\n");
        printf("No\tNama\t\tNilai\n");
        del_akhir();
        baca();
        printf("Hapus node akhir?");
        scanf("%c", &jawab);
        fflush(stdin);
    }
    return 0;
}

void alokasi() {
    p = (Node *) malloc(sizeof(Node));
    if(p == NULL) {
        printf("Gagal\n");
        exit(0);
    } else {
        printf("Nomor: ");
        scanf("%d", &p->no);
        fflush(stdin);
        printf("Nama: ");
        scanf(" %[^\n]%*c", &p->nama);
        fflush(stdin);
        printf("Nilai: ");
        scanf("%f", &p->nilai);
        fflush(stdin);
        p->next = NULL;
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

void del_akhir() {
    Node *delete, *prevDelete;
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
}

void baca() {
    Node *baca; baca = head;
    while(baca != NULL)
    {
        printf("%d\t%s\t\t%.2f\n", baca->no, baca->nama, baca->nilai);
        baca = baca->next;
    }
    printf("\n");
}