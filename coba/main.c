#include <stdlib.h>
#include <stdio.h>

typedef struct simpul node;
struct simpul
{
    int no;
    char name[20];
    float nilai;
    node *next;
    node *prev;
};
node *head=NULL, *p,*current=NULL,*hapus=NULL,*ph=NULL;
void alokasi();
void tampil();
void akhir();
void hapus1();
void bebas();
void urut();
void pilihan();
void tampil();
void cari();
void carirata2();
int main()
{
    pilihan();
}
void pilihan()
{
    int x;
    do
    {
        printf("1. Penambahan Secara terurut\n2. Pencarian data\n3. Menghapus Data\n4. Rata-rata\n5. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%i",&x);
        fflush(stdin);
        if(x==1)
        {
            alokasi();
        }
        else if(x==2)
        {
            cari();
        }
        else if(x==3)
        {
            hapus1();
        }
        else if(x==4)
        {
            carirata2();
        }
        else if(x==5)
        {
            exit(0);
        }
        tampil();
    }
    while(x!=5);
}
void carirata2()
{
    node *rata;
    float total=0,rata2,banyak=0;
    rata=head;
    while(rata!=NULL)
    {
        total=total+rata->nilai;
        rata=rata->next;
        banyak++;
    }
    rata2=total/banyak;
    printf("Rata-rata= %.2f\n",rata2);
}
void alokasi()
{
    p=(node *)malloc(sizeof(node));
    if(p==NULL)
    {
        printf("Alokasi gagal");
        exit(0);
    }
    else
    {
       printf("Masukkan nomer: ");
        scanf("%i",&p->no);
        fflush(stdin);
        printf("Masukkan nama: ");
        gets(p->name);
        printf("Masukkan nilai: ");
        scanf("%f",&p->nilai);
        p->next=NULL;
        p->prev=NULL;
        if(head==NULL)
        {
            head=p;

        }
        else
        {
            urut();
        }

    }

}
void awal()
{
    p->next=head;
    head->prev=p;
    head=p;
}
void akhir()
{
    p->prev=current;
    current->next=p;
}
void urut()
{
    current = head;
    if(current->next!=NULL)
    {
        if(current->no<=p->no)
        {
            while(current->no<=p->no)
            {
                current=current->next;
                if(current->next==NULL)
                {
                    break;
                }

            }
            if(current->prev->no<=p->no&&current->no>=p->no)
            {
                p->next=current->prev->next;
                current->prev->next=p;
                current->prev=p;
            }
            else
                akhir();
        }
        else
        {
            awal();
        }
    }
    else
    {
        if(current->no<=p->no)
        {
            akhir();
        }
        else
        {
            awal();
        }
    }


}
void cari()
{

    if(head==NULL)
    {
        printf("SLL masih Kosong.\n");
    }
    else
    {
        node *search;
        int x,banyak=0;
        printf("Masukkan Data yang ingin di cari: ");
        scanf("%i",&x);
        search=head;
        if(search->next==NULL)
        {

            if(search->no==x)
            {
                banyak++;
            }
        }
        else
        {
            do
            {
                if(search->no==x)
                {
                    banyak++;
                }
                search=search->next;
            }
            while(search!=NULL);
        }
        if(banyak==0)
        {
            printf("%d Tidak ada dalam DLL\n",x);
        }
        else
        {
            printf("Data %d ketemu sebanyak %d\n",x,banyak);
        }
    }
}
void bebas()
{
    free(hapus);
    hapus=NULL;
}
void hapus1()
{
    int key;
    printf("Data mana yang ingin dihapus: ");
    scanf("%i",&key);
    hapus=head;
    if (head==NULL)
    {
        printf("SLL masih kosong.\n");
    }
    else
    {


        if(head->next==NULL&&head->no==key)
        {
            head=NULL;
            bebas();
        }
        else
        {
            if(head->no==key)
            {
                head=hapus->next;
                hapus->next->prev=NULL;
                bebas();
            }
            else
            {

                while(hapus->no !=key)
                {
                    if(hapus->next == NULL)
                    {
                        printf("%d Tidak Ada dalam DLL\n",key);
                        tampil();
                        pilihan();
                    }
                    else
                    {
                        hapus = hapus->next;
                    }
                }
                if(hapus->next==NULL)
                {
                    hapus->prev->next=NULL;
                    bebas();
                }
                else
                {
                    hapus->prev->next=hapus->next;
                    hapus->next->prev=hapus->prev;
                    bebas();
                }
            }
        }
    }



}
void tampil()
{
    node *baca;
    baca=head;
    printf("Data pada DLL:\n");
    printf("No\tNama\tNilai\n");
    while(baca!=NULL)
    {

        printf("%i\t%s\t%.2f\n",baca->no,baca->name,baca->nilai);
        baca=baca->next;
    }
}
