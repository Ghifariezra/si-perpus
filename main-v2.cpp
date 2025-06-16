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
 
void daftarBuku();
void cariBuku();

void pinjamBuku()
{
    Queue Q;
    initQueue(Q);

    int pilihan;
    string nama, buku;

    do 
    {
        cout << "=== Sistem Peminjaman Buku (Queue) ===" << endl;
        cout << "1. Tambah Peminjam" << endl;
        cout << "2. Lihat Antrian" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) 
        {
            case 1:
                cout << "Masukkan nama peminjam: ";
                getline(cin, nama);
                cout << "Masukkan judul buku yang dipinjam: ";
                getline(cin, buku);
                tambahPeminjam(Q, nama, buku);
                break;
            case 2:
                lihatAntrian(Q);
                break;
            case 3:
                cout << "Terima kasih telah menggunakan sistem ini.\n";
                break;
            default:
                cout << "Opsi tidak valid. Silakan pilih ulang.\n";
        }
    } while (pilihan != 3); 
}

void pengembalianBuku();
void rekomendasiBuku();
void sortBuku();
void test();
void B();
void A ();
 
int main() 
{
    pinjamBuku();
    return 0;
}