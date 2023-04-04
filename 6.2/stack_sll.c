//
// Created by jordan on 3/30/2023.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
typedef char itemType;
struct simpul {
    itemType data;
    Node *next;
};

Node *head = NULL, *p;

void menu();
void stackInit();
void stackPush();
void stackPop();
void readLifo();

int main(int argc, char const *argv[])
{
//    char flag; printf("Stack SLL\n");
//    do {
//        stackInit(); stackPush();
//        fflush(stdin);
//        printf("lagi? ");
//        scanf("%c", &flag);
//        fflush(stdin);
//    } while((flag == 'y') || (flag == 'Y'));
//    printf("Isi dari Stack\n");
//    baca();
//    stackPop();
menu();


    return 0;
}

void menu() {
    int flag = 0, option;

    while(!flag) {
        puts("STACK USING SLL");
        printf("1. Mengisi Stack (PUSH)\n2. Mengambil Isi Stack (POP)\n3. Menampilkan Isi Stack (LIFO)\n4. Keluar\n");
        printf("Masukkan opsi: ");
        scanf("%d", &option);
        fflush(stdin);

        switch(option) {
            case 1:
                stackInit();
                stackPush();
                break;
            case 2:
                stackPop();
                break;
            case 3:
                readLifo();
                break;
            case 4:
                flag = 1;
                break;
            default:
                puts("Invalid");
                exit(0);
        }
    }
}

void stackInit() {
    p = (Node *) malloc(sizeof(Node));
    if(p != NULL) {
        printf("Data yang mau diinput: "); scanf("%c", &p->data); p->next = NULL;
    } else {
        printf("Gagal Init\n"); exit(0);
    }
}

void stackPush()
{
    // jika head tidak kosong
    if(head != NULL) {
        // assign next dengan node sebelumnya
        p->next = head;
    }

    // head menunjuk pada node baru yang telah disambungkan (line 57)
    head = p;
}

void stackPop()
{
    Node *delete;
    printf("\nDelete awal\n");
    if(head == NULL) {
        printf("STACK kosong\n");
    } else {
        printf("Data diPOP = %c\n", head->data);
        if(head->next == NULL) {
            free(head);
            head = NULL;
            readLifo();
        } else {
            delete = head;
            head = head->next;
            free(delete);
            delete = head;
            readLifo();
        }
    }
}

void readLifo()
{
    Node *baca; baca = head;
    while(baca != NULL)
    {
        printf("%c\n", baca->data);
        baca = baca->next;
    }
    printf("\n");

}