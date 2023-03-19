#include <stdio.h>
#include <string.h>

// deklarasi struct
typedef struct student {
    char nama[30], grade;
    int tugas, uts, uas, akhir;
} mahasiswa;

typedef struct valedictorian {
    char nama[30];
    int nilai;
} valedict;

// global variable batasan array;
int maks;

// prototype fungsi
void input(mahasiswa *);
void tampil(mahasiswa *);
void tertinggi(mahasiswa *, valedict *);

int main(int argc, char const *argv[])
{
    // input jumlah mahasiswa
    printf("MENGHITUNG NILAI AKHIR\nMATKUL KONSEP PEMROGRAMAN\n\n");
    printf("Berapa jumlah mahasiswa? ");
    scanf("%d", &maks);
    fflush(stdin);

    // deklarasi struct
    mahasiswa mhs[maks];
    valedict konsep_pemrograman;

    // pemanggilan fungsi
    input(&mhs);
    tampil(&mhs);

    // total mahasiswa
    printf("\n\nTotal Mahasiswa = %d", maks);
    
    // nilai tertinggi
    tertinggi(&mhs, &konsep_pemrograman);

    return 0;
}

void input(mahasiswa *msw) {
    printf("\nMasukkan DATA Mahasiswa\n\n");

    // input ke struct secara urut indeks
    for(int i = 0; i < maks; i++) {
        printf("Mahasiswa ke %d\n", i+1);
        printf("Nama: ");
        fgets((msw+i)->nama, sizeof((msw+i)->nama), stdin);
        printf("Nilai tugas: ");
        scanf("%d", &(msw+i)->tugas);
        printf("Nilai uts: ");
        scanf("%d", &(msw+i)->uts);
        printf("Nilai uas: ");
        scanf("%d", &(msw+i)->uas);
        fflush(stdin);
    }
}

void tampil(mahasiswa *msw) {
    // deklarasi variabel untuk penomoran
    int no;

    printf("DAFTAR NILAI\nMATKUL KONSEP PEMROGRAMAN\n");
    printf("============================================================\n");
    printf("No\tNama\t\tNilai\t\t\t\tGrade\n");
    printf("\tMahasiswa\tTugas\tUTS\tUAS\tAkhir\n");
    printf("============================================================\n");

    // proses hitung nilai akhir dan grade secara urut indeks
    for(int i = 0; i < maks; i++) {
        (msw+i)->akhir = ((msw+i)->tugas * 20 / 100) + ((msw+i)->uts * 40 / 100) + ((msw+i)->uas * 40 / 100);

        if((msw+i)->akhir >= 80) {
            (msw+i)->grade = 'A';
        } else if((msw+i)->akhir >= 70) {
            (msw+i)->grade = 'B';
        } else if((msw+i)->akhir >= 60) {
            (msw+i)->grade = 'C';
        } else if((msw+i)->akhir >= 50) {
            (msw+i)->grade = 'D';
        } else if((msw+i)->akhir < 50) {
            (msw+i)->grade = 'E';
        }   
        no += 1;
        printf("%d\t%s\t\t\t%d\t%d\t%d\t%d\t%c\n", no, (msw+i)->nama, (msw+i)->tugas, (msw+i)->uts, (msw+i)->uas, (msw+i)->akhir, (msw+i)->grade);
    }
    
}

void tertinggi(mahasiswa *msw, valedict *kp) {
    // init value field index pertama ke struct valedict
    kp->nilai = msw->akhir;
    strcpy(kp->nama, msw->nama);

    // bandingkan setiap index student dengan valedict
    for(int i = 0; i < maks; i++) {
        if((msw+i)->akhir > kp->nilai) {
            kp->nilai = (msw+i)->akhir;
            strcpy(kp->nama, (msw+i)->nama);
        }
    }

    printf("\nNilai tertinggi\n");
    printf("Nama: %s", kp->nama);
    printf("Nilai: %d", kp->nilai);
}

/*
    CATATAN TAMBAHAN

    Menggunakan [] untuk mengakses atau membaca field tidak bisa dilakukan, karena
    [] bersifat dereferencing (*). Sehingga mengakses field dengan -> tidak bisa dilakukan karena field struct yang akan diakses bukan lagi sebuah pointer.

    Pendekatan alternatif adalah dengan cara (array+i)->field supaya bisa melakukan akses field dengan arrow operator. Atau bisa dengan dot operator jika ingin mengakses dengan pendekatan diatas, misal array[i].field
*/