//
// Created by jordan on 5/31/2023.
//
#include <stdio.h>
#include <stdlib.h>

typedef char itemType;
typedef struct tree Leaf;
struct tree {
    itemType data;
    Leaf *left, *right;
};
Leaf *root = NULL, *new;

void menuTraversal();
void bentuk(itemType);
void sisip();
void preorder(Leaf *);
void inorder(Leaf *);
void postorder(Leaf *);
void input();
void cari(Leaf *, itemType);

int main()
{
    input();
    menuTraversal();
    return 0;
}

void menuTraversal()
{
    int option, flag = 1;
    itemType key;

    do {
        printf("PILIH PENELUSURAN TREE\n1. Preorder\n2. Postorder\n3. Inorder\n4. Cari\n5. Keluar\nPilihan anda: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Hasil traversal secara preorder: ");
                preorder(root);
                break;
            case 2:
                printf("Hasil traversal secara postorder: ");
                postorder(root);
                break;
            case 3:
                printf("Hasil traversal secara postorder: ");
                inorder(root);
                break;
            case 4:
                fflush(stdin);
                printf("Masukkan key: ");
                scanf("%c", &key);
                cari(root, key);
                break;
            default:
                puts("Invalid");
                break;
        }

        printf("\nMencoba metode lain? [1/0]: ");
        scanf("%d", &flag);
    }while(flag);


}

void bentuk(itemType n)
{
    // prepare new leaf
    new = (Leaf *) malloc(sizeof(Leaf));

    // check for leaf
    if(new == NULL) {
        puts("Gagal");
        exit(0);
    } else {
        new->data = n;
        new->left = NULL;
        new->right = NULL;
    }
    sisip();
}

void sisip()
{
    if(root == NULL) {
        root = new;
    } else {
        Leaf *p = root, *q = root;

        while(q != NULL && new->data != p->data) {
            p = q;
            if(new->data < p->data) {
                q = p->left;
            } else if(new->data > p->data) {
                q = p->right;
            }
        }

        if(new->data == p->data) {
            puts("Duplikasi data");
        } else {
            if(new->data < p->data) {
                p->left = new;
            } else {
                p->right = new;
            }
        }
    }
}

void preorder(Leaf *akar)
{
    if(akar != NULL) {
        printf("%c ", akar->data);
        preorder(akar->left);
        preorder(akar->right);
    }
}

void inorder(Leaf *akar)
{
    if(akar != NULL) {
        inorder(akar->left);
        printf("%c ", akar->data);
        inorder(akar->right);
    }
}

void postorder(Leaf *akar)
{
    if(akar != NULL) {
        postorder(akar->left);
        postorder(akar->right);
        printf("%c ", akar->data);
    }
}

void input()
{
    itemType data;
    int pilihan = 1;

    printf("MEMBENTUK SEBUAH TREE\n");
    do
    {
        fflush(stdin);
        printf("Ketikkan data/infonya: ");
        scanf("%c", &data);

        bentuk(data);

        printf("Ada data lagi? (1/0): ");
        scanf(" %d", &pilihan);
    }while(pilihan);
}

void cari(Leaf *akar, itemType k)
{
    if(akar == NULL) {
        puts("Tree kosong atau key tidak ditemukan");
    } else {
        if(k == akar->data) {
            printf("Key %c ditemukan\n", k);
        } else if(k < akar->data) {
            cari(akar->left, k);
        } else if(k > akar->data) {
            cari(akar->right, k);
        }
    }
}