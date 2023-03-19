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
void akhir();
void after();
void before();
void del_awal();
void del_akhir();
void del_tertentu();
void output();

int main(int argc, char const *argv[])
{
    int flag = 0, option, menu;

    while(!flag) {
        printf("Menu\n1. Insert\n2. Delete\n3. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &option);
        fflush(stdin);

        switch(option) {
            case 1:
                printf("Menu INSERT\n1.Awal\n2.Akhir\n3.Sebelum\n4.Sesudah\n");
                printf("Pilihan: ");
                scanf("%d", &menu); fflush(stdin);
                if(menu == 1) {
                    alokasi();
                    awal();
                    output();
                } else if(menu == 2) {
                    alokasi();
                    akhir();
                    output();
                } else if(menu == 3) {
                    after();
                    output();
                } else if(menu == 4) {
                    before();
                    output();
                } else {
                    printf("Tidak Valid\n");
                }
                break;
            case 2:
                printf("Menu DELETE\n1.Awal\n2.Akhir\n3.Tertentu\n");
                printf("Pilihan: ");
                scanf("%d", &menu); fflush(stdin);
                if(menu == 1) {
                    del_awal();
                } else if(menu == 2) {
                    del_akhir();
                } else if(menu == 3) {
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
        while(before->data != key) {
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
    } else {
        if(head->next == NULL) {
            free(head);
            head = NULL;
            output();
        } else {
            delete = head;
            head = head->next;
            free(delete);
            delete = head;
            output();
        }
    }
    printf("SLL kosong\n");
}

void del_akhir()
{
    Node *delete, *prevDelete;
    printf("\nDelete akhir\n");
    if(head == NULL) {
        printf("SLL kosong\n");
    } else {
        if(head->next == NULL) {
            free(head);
            head = NULL;
        } else {
            delete = head;
            while(delete->next != NULL) {
                prevDelete = delete;
                delete = delete->next;
            }
            prevDelete->next = NULL;
            free(delete);
            delete = NULL;
        }
        output();

        printf("SLL kosong\n");
    }
}

void del_tertentu()
{
    Node *delete, *prevDelete;
    int key;
    printf("\nDelete akhir\n");
    printf("Input key: "); scanf("%d", &key);
    if(head == NULL) {
        printf("SLL kosong\n");
    } else {
        if(head->data == key) {
            free(head);
            head = NULL;
    } else {
            delete = head;
            while(delete->data != key) {
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
    }
    output();

    printf("SLL telah dihapus\n");
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
    printf("\n");
}