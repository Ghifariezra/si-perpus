# Sistem Informasi - Manajemen Perpustakaan (PROJECT UAS - ASD)

#### Data Daftar Buku:

- Judul
- Penulis
- Genre
- Status
- Stock

#### Prosess Cari Buku:
- Judul

#### Prosess Pinjam Buku:
- Pengguna di mintai data:
- Nama
- Judul
- Tanggal Pinjam
---
- Riwayat Peminjam

#### Prosess Pengembalian Buku:
- Pengguna di mintai data:
- Nama
- Judul
- Tanggal Pengembalian
- Riwayat Pengembalian

#### Prosess Sort Buku:
- Sorting Berdasarkan Stock

#### Preview Source Code:
``` c++
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

void TambahPeminjam(Queue &Q, string Fnama, string FjudulBuku);
void LayaniPeminjam(Queue &Q);
void LihatAntrian(Queue Q);
void CariBuku();
bool KurangiStok(string judul);
void PinjamBuku();
void PengembalianBuku();
void RekomendasiBuku();
void DisplayBuku();

int main() {
    return 0;
}
```
