//S1-IF-10-06
//Ilma Kurnia 2211102162
//Nadia Nabila 2211102174
//Nida Gina Iswardhani 2211102306
//Rahma Ayu Riyantini 2211102313

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PENUMPANG 5
#define MAX_DATA 13
#define MAX_KELAS 4
#define MAX_KODE 20
#define MAX_JAM 20
#define MAX_KOTA 6
#define MAX_KERETA 6
#define MAX_TEMPAT_DUDUK 10
#define MAX_LENGTH 50

int inputan, i, j, opsi1, opsi2, opsi3, opsi4, harga;
bool tersedia;
int jumlah = 0;
char opsi_ulang[10], data_kereta[20], data_gerbong[20];

char data_penumpang[MAX_PENUMPANG][12][50];  // Data penumpang

// Prosedur untuk menambah tab pada setiap printf
void indentasi() {
    printf("\t\t\t");
}

// Prosedur untuk loading di awal
void loading(int waktuTunggu) {
    system("cls");
    printf("\n\n\n\t\t\t");
    printf("===== SELAMAT DATANG DI APLIKASI PEMESANAN TIKET KERETA =====\n");
    indentasi();
    printf("========================== SILAMBAT =========================\n");
    indentasi();
    printf("\t\t");
    
    // Tampilan Loading Bar
    for (int a = 1; a <= 30; a++) {
        printf("*");
        Sleep(waktuTunggu);
    }

    // Menampilkan gambar kereta
    printf("\n                                                 \n");
    indentasi();
    printf("\t      _     =====  ====================      \n");
    indentasi();
    printf("\t     | |    |[ ]|  |  [ ] [ ] [ ] [ ] |      \n");
    indentasi();
    printf("\t   |=|=|====|===|  |==================|      \n");
    indentasi();
    printf("\t   |        |   |  |                  |      \n");
    indentasi();
    printf("\t   |=O===O==|=O=|==|===O===O===O===O==|      \n");
    indentasi();
    printf("\t                                             \n");
    indentasi();
    printf("\t                                             \n");
    printf(" 100%%\n");
    indentasi();
    printf("Aplikasi sudah siap digunakan\n");
    indentasi();
    printf("Silahkan tekan tombol Enter");
    getch();
    system("CLS");
}

// Prosedur yang menampilkan harga jurusan kereta
void cek_harga() {
    printf("\n\t |===========================|===============|==============|=================|================|  ");
    printf("\n\t |          Jurusan          |    Ekonomi    |    Bisnis    |    Eksekutif    |     Luxury     |  ");
    printf("\n\t |===========================|===============|==============|=================|================|  ");
    printf("\n\t |   Jakarta - Surabaya      |   Rp 350.000  |   Rp 500.000 |   Rp 880.000    |  Rp 1.200.000  |  ");
    printf("\n\t |   Jakarta - Bandung       |   Rp  90.000  |   Rp 150.000 |   Rp 250.000    |  Rp   400.000  |  ");
    printf("\n\t |   Jakarta - Semarang      |   Rp 250.000  |   Rp 400.000 |   Rp 750.000    |  Rp   890.000  |  ");
    printf("\n\t |   Jakarta - Yogyakarta    |   Rp 290.000  |   Rp 425.000 |   Rp 590.000    |  Rp   970.000  |  ");
    printf("\n\t |   Jakarta - Purwokerto    |   Rp 210.000  |   Rp 385.000 |   Rp 450.000    |  Rp   770.000  |  ");
    printf("\n\t |                           |               |              |                 |                |  ");
    printf("\n\t |   Surabaya - Bandung      |   Rp 420.000  |   Rp 510.000 |   Rp 620.000    |  Rp   830.000  |  ");
    printf("\n\t |   Surabaya - Semarang     |   Rp 150.000  |   Rp 290.000 |   Rp 400.000    |  Rp   590.000  |  ");
    printf("\n\t |   Surabaya - Yogyakarta   |   Rp 240.000  |   Rp 310.000 |   Rp 420.000    |  Rp   610.000  |  ");
    printf("\n\t |   Surabaya - Purwokerto   |   Rp 270.000  |   Rp 350.000 |   Rp 460.000    |  Rp   630.000  |  ");
    printf("\n\t |                           |               |              |                 |                |  ");
    printf("\n\t |   Bandung - Semarang      |   Rp 60.000   |   Rp 290.000 |   Rp 400.000    |  Rp   680.000  |  ");
    printf("\n\t |   Bandung - Yogyakarta    |   Rp 50.000   |   Rp 360.000 |   Rp 445.000    |  Rp   720.000  |  ");
    printf("\n\t |   Bandung - Purwokerto    |   Rp 80.000   |   Rp  95.000 |   Rp 150.000    |  Rp   350.000  |  ");
    printf("\n\t |                           |               |              |                 |                |  ");
    printf("\n\t |   Semarang - Yogyakarta   |   Rp 150.000  |   Rp 270.000 |   Rp 335.000    |  Rp   500.000  |  ");
    printf("\n\t |   Semarang - Purwokerto   |   Rp 65.000   |   Rp 180.000 |   Rp 255.000    |  Rp   430.000  |  ");
    printf("\n\t |                           |               |              |                 |                |  ");
    printf("\n\t |   Yogyakarta - Purwokerto |   Rp 190.000  |   Rp 280.000 |   Rp 395.000    |  Rp   520.000  |  ");
    printf("\n\t |                           |               |              |                 |                |  ");
    printf("\n\t |===========================|===============|==============|=================|================|  ");
}

// Fungsi pemilihan kelas kereta
int kelas_kereta() {
    int kelas;
    char *kelas_kereta[] = {"Ekonomi", "Bisnis", "Eksekutif", "Luxury"};
    
    do {
        for (i = 0; i < 4; i++) {
            printf("\n%d) %s", i + 1, kelas_kereta[i]);
        }
        printf("\nPilih Kelas Yang Anda Inginkan: ");
        scanf("%d", &kelas);
        
        if (kelas >= 1 && kelas <= 4) {
            printf("\nAnda telah memilih kelas %s\n", kelas_kereta[kelas - 1]);
            strcpy(data_penumpang[jumlah][5], kelas_kereta[kelas - 1]);
        } else {
            printf("\n=== Pilihan tidak tersedia ===\n");
        }
    } while (kelas < 1 || kelas > 4);
    
    return kelas;
}

// Prosedur untuk menentukan harga tiket, jam, dan kode kereta
void harga_tiket(int kelas, int opsi1, int opsi2, char data_penumpang[][12][50], int jumlah) {
    char kode[50] = "";  // Inisialisasi string kode
    char jam[10] = "";   // Inisialisasi string jam
    int harga = 0;       // Inisialisasi harga
    int admin, total;

    if (kelas == 1) { // Jika memilih kelas 1 (Ekonomi)
        if ((opsi1 == 1 && opsi2 == 2) || (opsi1 == 2 && opsi2 == 1)) {
            harga = 350000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-eko1");
        } else if ((opsi1 == 1 && opsi2 == 3) || (opsi1 == 3 && opsi2 == 1)) {
            harga = 90000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-eko2");
        } else if ((opsi1 == 1 && opsi2 == 4) || (opsi1 == 4 && opsi2 == 1)) {
            harga = 250000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-eko3");
        } else if ((opsi1 == 1 && opsi2 == 5) || (opsi1 == 5 && opsi2 == 1)) {
            harga = 290000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-eko4");
        } else if ((opsi1 == 1 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 1)) {
            harga = 210000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-eko5");
        } else if ((opsi1 == 2 && opsi2 == 3) || (opsi1 == 3 && opsi2 == 2)) {
            harga = 420000;
            strcpy(jam, "08.00");
            strcpy(kode, "Kai-eko6");
        } else if ((opsi1 == 2 && opsi2 == 4) || (opsi1 == 4 && opsi2 == 2)) {
            harga = 150000;
            strcpy(jam, "08.00");
            strcpy(kode, "Kai-eko7");
        } else if ((opsi1 == 2 && opsi2 == 5) || (opsi1 == 5 && opsi2 == 2)) {
            harga = 240000;
            strcpy(jam, "08.00");
            strcpy(kode, "Kai-eko8");
        } else if ((opsi1 == 2 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 2)) {
            harga = 270000;
            strcpy(jam, "08.00");
            strcpy(kode, "Kai-eko9");
        } else if ((opsi1 == 3 && opsi2 == 4) || (opsi1 == 4 && opsi2 == 3)) {
            harga = 60000;
            strcpy(jam, "09.00");
            strcpy(kode, "Kai-eko10");
        } else if ((opsi1 == 3 && opsi2 == 5) || (opsi1 == 5 && opsi2 == 3)) {
            harga = 50000;
            strcpy(jam, "09.00");
            strcpy(kode, "Kai-eko11");
        } else if ((opsi1 == 3 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 3)) {
            harga = 80000;
            strcpy(jam, "09.00");
            strcpy(kode, "Kai-eko12");
        } else if ((opsi1 == 4 && opsi2 == 5) || (opsi1 == 5 && opsi2 == 4)) {
            harga = 150000;
            strcpy(jam, "10.00");
            strcpy(kode, "Kai-eko13");
        } else if ((opsi1 == 4 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 4)) {
            harga = 65000;
            strcpy(jam, "10.00");
            strcpy(kode, "Kai-eko14");
        } else if ((opsi1 == 5 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 5)) {
            harga = 190000;
            strcpy(jam, "11.00");
            strcpy(kode, "Kai-eko15");
        }
    } else if (kelas == 2) { // Jika memilih kelas 2 (Bisnis)
        if ((opsi1 == 1 && opsi2 == 2) || (opsi1 == 2 && opsi2 == 1)) {
            harga = 500000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-bns1");
        } else if ((opsi1 == 1 && opsi2 == 3) || (opsi1 == 3 && opsi2 == 1)) {
            harga = 150000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-bns2");
        } else if ((opsi1 == 1 && opsi2 == 4) || (opsi1 == 4 && opsi2 == 1)) {
            harga = 400000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-bns3");
        } else if ((opsi1 == 1 && opsi2 == 5) || (opsi1 == 5 && opsi2 == 1)) {
            harga = 425000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-bns4");
        } else if ((opsi1 == 1 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 1)) {
            harga = 385000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-bns5");
        } else if ((opsi1 == 2 && opsi2 == 3) || (opsi1 == 3 && opsi2 == 2)) {
            harga = 510000;
            strcpy(jam, "08.00");
            strcpy(kode, "Kai-bns6");
        } else if ((opsi1 == 2 && opsi2 == 4) || (opsi1 == 4 && opsi2 == 2)) {
            harga = 290000;
            strcpy(jam, "08.00");
            strcpy(kode, "Kai-bns7");
        } else if ((opsi1 == 2 && opsi2 == 5) || (opsi1 == 5 && opsi2 == 2)) {
            harga = 310000;
            strcpy(jam, "08.00");
            strcpy(kode, "Kai-bns8");
        } else if ((opsi1 == 2 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 2)) {
            harga = 350000;
            strcpy(jam, "08.00");
            strcpy(kode, "Kai-bns9");
        } else if ((opsi1 == 3 && opsi2 == 4) || (opsi1 == 4 && opsi2 == 3)) {
            harga = 290000;
            strcpy(jam, "09.00");
            strcpy(kode, "Kai-bns10");
        } else if ((opsi1 == 3 && opsi2 == 5) || (opsi1 == 5 && opsi2 == 3)) {
            harga = 360000;
            strcpy(jam, "09.00");
            strcpy(kode, "Kai-bns11");
        } else if ((opsi1 == 3 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 3)) {
            harga = 95000;
            strcpy(jam, "09.00");
            strcpy(kode, "Kai-bns12");
        } else if ((opsi1 == 4 && opsi2 == 5) || (opsi1 == 5 && opsi2 == 4)) {
            harga = 270000;
            strcpy(jam, "10.00");
            strcpy(kode, "Kai-bns13");
        } else if ((opsi1 == 4 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 4)) {
            harga = 180000;
            strcpy(jam, "10.00");
            strcpy(kode, "Kai-bns14");
        } else if ((opsi1 == 5 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 5)) {
            harga = 280000;
            strcpy(jam, "11.00");
            strcpy(kode, "Kai-bns15");
        }
    } else if (kelas == 3) { // Jika memilih kelas 3 (Eksekutif)
        if ((opsi1 == 1 && opsi2 == 2) || (opsi1 == 2 && opsi2 == 1)) {
            harga = 880000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-eks1");
        } else if ((opsi1 == 1 && opsi2 == 3) || (opsi1 == 3 && opsi2 == 1)) {
            harga = 250000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-eks2");
        } else if ((opsi1 == 1 && opsi2 == 4) || (opsi1 == 4 && opsi2 == 1)) {
            harga = 750000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-eks3");
        } else if ((opsi1 == 1 && opsi2 == 5) || (opsi1 == 5 && opsi2 == 1)) {
            harga = 590000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-eks4");
        } else if ((opsi1 == 1 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 1)) {
            harga = 450000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-eks5");
        } else if ((opsi1 == 2 && opsi2 == 3) || (opsi1 == 3 && opsi2 == 2)) {
            harga = 620000;
            strcpy(jam, "08.00");
            strcpy(kode, "Kai-eks6");
        } else if ((opsi1 == 2 && opsi2 == 4) || (opsi1 == 4 && opsi2 == 2)) {
            harga = 400000;
            strcpy(jam, "08.00");
            strcpy(kode, "Kai-eks7");
        } else if ((opsi1 == 2 && opsi2 == 5) || (opsi1 == 5 && opsi2 == 2)) {
            harga = 420000;
            strcpy(jam, "08.00");
            strcpy(kode, "Kai-eks8");
        } else if ((opsi1 == 2 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 2)) {
            harga = 460000;
            strcpy(jam, "08.00");
            strcpy(kode, "Kai-eks9");
        } else if ((opsi1 == 3 && opsi2 == 4) || (opsi1 == 4 && opsi2 == 3)) {
            harga = 400000;
            strcpy(jam, "09.00");
            strcpy(kode, "Kai-eks10");
        } else if ((opsi1 == 3 && opsi2 == 5) || (opsi1 == 5 && opsi2 == 3)) {
            harga = 445000;
            strcpy(jam, "09.00");
            strcpy(kode, "Kai-eks11");
        } else if ((opsi1 == 3 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 3)) {
            harga = 150000;
            strcpy(jam, "09.00");
            strcpy(kode, "Kai-eks12");
        } else if ((opsi1 == 4 && opsi2 == 5) || (opsi1 == 5 && opsi2 == 4)) {
            harga = 335000;
            strcpy(jam, "10.00");
            strcpy(kode, "Kai-eks13");
        } else if ((opsi1 == 4 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 4)) {
            harga = 225000;
            strcpy(jam, "10.00");
            strcpy(kode, "Kai-eks14");
        } else if ((opsi1 == 5 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 5)) {
            harga = 395000;
            strcpy(jam, "11.00");
            strcpy(kode, "Kai-eks15");
        }
    } else if (kelas == 4) { // Jika memilih kelas 4 (Luxury)
        if ((opsi1 == 1 && opsi2 == 2) || (opsi1 == 2 && opsi2 == 1)) {
            harga = 1200000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-lux1");
        } else if ((opsi1 == 1 && opsi2 == 3) || (opsi1 == 3 && opsi2 == 1)) {
            harga = 400000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-lux2");
        } else if ((opsi1 == 1 && opsi2 == 4) || (opsi1 == 4 && opsi2 == 1)) {
            harga = 890000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-lux3");
        } else if ((opsi1 == 1 && opsi2 == 5) || (opsi1 == 5 && opsi2 == 1)) {
            harga = 970000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-lux4");
        } else if ((opsi1 == 1 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 1)) {
            harga = 770000;
            strcpy(jam, "07.00");
            strcpy(kode, "Kai-lux5");
        } else if ((opsi1 == 2 && opsi2 == 3) || (opsi1 == 3 && opsi2 == 2)) {
            harga = 830000;
            strcpy(jam, "08.00");
            strcpy(kode, "Kai-lux6");
        } else if ((opsi1 == 2 && opsi2 == 4) || (opsi1 == 4 && opsi2 == 2)) {
            harga = 590000;
            strcpy(jam, "08.00");
            strcpy(kode, "Kai-lux7");
        } else if ((opsi1 == 2 && opsi2 == 5) || (opsi1 == 5 && opsi2 == 2)) {
            harga = 610000;
            strcpy(jam, "08.00");
            strcpy(kode, "Kai-lux8");
        } else if ((opsi1 == 2 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 2)) {
            harga = 630000;
            strcpy(jam, "08.00");
            strcpy(kode, "Kai-lux9");
        } else if ((opsi1 == 3 && opsi2 == 4) || (opsi1 == 4 && opsi2 == 3)) {
            harga = 680000;
            strcpy(jam, "09.00");
            strcpy(kode, "Kai-lux10");
        } else if ((opsi1 == 3 && opsi2 == 5) || (opsi1 == 5 && opsi2 == 3)) {
            harga = 720000;
            strcpy(jam, "09.00");
            strcpy(kode, "Kai-lux11");
        } else if ((opsi1 == 3 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 3)) {
            harga = 350000;
            strcpy(jam, "09.00");
            strcpy(kode, "Kai-lux12");
        } else if ((opsi1 == 4 && opsi2 == 5) || (opsi1 == 5 && opsi2 == 4)) {
            harga = 500000;
            strcpy(jam, "10.00");
            strcpy(kode, "Kai-lux13");
        } else if ((opsi1 == 4 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 4)) {
            harga = 430000;
            strcpy(jam, "10.00");
            strcpy(kode, "Kai-lux14");
        } else if ((opsi1 == 5 && opsi2 == 6) || (opsi1 == 6 && opsi2 == 5)) {
            harga = 520000;
            strcpy(jam, "11.00");
            strcpy(kode, "Kai-lux15");
        } else {
            printf("\n=== Pilihan tidak tersedia ===\n");
        }
    }

    // Tampilkan hasil
    printf("Anda telah memilih kelas Ekonomi\n");
    printf("Kode: %s\n", kode);
    printf("Harga: Rp. %d\n", harga);
    printf("Jam: %s\n", jam);

    // Biaya administrasi
    admin = 5000;
    total = harga + admin;

    // Menampilkan harga dan kode
    printf("\n\tHarga Tiket  : Rp %d + Rp %d\n", harga, admin);
    printf("\tKode Tiket   : %s\n", kode);

    // Mengonversi total ke string dan memasukkan ke data_penumpang di baris jumlah dan index 8
    sprintf(data_penumpang[jumlah][8], "%d", total);  // Menggunakan sprintf untuk format string

    // Memasukkan nilai kode ke data_penumpang di baris jumlah dan index 9
    strcpy(data_penumpang[jumlah][9], kode);  // Menggunakan strcpy untuk menyalin string

    // Memasukkan nilai jam ke data_penumpang di baris jumlah dan index 11
    strcpy(data_penumpang[jumlah][11], jam);  // Menggunakan strcpy untuk menyalin string
}


// Prosedur untuk menentukan tanggal berangkat Kereta
void tanggal_pemberangkatan() {
    int tanggal, bulan, tahun;
    char tanggalan[30];

    // Input tanggal
    do {
        printf("\n\nMasukkan tanggal pemberangkatan: ");
        scanf("%d", &tanggal);
    } while (tanggal > 30 || tanggal < 1);

    // Input bulan
    do {
        printf("\nMasukkan bulan pemberangkatan (angka): ");
        scanf("%d", &bulan);
    } while (bulan > 12 || bulan < 1);

    // Input tahun
    printf("\nMasukkan tahun pemberangkatan: ");
    scanf("%d", &tahun);

    // Gabungkan tanggal, bulan, dan tahun
    sprintf(tanggalan, "%d / %d / %d", tanggal, bulan, tahun);
    printf("\n\n\tTanggal Pemberangkatan\n\t%s\n", tanggalan);
    strcpy(data_penumpang[jumlah][10], tanggalan);
}

// Prosedur yang menampilkan jam berangkat jurusan kereta
void cek_jam() {
    printf("\n\t |===========================|===============|==============|=================|================|  ");
    printf("\n\t |          Jurusan          |    Ekonomi    |    Bisnis    |    Eksekutif    |     Luxury     |  ");
    printf("\n\t |===========================|===============|==============|=================|================|  ");
    printf("\n\t |   Jakarta - Surabaya      |     07.00     |     07.00    |      07.00      |      07.00     |  ");
    printf("\n\t |   Jakarta - Bandung       |     07.00     |     07.00    |      07.00      |      07.00     |  ");
    printf("\n\t |   Jakarta - Semarang      |     07.00     |     07.00    |      07.00      |      07.00     |  ");
    printf("\n\t |   Jakarta - Yogyakarta    |     07.00     |     07.00    |      07.00      |      07.00     |  ");
    printf("\n\t |   Jakarta - Purwokerto    |     07.00     |     07.00    |      07.00      |      07.00     |  ");
    printf("\n\t |                           |               |              |                 |                |  ");
    printf("\n\t |   Surabaya - Bandung      |     08.00     |     08.00    |      08.00      |      08.00     |  ");
    printf("\n\t |   Surabaya - Semarang     |     08.00     |     08.00    |      08.00      |      08.00     |  ");
    printf("\n\t |   Surabaya - Yogyakarta   |     08.00     |     08.00    |      08.00      |      08.00     |  ");
    printf("\n\t |   Surabaya - Purwokerto   |     08.00     |     08.00    |      08.00      |      08.00     |  ");
    printf("\n\t |                           |               |              |                 |                |  ");
    printf("\n\t |   Bandung - Semarang      |     09.00     |     09.00    |      09.00      |      09.00     |  ");
    printf("\n\t |   Bandung - Yogyakarta    |     09.00     |     09.00    |      09.00      |      09.00     |  ");
    printf("\n\t |   Bandung - Purwokerto    |     09.00     |     09.00    |      09.00      |      09.00     |  ");
    printf("\n\t |                           |               |              |                 |                |  ");
    printf("\n\t |   Semarang - Yogyakarta   |     10.00     |     10.00    |      10.00      |      10.00     |  ");
    printf("\n\t |   Semarang - Purwokerto   |     10.00     |     10.00    |      10.00      |      10.00     |  ");
    printf("\n\t |                           |               |              |                 |                |  ");
    printf("\n\t |   Yogyakarta - Purwokerto |     11.00     |     11.00    |      11.00      |      11.00     |  ");
    printf("\n\t |                           |               |              |                 |                |  ");
    printf("\n\t |===========================|===============|==============|=================|================|  ");
}

// Prosedur Pemilihan Kota awal dan tujuan
void pendaftaran_tujuan() {
    char tempat_kereta[MAX_KOTA][20] = {"Jakarta", "Surabaya", "Bandung", "Semarang", "Yogyakarta", "Purwokerto"};
    int opsi1, opsi2;
    int i, jumlah = 0;  // Pastikan jumlah diinisialisasi dengan nilai yang sesuai

    do { // do untuk mengulang ketika input opsi selain dari 1-6
        // Perulangan Menampilkan List kota
        for (i = 0; i < MAX_KOTA; i++) {
            printf("\n%d) %s", i + 1, tempat_kereta[i]);
        }
        printf("\n\nPilih Kota Pemberangkatan: ");
        scanf("%d", &opsi1);

        // Cetak Peringatan jika input selain dari 1-6
        if (opsi1 > MAX_KOTA || opsi1 < 1) {
            printf("\n=== Opsi/Kota tidak tersedia ===");
        }
    } while (opsi1 > MAX_KOTA || opsi1 < 1);

    // nilai tempat_kereta di index opsi1 - 1 dimasukkan ke data_penumpang di baris jumlah dan index 2
    strcpy(data_penumpang[jumlah][2], tempat_kereta[opsi1 - 1]);
    // kota pemberangkatan akan diubah menjadi [Pilihan Berangkat]
    strcpy(tempat_kereta[opsi1 - 1], "[Pilihan Berangkat]");

    do { // do untuk mengulang ketika data yang dimasukkan adalah data yang sudah dipilih([Pilihan Berangkat])
        do { // do untuk mengulang ketika input opsi selain dari 1-6
            for (i = 0; i < MAX_KOTA; i++) {
                printf("\n%d) %s", i + 1, tempat_kereta[i]);
            }
            printf("\n\nPilih Kota Tujuan: ");
            scanf("%d", &opsi2);

            // Cetak Peringatan jika input selain dari 1-6
            if (opsi2 > MAX_KOTA || opsi2 < 1) {
                printf("\n=== Opsi/Kota tidak tersedia ===");
            }
        } while (opsi2 > MAX_KOTA || opsi2 < 1);

        // nilai tempat_kereta di index opsi2 - 1 dimasukkan ke data_penumpang di baris jumlah dan index 3
        strcpy(data_penumpang[jumlah][3], tempat_kereta[opsi2 - 1]);

        // Cetak Peringatan jika nilai data_penumpang tadi bernilai [Pilihan Berangkat]
        if (strcmp(data_penumpang[jumlah][3], "[Pilihan Berangkat]") == 0) {
            printf("\n=== Pilihan Berangkat tidak dapat dipilih! ===");
        }
    } while (strcmp(data_penumpang[jumlah][3], "[Pilihan Berangkat]") == 0);
}

// Prosedur Pemilihan kereta, gerbong, dan tempat duduk
void pendaftaran_kereta() {
    char daftar_kereta[MAX_KERETA][20] = {"Brantas", "Singasari", "Mataram", "Bogowonto", "Gajayana", "Gumarang"};
    char tempatduduk_kereta[MAX_TEMPAT_DUDUK][3] = {"A1", "A2", "A3", "A4", "A5", "B1", "B2", "B3", "B4", "B5"};
    char gerbong_kereta[MAX_KERETA][3] = {"1", "2", "3", "4", "5", "6"};
    int opsi3, opsi4, i, j, jumlah = 0;  // Pastikan jumlah diinisialisasi dengan nilai yang sesuai
    bool tersedia = false;

    do { // do untuk mengulang ketika input opsi3 selain dari 1-6
        // Perulangan Menampilkan List Kereta
        for (i = 0; i < MAX_KERETA; i++) {
            printf("\n%d) %s", i + 1, daftar_kereta[i]);
        }
        // Input Kereta
        printf("\nPilih Kereta: ");
        scanf("%d", &opsi3);

        // Cetak Peringatan jika input selain dari 1-6
        if (opsi3 > MAX_KERETA || opsi3 < 1) {
            printf("\n=== Kereta tidak tersedia ===");
        }
    } while (opsi3 > MAX_KERETA || opsi3 < 1);

    // nilai daftar_kereta di index opsi3 - 1 dimasukkan ke variabel sementara data_kereta
    strcpy(data_kereta, daftar_kereta[opsi3 - 1]);
    printf("\n");

    do { // do untuk mengulang ketika input opsi selain dari 1-6
        // Perulangan Menampilkan List Gerbong Kereta
        for (i = 0; i < MAX_KERETA; i++) {
            printf("%s   ", gerbong_kereta[i]);
        }
        // Input Gerbong
        printf("\nPilih Gerbong: ");
        scanf("%d", &opsi4);

        // Cetak Peringatan jika input selain dari 1-6
        if (opsi4 > MAX_KERETA || opsi4 < 1) {
            printf("\n=== Gerbong tidak tersedia ===");
        }
    } while (opsi4 > MAX_KERETA || opsi4 < 1);

    // nilai gerbong_kereta di index opsi4 - 1 dimasukkan ke variabel sementara data_gerbong
    strcpy(data_gerbong, gerbong_kereta[opsi4 - 1]);
    printf("\n");

    do { // do untuk mengulang ketika tersedia adalah false
        do { // do untuk mengulang ketika data kursi kereta pada data_penumpang adalah []
            for (j = 0; j < MAX_TEMPAT_DUDUK; j++) {
                // Jika isi data_kereta ada yang sama dengan isi kereta pada data_penumpang
                if (strcmp(data_kereta, data_penumpang[j][4]) == 0) {
                    i = 0;
                    // Jika isi data_gerbong sama dengan isi gerbong pada data_penumpang
                    if (strcmp(data_gerbong, data_penumpang[j][6]) == 0) {
                        while (i < MAX_TEMPAT_DUDUK) {
                            // Jika ada tempat duduk yang sama dengan tempat duduk data_penumpang pada kereta dan gerbong itu
                            if (strcmp(tempatduduk_kereta[i], data_penumpang[j][7]) == 0) {
                                // isi tempatduduk_kereta tersebut akan diganti dengan []
                                strcpy(tempatduduk_kereta[i], "[]");
                            }
                            i++;
                        }
                    }
                }
            }

            for (j = 0; j < MAX_TEMPAT_DUDUK; j++) {
                printf("%s   ", tempatduduk_kereta[j]);
                if (j == 4) {
                    printf("\n");
                }
            }

            // nilai data_kereta dimasukkan ke data_penumpang di baris jumlah dan index 4
            strcpy(data_penumpang[jumlah][4], data_kereta);
            // nilai data_gerbong dimasukkan ke data_penumpang di baris jumlah dan index 6
            strcpy(data_penumpang[jumlah][6], data_gerbong);
            // nilai 0 dimasukkan ke data_penumpang di baris jumlah dan index 12
            strcpy(data_penumpang[jumlah][12], "0");

            // Input tempat duduk
            printf("\nPilih Tempat Duduk: ");
            scanf("%s", data_penumpang[jumlah][7]);

            for (j = 0; j < MAX_TEMPAT_DUDUK; j++) {
                // jika input tempat duduk sama dengan tempat duduk kereta yang ada
                // maka tersedia dibuat true agar dapat meneruskan program
                if (strcmp(data_penumpang[jumlah][7], tempatduduk_kereta[j]) == 0) {
                    tersedia = true;
                }
            }

            // Cetak Peringatan jika tersedia adalah false
            if (!tersedia) {
                printf("\n=== Tempat duduk tidak tersedia ===\n");
            }
            // Cetak Peringatan jika nilai input tempat duduk adalah []
            if (strcmp(data_penumpang[jumlah][7], "[]") == 0) {
                printf("\n=== Tempat duduk sudah dibooking ===\n");
            }
        } while (strcmp(data_penumpang[jumlah][7], "[]") == 0);
    } while (!tersedia);
}

void pembayaran(int inputan)
{
    // data_penumpang baris inputan di index 12 adalah status pembayaran
    // cetak peringatan jika status pembayaran adalah 1
    if (strcmp(data_penumpang[inputan][12], "1") == 0)
    {
        printf("\nTiket Penumpang ini sudah terbayar\n");
    }
    else
    {
        // total bernilai harga tiket yang diconvert menjadi integer
        int total = atoi(data_penumpang[inputan][8]);
        int uang, pembayaran = 0;
        
        printf("Atas Nama    : %s\n", data_penumpang[inputan][0]);
        printf("Kode Kereta  : %s\n", data_penumpang[inputan][9]);
        printf("Total        : Rp. %d\n\n", total);
        
        do
        {
            // Input uang
            printf("Jumlah uang untuk pembayaran :\n===> ");
            scanf("%d", &uang);
            
            // nilai uang ditambah ke pembayaran
            pembayaran += uang;
            
            // cetak uang kekurangan dan peringatan jika pembayaran kurang dari total
            if (pembayaran < total)
            {
                printf("\nRp. %d\n", total - pembayaran);
                printf("Saldo kurang, silahkan bayar kekurangan\n");
            }
            else
            {
                // mengatur status pembayaran menjadi 1 dan cetak berhasil jika pembayaran pas/lebih dari total
                strcpy(data_penumpang[inputan][12], "1");
                printf("\nPembayaran Berhasil, Silahkan Cetak Tiket\n");
            }
        } while (pembayaran < total);
    }
}

// Prosedur untuk menampilkan riwayat pemesanan sesuai dengan inputan user
void riwayat(int inputan) {
    char bayar[20];
    // mengatur bayar menjadi Belum Terbayar jika status pembayaran adalah 0
    if (strcmp(data_penumpang[inputan][12], "0") == 0) {
        strcpy(bayar, "Belum Terbayar");
    } else if (strcmp(data_penumpang[inputan][12], "1") == 0) {
        strcpy(bayar, "Sudah Terbayar");
    }
    // Cetak seluruh data penumpang
    printf("\nNama Lengkap         : %s", data_penumpang[inputan][0]);
    printf("\nTanggal Lahir        : %s", data_penumpang[inputan][1]);
    printf("\nKode Kelas Kereta    : %s", data_penumpang[inputan][9]);
    printf("\nKota Pemberangkatan  : %s", data_penumpang[inputan][2]);
    printf("\nKota Tujuan          : %s", data_penumpang[inputan][3]);
    printf("\nKursi Kereta         : %s", data_penumpang[inputan][7]);
    printf("\n\t\tKereta Api            : %s", data_penumpang[inputan][4]);
    printf("\nGerbong Kereta Api   : %s", data_penumpang[inputan][6]);
    printf("\n\t\tKelas Kereta          : %s", data_penumpang[inputan][5]);
    printf("\nJam Berangkat Kereta : %s", data_penumpang[inputan][11]);
    printf("\n\t\tTanggal Keberangkatan : %s", data_penumpang[inputan][10]);
    printf("\nHarga Tiket          : %s", data_penumpang[inputan][8]);
    printf("\n\t\tStatus Pembayaran     : %s\n", bayar);
}

// Prosedur untuk mencetak tiket kereta sesuai dengan inputan user
void tiket(int inputan) {
    // Cetak peringatan jika status pembayaran adalah 0
    if (strcmp(data_penumpang[inputan][12], "0") == 0) {
        printf("\n\n=== Silahkan Bayar Terlebih dahulu untuk Mencetak ===\n\n");
    } else if (strcmp(data_penumpang[inputan][12], "1") == 0) { // Cetak Tiket Kereta jika status pembayaran adalah 1
        printf("\nCETAK TIKET KERETA API\n");
        printf("=======================================================\n");
        printf("||                                                   ||");
        printf("\n||    NAMA LENGKAP        : %s", data_penumpang[inputan][0]);
        printf("\n||");
        printf("\n||    KODE IDENTITAS      : %s0000", data_penumpang[inputan][1]);
        printf("\n||");
        printf("\n||    KOTA KEBERANGKATAN  : %s", data_penumpang[inputan][2]);
        printf("\n||");
        printf("\n||    KOTA TUJUAN         : %s", data_penumpang[inputan][3]);
        printf("\n||");
        printf("\n||    GERBONG KERETA API  : \tKELAS KERETA API :");
        printf("\n||    %s\t\t\t\t%s", data_penumpang[inputan][6], data_penumpang[inputan][5]);
        printf("\n||");
        printf("\n||    KURSI KERETA :\t\tKERETA API :");
        printf("\n||    %s\t\t\t%s", data_penumpang[inputan][7], data_penumpang[inputan][4]);
        printf("\n||                                                   ||");
        printf("\n=======================================================\n");
    }
}

int main() {
    loading(100);
    int inputan;
    char opsi_ulang[4];

    do { // do untuk mengulang jika nilai opsi ulang adalah yes atau y
        printf("\n========== Kereta SiLambat =========\n");
        printf("============ Menu Kereta ===========\n");
        printf("|                                  |\n");
        printf("| (1) => Pesan Tiket Sekarang      |\n");
        printf("| (2) => Lihat Harga Tiket         |\n");
        printf("| (3) => Lihat Jam Keberangkatan   |\n");
        printf("| (4) => Riwayat Pesanan           |\n");
        printf("| (5) => Pembayaran Tiket          |\n");
        printf("| (6) => Cetak Tiket               |\n");
        printf("| (7) => Keluar                    |\n");
        printf("|                                  |\n");
        printf("====================================\n");
        printf("Pilih Opsi Menu: ");
        scanf("%d", &inputan); // Input pilihan Menu

        switch (inputan) {
            case 1: {
                printf("\n=============== Isi Data Diri ================\n");
                printf("========= Tiket dapat dipesan maks 5 =========\n\n");

                // pesan tiket akan stop jika sudah memesan 5 kali
                if (jumlah >= MAX_PENUMPANG) {
                    printf("==== Pemesanan Tiket sudah mencapai batas ====\n");
                    break;
                }

                // Input nama
                printf("Nama Lengkap: ");
                getchar();  // Membersihkan newline dari input sebelumnya
                fgets(data_penumpang[jumlah][0], sizeof(data_penumpang[jumlah][0]), stdin);
                data_penumpang[jumlah][0][strcspn(data_penumpang[jumlah][0], "\n")] = 0; // Menghapus newline

                // Input tanggal lahir
                printf("Tanggal Lahir (ddmmyyyy): ");
                scanf("%s", data_penumpang[jumlah][1]);

                pendaftaran_tujuan();   // memanggil prosedur pendaftaran_tujuan
                pendaftaran_kereta();   // memanggil prosedur pendaftaran_kereta
                int kelas = kelas_kereta(); // kelas bernilai hasil kembalian fungsi kelas_kereta
                int opsi1 = 1;  // Ini hanya contoh, sesuaikan sesuai kebutuhan
                int opsi2 = 2;  // Ini hanya contoh, sesuaikan sesuai kebutuhan
                harga_tiket(kelas, opsi1, opsi2, data_penumpang, jumlah);  // memanggil prosedur harga_tiket dengan nilai dari kelas
                tanggal_pemberangkatan(); // memanggil prosedur tanggal_pemberangkatan
                jumlah++;                // jumlah bertambah 1 setiap melakukan pemesanan tiket
                break;
            }
            case 2:
                printf("\n========= Harga Tiket =========\n");
                cek_harga();  // memanggil prosedur cek_harga
                break;
            case 3:
                printf("\n====== Jam Keberangkatan ======\n");
                cek_jam();  // memanggil prosedur cek_jam
                break;
            case 4:
                printf("\n========== Riwayat Pesanan ==========\n");
                if (jumlah == 0) {
                    printf("\nData Penumpang kosong / Tidak tersedia\n");
                    break;
                }
                for (int i = 0; i < jumlah; i++) {
                    printf("  %d) %s - %s\n", i + 1, data_penumpang[i][0], data_penumpang[i][4]);
                }
                printf("Pilih Riwayat Pemesanan: ");
                scanf("%d", &inputan);
                riwayat(inputan - 1); // memanggil prosedur riwayat
                break;
            case 5:
                printf("\n========= Pembayaran Tiket =========\n");
                if (jumlah == 0) {
                    printf("\nData Penumpang kosong / Tidak tersedia\n");
                    break;
                }
                for (int i = 0; i < jumlah; i++) {
                    printf("  %d) %s - %s\n", i + 1, data_penumpang[i][0], data_penumpang[i][9]);
                }
                printf("Pilih Tiket yang akan dibayar: ");
                scanf("%d", &inputan);
                pembayaran(inputan - 1); // memanggil prosedur pembayaran
                break;
            case 6:
                printf("\n======== Cetak Tiket Kereta ========\n");
                if (jumlah == 0) {
                    printf("\nData Penumpang kosong / Tidak tersedia\n");
                    break;
                }
                for (int i = 0; i < jumlah; i++) {
                    printf("  %d) %s - %s\n", i + 1, data_penumpang[i][0], data_penumpang[i][4]);
                }
                printf("Pilih Tiket yang akan dicetak: ");
                scanf("%d", &inputan);
                tiket(inputan - 1); // memanggil prosedur tiket
                break;
            case 7:
                printf("\nTerimakasih sudah menggunakan jasa kami\n");
                exit(0);
                break;
            default:
                printf("\n===== Opsi ini Tidak Tersedia =====\n");
                break;
        }

        printf("\nKembali ke menu utama?\n(yes untuk kembali dan no untuk keluar)\n===> ");
        scanf("%s", opsi_ulang);
        
        // Jika input adalah yes maka menu akan mengulang
        if (strcmp(opsi_ulang, "yes") == 0 || strcmp(opsi_ulang, "y") == 0) {
            system("cls");  // Bersihkan layar terminal
        }
    } while (strcmp(opsi_ulang, "yes") == 0 || strcmp(opsi_ulang, "y") == 0);
    
    printf("\nTerimakasih sudah menggunakan jasa kami\n");
    return 0;
}