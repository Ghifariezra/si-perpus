/*
    Final Project - Sistem Informasi - Manajemen Perpustakaan
    File Name: main.cpp

    Kelompok:
        •⁠ Fatimah (4524210039)
        •⁠ Maghfiroh Lisabiliana (4524210040)
        •⁠ Ghifari Ezra Ramadhan (4524210041)

    Pembagian Materi:
        Maghfiroh:
            •⁠  ⁠Pointer
            •⁠  ⁠⁠Stack
        Fatimah:
            •⁠  ⁠⁠Sorting
            •⁠  ⁠⁠Queue
        Fatimah & Maghfiroh:
            •⁠  ⁠⁠Searching
        Ghifari:
            •⁠  ⁠⁠Tree
            •⁠  ⁠⁠Graph

    Materi:
        •⁠  ⁠Pointer
        •⁠  ⁠⁠Stack
        •⁠  ⁠⁠Queue
        •⁠  ⁠⁠Sorting
        •⁠  ⁠⁠Searching
        •⁠  ⁠⁠Tree
        •⁠  ⁠⁠Graph
*/

/*
    Final Project - Sistem Informasi - Manajemen Perpustakaan
    File Name: main.cpp

    Kelompok:
        • Fatimah (4524210039)
        • Maghfiroh Lisabiliana (4524210040)
        • Ghifari Ezra Ramadhan (4524210041)

    Pembagian Materi:
        Maghfiroh:
            • Pointer
            • Stack
        Fatimah:
            • Sorting
            • Queue
        Fatimah & Maghfiroh:
            • Searching
        Ghifari:
            • Tree
            • Graph

    Materi:
        • Pointer
        • Stack
        • Queue
        • Sorting
        • Searching
        • Tree
        • Graph
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Queue dalam peminjaman buku
typedef struct Node 
{
    string Fnama;
    string FjudulBuku; 
    Node* Fnext; 
} Node;

typedef struct Queue 
{
    Node* FFirst;
    Node* FLast;
} Queue;

void initQueue(Queue &Q) 
{
    Q.FFirst = NULL;
    Q.FLast = NULL;
}

void tambahPeminjam(Queue &Q, string Fnama, string FjudulBuku) 
{
    Node* Fbaru = new Node{Fnama, FjudulBuku, NULL};
    if (Q.FFirst == NULL) 
    {
        Q.FFirst = Fbaru;
        Q.FLast = Fbaru;
    } 
    else 
    {
        Q.FLast->Fnext = Fbaru;
        Q.FLast = Fbaru;
    }
}

void lihatAntrian(Queue Q) 
{
    Node* bantu = Q.FFirst;
    if (bantu == NULL) 
    {
        cout << "\nAntrian kosong.\n";
    } 
    else 
    {
        cout << "\nDaftar Antrian Peminjam:\n";
        while (bantu != NULL) 
        {
            cout << "- " << bantu->Fnama << " (Buku: " << bantu->FjudulBuku << ")\n";
            bantu = bantu->Fnext;
        }
    }
}

void daftarBuku() {
    const int MAX_STACK = 100;
    struct Buku {
        string judul, penulis, genre, status;
        int stock;
    };

    Buku stackBuku[MAX_STACK];
    int top = -1;

    // input 3 data buku ke stack (STACK)
    stackBuku[++top] = {"The Psychology of Money", "Morgan Housel", "Psikologi Finansial", "Tersedia", 2};
    stackBuku[++top] = {"Laut Bercerita", "Leila S. Chudori", "Novel Sosial", "Tersedia", 5};
    stackBuku[++top] = {"Dilan 1990", "Pidi Baiq", "Romantis", "Tidak Tersedia", 0};
    stackBuku[++top] = {"Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "Fantasi", "Tersedia", 3};
    stackBuku[++top] = {"Danur", "Risa Saraswati", "Horor", "Tersedia", 1};

    // input judul untuk dicari (SEARCHING)
    string cariJudul;
    cout << "Masukkan judul buku yang ingin dicari: ";
    getline(cin, cariJudul);

    bool ditemukan = false;
    for (int i = 0; i <= top; i++) {
        if (stackBuku[i].judul == cariJudul) {
            cout << "\n====== DETAIL BUKU ======\n";
            cout << "Judul   : " << stackBuku[i].judul << endl;
            cout << "Penulis : " << stackBuku[i].penulis << endl;
            cout << "Genre   : " << stackBuku[i].genre << endl;
            cout << "Status  : " << stackBuku[i].status << endl;
            cout << "Stock   : " << stackBuku[i].stock << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "\nBuku tidak tersedia.\n";
    }
}

void cariBuku();

void pinjamBuku()
{
    Queue Q;
    initQueue(Q);

    int pilihan;
    string nama, buku;

    do 
    {
        cout << endl;
        cout << "=================================" << endl;
        cout << "======== Peminjaman Buku ========" << endl;
        cout << "1. Tambah Peminjam" << endl;
        cout << "2. Lihat Antrian" << endl;
        cout << "3. Kembali ke Menu Utama" << endl;
        cout << "=================================" << endl;

        cout << "Pilih opsi: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) 
        {
            case 1:
                cout  << endl;
                cout << "Masukkan nama peminjam: ";
                getline(cin, nama);
                cout << "Masukkan judul buku yang dipinjam: ";
                getline(cin, buku);    
                cout << endl;
                tambahPeminjam(Q, nama, buku);
                cout << "Peminjam berhasil ditambahkan ke antrian:)" << endl;
                break;
            case 2:
                lihatAntrian(Q);
                break;
        }
    } 
    while (pilihan != 3); 
}

void pengembalianBuku() {
    const int MAX_STACK = 100;

    struct Pengembalian {
        string nama;
        string judul;
        string tanggal;
    };
    // Stack 
    Pengembalian stackKembali[MAX_STACK];
    int top = -1;

    int pilihan;
    do {
        cout << "=================================" << endl;
        cout << "======= Pengembalian Buku =======" << endl;
        cout << "1. Tambah Data Pengembalian"       << endl;
        cout << "2. Lihat Semua Pengembalian"       << endl;
        cout << "3. Cari Pengembalian"              << endl;
        cout << "4. Kembali ke Menu Utama"          << endl;
        cout << "=================================" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: {
                if (top >= MAX_STACK - 1) {
                    cout << "Stack penuh. Tidak bisa menambah data lagi.\n";
                    break;
                }

                Pengembalian data;
                cout << "\nMasukkan nama pengembali : ";
                getline(cin, data.nama);
                cout << "Masukkan judul buku      : ";
                getline(cin, data.judul);
                cout << "Masukkan tanggal kembali : ";
                getline(cin, data.tanggal);

                stackKembali[++top] = data;
                cout << "\nData pengembalian berhasil ditambahkan!\n";
                break;
            }
            case 2: {
                if (top == -1) {
                    cout << "\nBelum ada data pengembalian.\n";
                } else {
                    cout << "\n===== Daftar Pengembalian Buku =====\n";
                    for (int i = top; i >= 0; i--) {
                        cout << "- Nama     : " << stackKembali[i].nama << endl;
                        cout << "  Judul    : " << stackKembali[i].judul << endl;
                        cout << "  Tanggal  : " << stackKembali[i].tanggal << endl;
                        cout << "-----------------------------------\n";
                    }
                }
                break;
            }
            case 3: {
                // Searching
                if (top == -1) {
                    cout << "\nTidak ada data pengembalian.\n";
                    break;
                }

                string cariJudul;
                cout << "\nMasukkan judul buku yang ingin dicari: ";
                getline(cin, cariJudul);

                bool ketemu = false;
                for (int i = 0; i <= top; i++) {
                    if (stackKembali[i].judul == cariJudul) {
                        cout << "\n== Ditemukan ==\n";
                        cout << "Nama     : " << stackKembali[i].nama << endl;
                        cout << "Judul    : " << stackKembali[i].judul << endl;
                        cout << "Tanggal  : " << stackKembali[i].tanggal << endl;
                        ketemu = true;
                        break;
                    }
                }

                if (!ketemu) {
                    cout << "\nData pengembalian tidak ditemukan.\n";
                }

                break;
            }
            default:
                cout << "Opsi tidak valid.\n";
        }

    } while (pilihan != 4);
}

void rekomendasiBuku();
void sortBuku();
void test();
void B();
void A();
 
int main() 
{
    int pilihan;
    do {
        cout << "\n=============================================\n";
        cout << "         SELAMAT DATANG DI PERPUSTAKAAN       \n";
        cout << "=============================================\n";
        cout << "| 1. Daftar & Cari Buku                      |\n";
        cout << "| 2. Peminjaman Buku                         |\n";
        cout << "| 3. Pengembalian Buku                       |\n";
        cout << "| 4. Keluar                                  |\n";
        cout << "=============================================\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: 
                cout << endl;
                daftarBuku(); 
                break;
            case 2: 
                cout << endl;
                pinjamBuku(); 
                break;
            case 3: 
                cout << endl;
                pengembalianBuku();
                break;
            case 4:
                cout << "\nTerima kasih telah meminjam di perpustakaan kami :)\n";
                break;
            default: 
                cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 4);
    
    return 0;
}