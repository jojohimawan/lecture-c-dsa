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
void output();

int main(int argc, char const *argv[])
{
    int flag = 0, option;

    while(!flag) {
        printf("Menu Insert\n1. Awal\n2. Akhir\n3. After\n4. Before\n5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &option);
        fflush(stdin);

        switch(option) {
            case 5: flag = 1; break;
            case 1:
                alokasi();
                awal();
                output();
                break;
            case 2:
                alokasi();
                akhir();
                output();
                break;
            case 3:
                after();
                output();
                break;
            case 4:
                before();
                output();
                break;
            default: printf("Tidak valid\n"); flag = 1; break;
        }
    }
    
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

        // looping pada setiap head dan cek pada field data
        while(after->no != key) {
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

void output()
{
    Node *baca;
    baca = head;
                                                                                
    while(baca != NULL) {
        printf("%d\t%s\t\t%.2f\n", baca->no, baca->nama, baca->nilai);
        baca = baca->next;
    }
    printf("\n");
}