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
void del_tertentu();
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
    printf("Hapus node tertentu?");
    scanf("%c", &jawab);
    fflush(stdin);

    while((jawab == 'y') || (jawab == 'Y')) {
        printf("\nDelete tertentu\n");
        printf("No\tNama\t\tNilai\n");
        del_tertentu();
        baca();
        printf("Hapus node tertentu?");
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

void del_tertentu()
{
    Node *delete, *prevDelete;
    int key;
    printf("Input key: "); scanf("%d", &key);
    if(head == NULL) {
        printf("SLL kosong\n");
    }

    if(head->no == key) {
        free(head);
        head = NULL;
    } else {
        delete = head;
        while(delete->no != key) {
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
        printf("%d\t%s\t\t%.2f\n", baca->no, baca->nama, baca->nilai);
        baca = baca->next;
    }
    printf("\n");
    
}