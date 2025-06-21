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

const int MAX_STACK = 100;

int top = -1;
// Jumlah data buku
int jumlahBuku = 0;

struct BNode
{
    string key;
    int bookId;
    BNode *left;
    BNode *right;
};

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

struct Buku
{
    int id;
    string judul, penulis, genre, status;
    int stock;
};

// Gunakan 1 array global
Buku stackBuku[MAX_STACK];
BNode *rootBTree = nullptr;

// Fungsi untuk mencari buku berdasarkan ID
int findBookIndexById(int bookId)
{
    for (int i = 0; i < jumlahBuku; i++)
    {
        if (stackBuku[i].id == bookId)
        {
            return i;
        }
    }
    return -1;
}

// Update fungsi insert BST
BNode *insertBTree(BNode *root, string key, int bookId)
{
    if (root == nullptr)
    {
        BNode *newNode = new BNode{key, bookId, nullptr, nullptr};
        return newNode;
    }
    if (key < root->key)
    {
        root->left = insertBTree(root->left, key, bookId);
    }
    else if (key > root->key)
    {
        root->right = insertBTree(root->right, key, bookId);
    }
    return root;
}

// Update fungsi search BST
int searchBTree(BNode *root, string key)
{
    if (root == nullptr)
        return -1;
    if (root->key == key)
        return findBookIndexById(root->bookId); // Cari index berdasarkan ID
    if (key < root->key)
        return searchBTree(root->left, key);
    return searchBTree(root->right, key);
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

void initDataBuku()
{
    if (jumlahBuku == 0)
    {
        stackBuku[++top] = {1, "The Psychology of Money", "Morgan Housel", "Psikologi Finansial", "Tersedia", 2};
        rootBTree = insertBTree(rootBTree, stackBuku[top].judul, stackBuku[top].id);

        stackBuku[++top] = {2, "Laut Bercerita", "Leila S. Chudori", "Novel Sosial", "Tersedia", 5};
        rootBTree = insertBTree(rootBTree, stackBuku[top].judul, stackBuku[top].id);

        stackBuku[++top] = {3, "Dilan 1990", "Pidi Baiq", "Romantis", "Tidak Tersedia", 0};
        rootBTree = insertBTree(rootBTree, stackBuku[top].judul, stackBuku[top].id);

        stackBuku[++top] = {4, "Harry Potter", "J.K. Rowling", "Fantasi", "Tersedia", 3};
        rootBTree = insertBTree(rootBTree, stackBuku[top].judul, stackBuku[top].id);

        stackBuku[++top] = {5, "Danur", "Risa Saraswati", "Horor", "Tersedia", 1};
        rootBTree = insertBTree(rootBTree, stackBuku[top].judul, stackBuku[top].id);

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
    string cariJudul;
    cout << "Masukkan judul buku yang ingin dicari: ";
    getline(cin, cariJudul);

    int index = searchBTree(rootBTree, cariJudul);
    if (index != -1)
    {
        system("cls");
        cout << "\n===== BUKU DITEMUKAN ====\n";
        cout << "====== DETAIL BUKU ======\n";
        cout << "Judul   : " << stackBuku[index].judul << endl;
        cout << "Penulis : " << stackBuku[index].penulis << endl;
        cout << "Genre   : " << stackBuku[index].genre << endl;
        cout << "Status  : " << stackBuku[index].status << endl;
        cout << "Stock   : " << stackBuku[index].stock << endl;
    }
    else
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

// Fungsi untuk menambah stok buku berdasarkan judul
void TambahStok(string judul)
{
    for (int i = 0; i <= top; i++)
    {
        if (stackBuku[i].judul == judul)
        {
            stackBuku[i].stock++;
            stackBuku[i].status = "Tersedia";
            break;
        }
    }
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
            TambahStok(data.judul); // Tambah stok buku saat pengembalian
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

// ===== ALTERNATIF SOLUSI 2: Gunakan copy array untuk sorting =====
void DisplayBuku()
{
    // Buat copy array untuk sorting, jangan sort array asli
    Buku tempBuku[MAX_STACK];
    for (int i = 0; i < jumlahBuku; i++)
    {
        tempBuku[i] = stackBuku[i];
    }

    // Bubble Sort pada array copy
    for (int i = 0; i < jumlahBuku - 1; i++)
    {
        for (int j = 0; j < jumlahBuku - i - 1; j++)
        {
            if (tempBuku[j].stock < tempBuku[j + 1].stock)
            {
                swap(tempBuku[j], tempBuku[j + 1]);
            }
        }
    }

    // Display menggunakan array yang sudah di-sort
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
        string judulFix = tempBuku[i].judul;
        if (judulFix.length() > 35)
        {
            judulFix = judulFix.substr(0, 32) + "...";
        }

        cout << "| " << setw(4) << i + 1
             << "| " << setw(35) << judulFix
             << "| " << setw(20) << tempBuku[i].penulis
             << "| " << setw(20) << tempBuku[i].genre
             << "| " << setw(17) << tempBuku[i].status
             << "| " << setw(5) << tempBuku[i].stock
             << " |" << endl;
    }

    cout << string(115, '=') << endl;
}