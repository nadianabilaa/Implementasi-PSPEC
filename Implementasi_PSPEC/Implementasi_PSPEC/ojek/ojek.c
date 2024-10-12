//S1-IF-10-06
//Ilma Kurnia 2211102162
//Nadia Nabila 2211102174
//Nida Gina Iswardhani 2211102306
//Rahma Ayu Riyantini 2211102313

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Variabel global untuk menyimpan informasi pengguna
char nama[MAX_LEN], alamat[MAX_LEN], antr[MAX_LEN], wktt[MAX_LEN], wktp[MAX_LEN], x[MAX_LEN];
char jkelamin[MAX_LEN], Nama[MAX_LEN], Jenis_kelamin[MAX_LEN];
int ido, idp;
int tujuan, ID, Umur;
char lagi, pilihanJK;
int pilihan, melakukanHalLain;

// Precondition: Pengguna siap keluar dari program
void keluar() {
    printf("\n");
    printf("Terima kasih banyak atas kunjungan Anda\n");
    printf("Datang lagi yaa...\n");
}

// Precondition: Data driver perlu ditampilkan
void driver() {
    printf("   -------------------------------------------------\n");
    printf("   NO | ID |  Nama Driver | Umur |  Jenis Kelamin  |\n");
    printf("   -------------------------------------------------\n");
    printf("   1  |001 | Jumadi       |  41  | Laki-laki       |\n");
    printf("   2  |002 | Haryanto     |  45  | Laki-laki       |\n");
    printf("   3  |003 | Agus         |  30  | Laki-laki       |\n");
    printf("   4  |004 | Adi          |  44  | Laki-laki       |\n");
    printf("   5  |005 | Adit         |  27  | Laki-laki       |\n");
    printf("   -------------------------------------------------\n");
}

// Precondition: Pengguna memasukkan informasi transportasi
void pengantaran() {
    do {
        printf("*****************************************\n");
        printf("                 PROGRAM C               \n");
        printf("                 OJEK ONLINE             \n");
        printf("*****************************************\n");
        printf("\n");

        // Structured English Construct: Pengguna memberikan data mereka
        printf("Silahkan masukkan data anda : "); 
        fgets(x, sizeof(x), stdin); // Menggunakan fgets untuk membaca string
        printf("\n");

        // Precondition: Pengguna harus memasukkan nama mereka
        printf("   Nama               = "); 
        fgets(nama, sizeof(nama), stdin); 
        nama[strcspn(nama, "\n")] = 0; // Menghapus newline

        // Precondition: Pengguna harus memasukkan ID penumpang
        printf("   ID penumpang       = "); 
        scanf("%d", &idp);

        // Precondition: Pengguna harus memilih jenis kelamin mereka
        printf("   Jenis Kelamin[L/P] = "); 
        scanf(" %c", &pilihanJK); // Spasi sebelum %c untuk mengabaikan newline
        switch(pilihanJK) {
            case 'L':
                strcpy(jkelamin, "Laki - Laki");
                break;
            case 'P':
                strcpy(jkelamin, "Perempuan");
                break;
        }

        // Precondition: Pengguna harus memilih driver
        printf("Silahkan pilih driver anda : \n");
        driver();
        // Structured English Construct: Pengguna memilih driver dengan nomor
        printf("Masukkan pilihan anda [1/2/3/4/5] = "); 
        scanf("%d", &ido);
        printf("\n");

        // Pre/Postconditions: Menetapkan informasi driver berdasarkan pilihan pengguna
        switch(ido) {
            case 1:
                ID = 1;
                strcpy(Nama, "Jumaidi");
                Umur = 41;
                strcpy(Jenis_kelamin, "Laki-laki");
                break;
            case 2:
                ID = 2;
                strcpy(Nama, "Haryanto");
                Umur = 45;
                strcpy(Jenis_kelamin, "Laki-laki");
                break;
            case 3:
                ID = 3;
                strcpy(Nama, "Agus");
                Umur = 30;
                strcpy(Jenis_kelamin, "Laki-laki");
                break;
            case 4:
                ID = 4;
                strcpy(Nama, "Adi");
                Umur = 44;
                strcpy(Jenis_kelamin, "Laki-laki");
                break;
            case 5:
                ID = 5;
                strcpy(Nama, "Adit");
                Umur = 27;
                strcpy(Jenis_kelamin, "Laki-laki");
                break;
            default:
                printf("Menu tidak tersedia\n");
        }

        // Precondition: Pengguna harus memasukkan informasi pengantaran
        printf("Silahkan masukkan informasi pengantaran : "); 
        fgets(x, sizeof(x), stdin); 
        printf("\n");

        // Precondition: Pengguna harus memasukkan alamat pickup
        printf("   Masukkan Alamat Pickup = "); 
        fgets(alamat, sizeof(alamat), stdin);
        alamat[strcspn(alamat, "\n")] = 0; // Menghapus newline

        // Precondition: Pengguna harus memasukkan alamat antar
        printf("   Masukkan Alamat Antar  = "); 
        fgets(antr, sizeof(antr), stdin);
        antr[strcspn(antr, "\n")] = 0; // Menghapus newline

        // Precondition: Pengguna harus memasukkan waktu pickup
        printf("   Masukkan Waktu Pickup  = "); 
        fgets(wktp, sizeof(wktp), stdin);
        wktp[strcspn(wktp, "\n")] = 0; // Menghapus newline

        // Precondition: Pengguna harus memasukkan waktu tiba
        printf("   Masukkan Waktu Tiba    = "); 
        fgets(wktt, sizeof(wktt), stdin);
        wktt[strcspn(wktt, "\n")] = 0; // Menghapus newline
        printf("\n");

        // Postcondition: Menampilkan ringkasan informasi pengantaran
        printf("   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("               RIWAYAT PENGANTARAN OJEK ONLINE          \n");
        printf("   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("   Informasi Driver        :                            \n");
        printf("       ID Driver             = %d\n", ID);
        printf("       Nama driver           = %s\n", Nama);
        printf("       Umur                  = %d\n", Umur);
        printf("       Jenis Kelamin         = %s\n", Jenis_kelamin);
        printf("                                                        \n");
        printf("   Informasi penumpang     :                            \n");
        printf("       ID penumpang          = %d\n", idp);
        printf("       Nama Penumpang        = %s\n", nama);
        printf("       Jenis Kelamin         = %s\n", jkelamin);
        printf("                                                        \n");
        printf("   Informasi pengantaran   :                            \n");
        printf("       Alamat pickup         = %s\n", alamat);
        printf("       Alamat antar          = %s\n", antr);
        printf("       Waktu pickup          = %s\n", wktp);
        printf("       Waktu tiba            = %s\n", wktt);
        printf("   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("                   Pengantaran selesai                  \n");
        printf("   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n");

        // Structured English Construct: Menanyakan pengguna jika mereka ingin menggunakan layanan lagi
        printf("Ingin menggunakan ojek lagi(y/t): "); 
        scanf(" %c", &lagi);

    } while(lagi == 'y' || lagi == 'Y'); // Postcondition: Loop hingga pengguna memutuskan untuk berhenti
    printf("Terima kasih telah menggunakan ojek online\n");
}

// Precondition: Menampilkan opsi menu utama kepada pengguna
void menu() {
    do {
        printf("*****************************************\n");
        printf("                 PROGRAM C               \n");
        printf("                 OJEK ONLINE             \n");
        printf("*****************************************\n");
        printf("\n");
        printf("1. Data Driver Ojek\n");
        printf("2. Riwayat Pengantaran\n");
        printf("3. Data Riwayat Pengantaran\n");
        printf("0. Keluar\n");
        printf("Apa yang anda butuhkan(0-3) : ");
        scanf("%d", &pilihan);

        // Structured English Construct: Pengguna membuat pilihan dari menu
        switch(pilihan) {
            case 1:
                driver();
                printf("Under construction...\n");
                printf("\n");
                // Postcondition: Menanyakan pengguna jika mereka ingin melakukan hal lain
                printf("Mau melakukan hal lain (y/t) ? ");
                scanf(" %c", &melakukanHalLain);
                if (melakukanHalLain == 't' || melakukanHalLain == 'T') {
                    keluar();
                    pilihan = 0; // Postcondition: Keluar dari menu
                }
                break;
            case 2:
                pengantaran();
                printf("Under construction...\n");
                printf("\n");
                // Postcondition: Menanyakan pengguna jika mereka ingin melakukan hal lain
                printf("Mau melakukan hal lain (y/t) ? ");
                scanf(" %c", &melakukanHalLain);
                if (melakukanHalLain == 't' || melakukanHalLain == 'T') {
                    keluar();
                    pilihan = 0; // Postcondition: Keluar dari menu
                }
            case 3:
                printf("Under construction...\n");
                printf("\n");
                // Postcondition: Menanyakan pengguna jika mereka ingin melakukan hal lain
                printf("Mau melakukan hal lain (y/t) ? ");
                scanf(" %c", &melakukanHalLain);
                if (melakukanHalLain == 't' || melakukanHalLain == 'T') {
                    keluar();
                    pilihan = 0; // Postcondition: Keluar dari menu
                }
                break;
            case 0:
                keluar(); // Postcondition: Mengakhiri program
                break;
            default:
                printf("Mohon maaf pilihan tidak ada...\n");
                printf("\n");
                // Postcondition: Menanyakan pengguna jika mereka ingin melakukan hal lain
                printf("Mau melakukan hal lain (y/t) ? ");
                scanf(" %c", &melakukanHalLain);
                if (melakukanHalLain == 't' || melakukanHalLain == 'T') {
                    keluar();
                    pilihan = 0; // Postcondition: Keluar dari menu
                }
        }
    } while (pilihan != 0); // Postcondition: Mengulangi menu hingga pengguna memilih keluar
}

// Precondition: Memulai program
int main() {
    menu(); // Memanggil fungsi menu untuk menjalankan program
    return 0; // Postcondition: Mengakhiri eksekusi program dengan status 0
}
