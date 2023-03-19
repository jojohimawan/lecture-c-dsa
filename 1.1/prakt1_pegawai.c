#include <stdio.h>
#include <string.h>

// deklarasi variabel struct
typedef struct date {
    int day, month, year
} tanggal;

typedef struct employee {
    tanggal lahir;
    char nama[30], k, jk[12];
    int id, gaji, pegawai
} pegawai;

// global variable untuk batasan array
int jumlah_pegawai;

// prototype fungsi
void input(pegawai *);
void tampil(pegawai *);

int main(int argc, char const *argv[])
{
    // input batasan array
    printf("DATA PEGAWAI\n");
    printf("Berapa jummlah pegawai? :");
    scanf("%d", &jumlah_pegawai); 

    // deklarasi array of struct
    pegawai emp[jumlah_pegawai];

    // pemanggilan fungsi
    input(emp);
    tampil(emp);
    
    return 0;
}

void input(pegawai *emp){
    for(int i = 0; i < jumlah_pegawai; i++) {
        fflush(stdin);
        printf("Data pegawai ke-%d\n", i+1);
        printf("Nama: ");
        fgets(emp[i].nama, sizeof(emp[i].nama), stdin);
        fflush(stdin);
        printf("Tgl lahir <dd mm yyyy>: ");
        scanf("%d %d %d", &emp[i].lahir.day, &emp[i].lahir.month, &emp[i].lahir.year);
        fflush(stdin);
        printf("Jenis kelamin [L/P]: ");
        scanf("%c", &emp[i].k);
        fflush(stdin);
        printf("Gaji/bln: ");
        scanf("%d",  &emp[i].gaji);
        fflush(stdin);
    }
}

void tampil(pegawai *emp) {
    printf("\nData pegawai yang telah diinputkan\n");

    for(int i = 0; i < jumlah_pegawai; i++) {
        // assign id
        emp[i].id = i+1;

        // string assign jenis kelamin
        if(emp[i].k == 'L' || emp[i].k == 'l') {
            strcpy(emp[i].jk, "Laki-Laki");
        } else if(emp[i].k == 'P' || emp[i].k == 'p') {
            strcpy(emp[i].jk, "Perempuan");
        } else {
            strcpy(emp[i].jk, "Tidak disebutkan");
        }

        // output
        printf("No ID: %d\n", emp[i].id);
        printf("Nama: %s", emp[i].nama);
        printf("Tgl lahir: %d-%d-%d\n", emp[i].lahir.day, emp[i].lahir.month, emp[i].lahir.year);
        printf("Jenis kelamin: %s\n", emp[i].jk);
        printf("Gaji/bln: Rp %d,00\n\n", emp[i].gaji);
    }
}