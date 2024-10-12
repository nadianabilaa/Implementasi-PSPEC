////S1-IF-10-06
//Ilma Kurnia 2211102162
//Nadia Nabila 2211102174
//Nida Gina Iswardhani 2211102306
//Rahma Ayu Riyantini 2211102313

#include <stdio.h>
#include <string.h>

// Fungsi untuk menampilkan header restoran
void header() {
    // Menampilkan nama restoran
    printf("=============== RESTORAN KELUARGA BAHAGIA =================\n");
    printf("================ ANDA KENYANG, KAMI SENANG ================\n");
}

// Fungsi untuk menampilkan menu makanan
void menu_makanan() {
    // Menampilkan menu makanan
    printf("===========================================================\n");
    printf("|          MENU MAKANAN         |          HARGA          |\n");
    printf("-----------------------------------------------------------\n");
    printf("|   1. AYAM BAKAR               |       RP. 15.000        |\n");
    printf("|   2. AYAM GORENG              |       RP. 18.000        |\n");
    printf("|   3. AYAM KECAP               |       RP. 10.000        |\n");
    printf("|   4. AYAM RICA-RICA           |       RP. 12.000        |\n");
    printf("|   5. AYAM MENTEGA             |       RP. 11.000        |\n");
    printf(" ------------------------------------------------------- \n\n");
}

// Fungsi untuk menampilkan menu minuman
void menu_minuman() {
    // Menampilkan menu minuman
    printf("===========================================================\n");
    printf("|          MENU MINUMAN         |          HARGA          |\n");
    printf("-----------------------------------------------------------\n");
    printf("|   1. ES TEH                   |       RP.  5.000        |\n");
    printf("|   2. ES JERUK                 |       RP.  8.000        |\n");
    printf("|   3. ES KELAPA                |       RP. 10.000        |\n");
    printf("|   4. TEH TAWAR                |       RP.  2.000        |\n");
    printf("|   5. TEH HANGAT               |       RP.  1.000        |\n");
    printf(" ------------------------------------------------------- \n\n");
}

// Fungsi untuk menampilkan menu paket
void menu_paket() {
    // Menampilkan menu paket
    printf("===========================================================\n");
    printf("|          MENU PAKET HEMAT     |          HARGA          |\n");
    printf("-----------------------------------------------------------\n");
    printf("|   1. AYAM GORENG + ES TEH     |       RP.  5.000        |\n");
    printf("|   2. AYAM BAKAR + ES JERUK    |       RP.  8.000        |\n");
    printf("|   3. AYAM RICA-RICA + ES KELAPA |       RP. 10.000      |\n");
    printf("|   4. AYAM MENTEGA + TEH TAWAR  |       RP.  2.000       |\n");
    printf("|   5. AYAM KECAP + TEH HANGAT   |       RP.  1.000       |\n");
    printf(" ------------------------------------------------------- \n\n");
}

int main() {
    // Deklarasi variabel
    float diskon, diskon1, total, total1, hargajadi, hargajadi1;
    char kembali; // Untuk mengecek apakah pengguna ingin memesan lagi
    char nama[50]; // Untuk menyimpan nama pengguna
    int pilih, jumlah, bayar, kembalian, jumlah1, jumlah2, pilih1, pilih2, angka, kembalian1;

    // Array untuk menu
    char *menu1[5] = {"AYAM BAKAR", "AYAM GORENG", "AYAM KECAP", "AYAM RICA-RICA", "AYAM MENTEGA"};
    char *menu2[5] = {"ES TEH", "ES JERUK", "ES KELAPA", "TEH TAWAR", "TEH HANGAT"};
    char *menu3[5] = {"AYAM GORENG + ES TEH", "AYAM BAKAR + ES JERUK", "AYAM RICA-RICA + ES KELAPA", "AYAM MENTEGA + TEH TAWAR", "AYAM KECAP + TEH HANGAT"};

    // Array untuk harga
    int harga1[5] = {15000, 18000, 10000, 12000, 11000};
    int harga2[5] = {5000, 8000, 10000, 2000, 1000};
    int harga3[5] = {5000, 8000, 10000, 2000, 1000};

    // Variabel untuk indeks menu
    int i = 0, j = 0, k = 0;

    // Loop utama untuk memesan
    do {
        header(); // Tampilkan header
        printf("\nMasukkan nama anda : "); // Meminta nama pengguna
        scanf("%s", nama); // Menyimpan nama pengguna
        printf("Pilihan menu yang tersedia....\n\n");
        printf("Silakan Pilih....\n\n");
        printf("1. Menu Dine In\n"); // Menu Dine In
        printf("2. Menu paket\n\n"); // Menu paket
        printf("Pilihan Anda : "); // Meminta pilihan menu
        scanf("%d", &angka); // Menyimpan pilihan menu

        // Jika pengguna memilih menu Dine In
        if (angka == 1) {
            menu_makanan(); // Tampilkan menu makanan
            printf("Silahkan Pilih Makanan Anda : "); // Meminta pilihan makanan
            scanf("%d", &pilih); // Menyimpan pilihan makanan

            // Jika pilihan makanan valid
            if (pilih <= 5) {
                printf("Jumlah Makanan yang Dibeli : "); // Meminta jumlah makanan
                scanf("%d", &jumlah); // Menyimpan jumlah makanan
            } else {
                printf("PILIHAN YANG ANDA MASUKAN TIDAK TERSEDIA\n\n"); // Menampilkan pesan error
            }

            menu_minuman(); // Tampilkan menu minuman
            printf("Silahkan Pilih Minuman Anda : "); // Meminta pilihan minuman
            scanf("%d", &pilih1); // Menyimpan pilihan minuman

            // Jika pilihan minuman valid
            if (pilih1 <= 5) {
                printf("Jumlah Minuman yang Dibeli : "); // Meminta jumlah minuman
                scanf("%d", &jumlah1); // Menyimpan jumlah minuman
            } else {
                printf("PILIHAN YANG ANDA MASUKAN TIDAK TERSEDIA\n\n"); // Menampilkan pesan error
            }
        } else if (angka == 2) { // Jika pengguna memilih menu paket
            menu_paket(); // Tampilkan menu paket
            printf("Silahkan Pilih Paket Anda : "); // Meminta pilihan paket
            scanf("%d", &pilih2); // Menyimpan pilihan paket

            // Jika pilihan paket valid
            if (pilih2 <= 5) {
                printf("Jumlah Paket yang Dibeli : "); // Meminta jumlah paket
                scanf("%d", &jumlah2); // Menyimpan jumlah paket
            } else {
                printf("PILIHAN YANG ANDA MASUKAN TIDAK TERSEDIA\n\n"); // Menampilkan pesan error
            }
        }

        // Menentukan indeks makanan yang dipilih
        switch (pilih) {
            case 1: i = 0; break;
            case 2: i = 1; break;
            case 3: i = 2; break;
            case 4: i = 3; break;
            case 5: i = 4; break;
        }

        // Menentukan indeks minuman yang dipilih
        switch (pilih1) {
            case 1: j = 0; break;
            case 2: j = 1; break;
            case 3: j = 2; break;
            case 4: j = 3; break;
            case 5: j = 4; break;
        }

        // Menentukan indeks paket yang dipilih
        switch (pilih2) {
            case 1: k = 0; break;
            case 2: k = 1; break;
            case 3: k = 2; break;
            case 4: k = 3; break;
            case 5: k = 4; break;
        }

        // Menghitung total harga untuk menu Dine In
        total = jumlah * harga1[i] + jumlah1 * harga2[j];
        // Menghitung total harga untuk paket
        total1 = jumlah2 * harga3[k];

        // Menghitung diskon untuk menu Dine In
        if (total >= 75000) {
            diskon = total * 5 / 100; // Diskon 5%
            hargajadi = total - diskon; // Harga setelah diskon
        } else if (total >= 120000) {
            diskon = total * 15 / 100; // Diskon 15%
            hargajadi = total - diskon; // Harga setelah diskon
        } else {
            diskon = 0; // Tidak ada diskon
            hargajadi = total; // Harga tanpa diskon
        }

        // Menampilkan hasil pemesanan untuk menu Dine In
        if (angka == 1) {
            printf("==================================================\n");
            printf("============== RESTORAN KELUARGA BAHAGIA ============\n");
            printf("==================================================\n");
            printf("\tNama Pemesan                      : %s\n", nama); // Menampilkan nama pemesan
            printf("\tMenu Yang Dipesan                 : %s dan %s\n", menu1[pilih - 1], menu2[pilih1 - 1]); // Menampilkan menu yang dipesan
            printf("\tJumlah Menu yang dipesan          : %d dan %d\n", jumlah, jumlah1); // Menampilkan jumlah yang dipesan
            printf("\tHarga Menu yang dipesan           : %d * %d + %d * %d\n", harga1[i], jumlah, harga2[j], jumlah1); // Menampilkan rincian harga
            printf("\tTotal Pembayaran                  : Rp. %.2f\n", total); // Menampilkan total pembayaran
            printf("\tAnda mendapatkan potongan sebesar : Rp. %.2f\n", diskon); // Menampilkan diskon
            printf("\tHarga Setelah potongan/diskon     : Rp. %.2f\n", hargajadi); // Menampilkan harga setelah diskon
            printf("==================================================\n");
            printf("Silahkan bayar disini     : Rp. "); // Meminta pengguna untuk membayar
            scanf("%d", &bayar); // Menyimpan jumlah yang dibayar
            kembalian = bayar - hargajadi; // Menghitung kembalian
            printf("Uang yang anda bayar \t\t\t Rp. %d\n", bayar); // Menampilkan uang yang dibayar
            printf("Uang kembalian \t\t\t\t Rp. %d\n", kembalian); // Menampilkan kembalian
            printf("##################################################\n");
        } else if (angka == 2) { // Jika pengguna memilih paket
            // Menghitung diskon untuk paket
            if (total1 >= 75000) {
                diskon1 = total1 * 5 / 100; // Diskon 5%
                hargajadi1 = total1 - diskon1; // Harga setelah diskon
            } else if (total1 >= 120000) {
                diskon1 = total1 * 15 / 100; // Diskon 15%
                hargajadi1 = total1 - diskon1; // Harga setelah diskon
            } else {
                diskon1 = 0; // Tidak ada diskon
                hargajadi1 = total1; // Harga tanpa diskon
            }

            // Menampilkan hasil pemesanan untuk paket
            printf("==================================================\n");
            printf("============== RESTORAN KELUARGA BAHAGIA ============\n");
            printf("==================================================\n");
            printf("\tNama Pemesan                   : %s\n", nama); // Menampilkan nama pemesan
            printf("\tMenu Yang Dipesan              : %s\n", menu3[pilih2 - 1]); // Menampilkan menu paket yang dipesan
            printf("\tJumlah Menu yang dipesan       : %d\n", jumlah2); // Menampilkan jumlah paket yang dipesan
            printf("\tHarga Menu yang dipesan        : %d * %d\n", harga3[k], jumlah2); // Menampilkan rincian harga paket
            printf("\tTotal Pembayaran               : Rp. %.2f\n", total1); // Menampilkan total pembayaran
            printf("\tAnda mendapatkan potongan sebesar : Rp. %.2f\n", diskon1); // Menampilkan diskon
            printf("\tHarga Setelah potongan/diskon     : Rp. %.2f\n", hargajadi1); // Menampilkan harga setelah diskon
            printf("==================================================\n");
            printf("Silahkan bayar disini     : Rp. "); // Meminta pengguna untuk membayar
            scanf("%d", &bayar); // Menyimpan jumlah yang dibayar
            kembalian1 = bayar - hargajadi1; // Menghitung kembalian
            printf("Uang yang anda bayar \t\t\t Rp. %d\n", bayar); // Menampilkan uang yang dibayar
            printf("Uang kembalian \t\t\t\t Rp. %d\n", kembalian1); // Menampilkan kembalian
            printf("##################################################\n");
        }

        // Menanyakan kepada pengguna apakah ingin memesan lagi
        printf("Apakah anda ingin memesan lagi? (Y/T) = ");
        scanf(" %c", &kembali); // Menyimpan jawaban pengguna
        printf("\n");

    } while (kembali == 'Y' || kembali == 'y'); // Jika pengguna menjawab 'Y' atau 'y', ulangi pemesanan

    // Menampilkan pesan terima kasih
    printf("Terima kasih telah memesan makanan di RESTORAN KELUARGA BAHAGIA\n");
    printf("Selamat Menikmati\n");

    return 0; // Mengembalikan nilai 0 sebagai tanda program selesai
}
