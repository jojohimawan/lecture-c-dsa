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
void awal();
void akhir();
void after();
void before();
void del_awal();
void del_akhir();
void del_tertentu();
void baca();

int main(int argc, char const *argv[])
{
    int flag = 0, option; char menu;

    while(!flag) {
        printf("Menu\n1. Insert\n2. Delete\n3. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &option);
        fflush(stdin);

        switch(option) {
            case 1:
                alokasi();
                printf("Menu INSERT\na.Awal\nb.Akhir\nc.Sebelum\nd.Sesudah\n");
                printf("Pilihan: ");
                scanf("%c", &menu); fflush(stdin);
                if(menu == 'a') {
                    awal();
                } else if(menu == 'b') {
                    akhir();
                } else if(menu == 'c') {
                    after();
                } else if(menu == 'd') {
                    before();
                } else {
                    printf("Tidak Valid\n");
                }
                baca();
                break;
            case 2:
                printf("Menu DELETE\na.Awal\nb.Akhir\nc.Tertentu\n");
                printf("Pilihan: ");
                scanf("%c", &menu); fflush(stdin);
                if(menu == 'a') {
                    del_awal();
                } else if(menu == 'b') {
                    del_akhir();
                } else if(menu == 'c') {
                    del_tertentu();
                } else {
                    printf("Tidak Valid\n");
                }
                break;
            case 3:
                flag = 1;
                break;
            default: printf("Tidak valid\n"); flag = 1; break;
        }
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

void after()
{
    Node *after;
    int key;
    
    if(head == NULL) {
        // jika head kosong, cetak
        printf("SLL kosong\n");
    } else {
        alokasi();
        printf("Disisipkan setelah? ");
        scanf("%d", &key);
        // assign after dengan head
        after = head;

        // looping pada setiap head dan cek pada field no
        while(after->no != key) {
            if(after->next == NULL) {
                // jika field no tidak ada yang cocok dengan key, maka gagal
                printf("Key tidak ada\n");
            } else {
                // geser after jika next not NULL
                after = after->next; 
            }
        }

        // jika field after->no = key, assign next pada node baru dengan after next
        p->next = after->next;

        // assign p pada node dengan field yang = key
        after->next = p;
    }
}

void before()
{
    Node *before, *prevBefore;
    int key;
    
    if(head == NULL) {
        printf("SLL kosong\n");
    } else {
        alokasi();
        printf("Disisipkan sebelum? ");
        scanf("%d", &key);
        before = head;
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

void del_awal()
{
    Node *delete;
    printf("\nDelete awal\n");
    if(head == NULL) {
        printf("SLL kosong\n");
    }

    while(head != NULL) {
        if(head->next == NULL) {
            free(head);
            head = NULL;
            baca();
        } else {
            delete = head;
            head = head->next;
            free(delete);
            delete = head;
            baca();
        }
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