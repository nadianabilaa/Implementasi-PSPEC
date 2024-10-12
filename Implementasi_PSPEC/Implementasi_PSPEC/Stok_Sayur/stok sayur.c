//S1-IF-10-06
//Ilma Kurnia 2211102162
//Nadia Nabila 2211102174
//Nida Gina Iswardhani 2211102306
//Rahma Ayu Riyantini 2211102313

#include <stdio.h>
#include <string.h>

// Struktur data untuk produk
struct Produk {
    char nama[50];
    int stok;
};

// Fungsi untuk menampilkan produk
void tampilkanItemProduk(struct Produk produk[], int jumlahProduk) {
    printf("Daftar Produk Tersedia:\n");
    for (int i = 0; i < jumlahProduk; i++) {
        printf("%d. %s - Stok: %d\n", i + 1, produk[i].nama, produk[i].stok);
    }
}

// Fungsi untuk mengedit stok produk
void editStokProduk(struct Produk *produk, int stokBaru) {
    produk->stok = stokBaru;
    printf("Stok %s berhasil diperbarui menjadi %d\n", produk->nama, produk->stok);
}

// Fungsi untuk memproses pesanan
void prosesPesanan(int idPesanan) {
    printf("Pesanan ID %d berhasil diproses.\n", idPesanan);
}

// Fungsi untuk mencetak invoice
void cetakInvoice(int idPesanan, char namaPelanggan[], int totalHarga) {
    printf("Invoice\n");
    printf("ID Pesanan: %d\n", idPesanan);
    printf("Nama Pelanggan: %s\n", namaPelanggan);
    printf("Total Harga: Rp %d\n", totalHarga);
}

int main() {
    struct Produk produk[3] = {
        {"Tomat", 100},
        {"Kentang", 50},
        {"Wortel", 200}
    };
    int pilihan, stokBaru, idPesanan = 12345, totalHarga = 50000;
    char namaPelanggan[] = "Budi";

    do {
        printf("\nMenu:\n");
        printf("1. Tampilkan Produk\n");
        printf("2. Edit Stok Produk\n");
        printf("3. Proses Pesanan\n");
        printf("4. Cetak Invoice\n");
        printf("5. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tampilkanItemProduk(produk, 3);
                break;
            case 2:
                printf("Masukkan stok baru untuk Tomat: ");
                scanf("%d", &stokBaru);
                editStokProduk(&produk[0], stokBaru);
                break;
            case 3:
                prosesPesanan(idPesanan);
                break;
            case 4:
                cetakInvoice(idPesanan, namaPelanggan, totalHarga);
                break;
            case 5:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Opsi tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 5);

    return 0;
}
