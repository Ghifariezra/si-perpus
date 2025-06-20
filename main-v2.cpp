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
    string Fnama; // Pointer
    string FjudulBuku;
    Node *Fnext;
} Node;

typedef struct Queue
{
    Node *FFirst;
    Node *FLast;
} Queue;

void initQueue(Queue &Q)
{
    Q.FFirst = NULL;
    Q.FLast = NULL;
}

void TambahPeminjam(Queue &Q, string Fnama, string FjudulBuku);
void LayaniPeminjam(Queue &Q);
void LihatAntrian(Queue Q);
void CariBuku();
bool KurangiStok(string judul);
void PinjamBuku();
void PengembalianBuku();
void RekomendasiBuku();
void DisplayBuku();

const int MAX_STACK = 100;

struct Buku
{
    string judul, penulis, genre, status;
    int stock;
};

// Gunakan 1 array global
Buku stackBuku[MAX_STACK];
int top = -1;

// Jumlah data buku
int jumlahBuku = 0;

void initDataBuku()
{
    if (jumlahBuku == 0)
    { // hanya isi jika belum pernah diisi
        stackBuku[++top] = {"The Psychology of Money", "Morgan Housel", "Psikologi Finansial", "Tersedia", 2};
        stackBuku[++top] = {"Laut Bercerita", "Leila S. Chudori", "Novel Sosial", "Tersedia", 5};
        stackBuku[++top] = {"Dilan 1990", "Pidi Baiq", "Romantis", "Tidak Tersedia", 0};
        stackBuku[++top] = {"Harry Potter", "J.K. Rowling", "Fantasi", "Tersedia", 3};
        stackBuku[++top] = {"Danur", "Risa Saraswati", "Horor", "Tersedia", 1};
        jumlahBuku = top + 1;
    }
}

int main()
{
    int pilihan;

    initDataBuku(); // Inisialisasi data buku
    do
    {
        cout << "\n=============================================\n";
        cout << "         SELAMAT DATANG DI PERPUSTAKAAN       \n";
        cout << "=============================================\n";
        cout << "| 1. Daftar Buku                             |\n";
        cout << "| 2. Cari Buku                               |\n";
        cout << "| 3. Peminjaman Buku                         |\n";
        cout << "| 4. Pengembalian Buku                       |\n";
        cout << "| 5. Keluar                                  |\n";
        cout << "=============================================\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            cout << endl;
            system("cls");
            DisplayBuku();
            break;
        case 2:
            cout << endl;
            CariBuku();
            break;
        case 3:
            cout << endl;
            PinjamBuku();
            break;
        case 4:
            cout << endl;
            system("cls");
            PengembalianBuku();
            break;
        default:
            cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan > 0 && pilihan < 5);

    return 0;
}

void TambahPeminjam(Queue &Q, string Fnama, string FjudulBuku)
{
    Node *Fbaru = new Node{Fnama, FjudulBuku, NULL};
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

void LayaniPeminjam(Queue &Q)
{
    if (Q.FFirst != NULL)
    {
        Node *dilayani = Q.FFirst;
        cout << "\nSedang melayani: " << dilayani->Fnama
             << " (Buku: " << dilayani->FjudulBuku << ")\n";
        Q.FFirst = Q.FFirst->Fnext;
        if (Q.FFirst == NULL)
            Q.FLast = NULL;
        delete dilayani;
    }
    else
    {
        cout << "\nTidak ada antrian untuk dilayani.\n";
    }
}

void LihatAntrian(Queue Q)
{
    Node *bantu = Q.FFirst;
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

void CariBuku()
{
    // input judul untuk dicari (SEARCHING)
    string cariJudul;
    cout << "Masukkan judul buku yang ingin dicari: ";
    getline(cin, cariJudul);

    bool ditemukan = false;
    for (int i = 0; i <= top; i++)
    {
        if (stackBuku[i].judul == cariJudul)
        {
            system("cls");
            cout << "\n===== BUKU DITEMUKAN ====\n";
            cout << "====== DETAIL BUKU ======\n";
            cout << "Judul   : " << stackBuku[i].judul << endl;
            cout << "Penulis : " << stackBuku[i].penulis << endl;
            cout << "Genre   : " << stackBuku[i].genre << endl;
            cout << "Status  : " << stackBuku[i].status << endl;
            cout << "Stock   : " << stackBuku[i].stock << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan)
    {
        cout << "\nBuku tidak tersedia.\n";
    }
}

bool KurangiStok(string judul)
{
    for (int i = 0; i <= top; i++)
    {
        if (stackBuku[i].judul == judul)
        {
            if (stackBuku[i].stock > 0)
            {
                stackBuku[i].stock--;
                if (stackBuku[i].stock == 0)
                    stackBuku[i].status = "Tidak Tersedia";
                return true;
            }
            else
            {
                cout << "\nStok buku habis!\n";
                return false;
            }
        }
    }
    cout << "Judul buku tidak ditemukan.\n";
    return false;
}

void PinjamBuku()
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
        cout << "2. Layani peminjam" << endl;
        cout << "3. Lihat Antrian" << endl;
        cout << "4. Kembali ke Menu Utama" << endl;
        cout << "=================================" << endl;

        cout << "Pilih opsi: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            cout << endl;
            cout << "Masukkan nama peminjam: ";
            getline(cin, nama);
            cout << "Masukkan judul buku yang dipinjam: ";
            getline(cin, buku);

            if (KurangiStok(buku))
            {
                TambahPeminjam(Q, nama, buku);
                cout << "Peminjam berhasil ditambahkan ke antrian :)" << endl;
            }
            else
            {
                cout << "Gagal menambahkan ke antrian karena stok tidak tersedia.\n";
            }
            break;
        case 2:
            LayaniPeminjam(Q);
            break;
        case 3:
            LihatAntrian(Q);
            break;
        default:
            system("cls");
            break;
        }
    } while (pilihan > 0 && pilihan < 4);
}


void PengembalianBuku()
{
    const int MAX_STACK = 100;

    struct Pengembalian
    {
        string nama;
        string judul;
        string tanggal;
    };
    
    // Stack
    Pengembalian stackKembali[MAX_STACK];
    int top = -1;

    int pilihan;
    do
    {
        cout << "=================================" << endl;
        cout << "======= Pengembalian Buku =======" << endl;
        cout << "1. Tambah Data Pengembalian" << endl;
        cout << "2. Lihat Semua Pengembalian" << endl;
        cout << "3. Cari Pengembalian" << endl;
        cout << "4. Kembali ke Menu Utama" << endl;
        cout << "=================================" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
        {
            if (top >= MAX_STACK - 1)
            {
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
        case 2:
        {
            if (top == -1)
            {
                cout << "\nBelum ada data pengembalian.\n";
            }
            else
            {
                cout << "\n===== Daftar Pengembalian Buku =====\n";
                for (int i = top; i >= 0; i--)
                {
                    cout << "- Nama     : " << stackKembali[i].nama << endl;
                    cout << "  Judul    : " << stackKembali[i].judul << endl;
                    cout << "  Tanggal  : " << stackKembali[i].tanggal << endl;
                    cout << "-----------------------------------\n";
                }
            }
            break;
        }
        case 3:
        {
            // Searching
            if (top == -1)
            {
                cout << "\nTidak ada data pengembalian.\n";
                break;
            }

            string cariJudul;
            cout << "\nMasukkan judul buku yang ingin dicari: ";
            getline(cin, cariJudul);

            bool ketemu = false;
            for (int i = 0; i <= top; i++)
            {
                if (stackKembali[i].judul == cariJudul)
                {
                    cout << "\n== Ditemukan ==\n";
                    cout << "Nama     : " << stackKembali[i].nama << endl;
                    cout << "Judul    : " << stackKembali[i].judul << endl;
                    cout << "Tanggal  : " << stackKembali[i].tanggal << endl;
                    ketemu = true;
                    break;
                }
            }

            if (!ketemu)
            {
                cout << "\nData pengembalian tidak ditemukan.\n";
            }

            break;
        }
        default:
            cout << "Opsi tidak valid.\n";
        }

    } while (pilihan != 4);
}

void RekomendasiBuku();

void DisplayBuku()
{
    // Bubble Sort berdasarkan stok (descending)
    for (int i = 0; i < jumlahBuku - 1; i++)
    {
        for (int j = 0; j < jumlahBuku - i - 1; j++)
        {
            if (stackBuku[j].stock < stackBuku[j + 1].stock)
            {
                swap(stackBuku[j], stackBuku[j + 1]);
            }
        }
    }

    cout << string(115, '=') << endl;
    cout << setw(80) << right << "Daftar Buku Setelah Diurutkan (Stok Terbanyak)" << endl;
    cout << string(115, '=') << endl;

    cout << left
         << "| " << setw(4) << "No"
         << "| " << setw(35) << "Judul"
         << "| " << setw(20) << "Penulis"
         << "| " << setw(20) << "Genre"
         << "| " << setw(17) << "Status"
         << "| " << setw(5) << "Stok"
         << " |" << endl;

    cout << string(115, '-') << endl;

    for (int i = 0; i < jumlahBuku; i++)
    {
        string judulFix = stackBuku[i].judul;
        if (judulFix.length() > 35)
        {
            judulFix = judulFix.substr(0, 32) + "...";
        }

        cout << "| " << setw(4) << i + 1
             << "| " << setw(35) << judulFix
             << "| " << setw(20) << stackBuku[i].penulis
             << "| " << setw(20) << stackBuku[i].genre
             << "| " << setw(17) << stackBuku[i].status
             << "| " << setw(5) << stackBuku[i].stock
             << " |" << endl;
    }

    cout << string(115, '=') << endl;
}
