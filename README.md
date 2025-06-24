# 📚 Sistem Informasi Manajemen Perpustakaan

Final project berbasis **C++** untuk simulasi sistem perpustakaan yang melibatkan berbagai struktur data seperti Stack, Queue, Tree, dan Graph. Program ini mampu melakukan pencatatan data buku, peminjaman, pengembalian, pencarian, serta memberikan rekomendasi buku berdasarkan genre.

---

## 👥 Anggota Kelompok

- **Fatimah** (4524210039)  
  Materi: Sorting, Queue
- **Maghfiroh Lisabiliana** (4524210040)  
  Materi: Pointer, Stack
- **Ghifari Ezra Ramadhan** (4524210041)  
  Materi: Searching, Tree, Graph

---

## 🧠 Materi yang Digunakan

- Pointer
- Stack (untuk pengembalian buku)
- Queue (untuk peminjaman buku)
- Sorting (Bubble Sort berdasarkan stok)
- Searching (Binary Search Tree)
- Tree (Binary Search Tree untuk pencarian judul)
- Graph (Rekomendasi buku berdasarkan genre menggunakan DFS)

---

## 🚀 Fitur Utama

| Fitur                     | Deskripsi |
|--------------------------|-----------|
| 📚 Daftar Buku           | Menampilkan daftar buku yang telah diurutkan berdasarkan stok terbanyak |
| 🔍 Cari Buku             | Mencari buku menggunakan **Binary Search Tree** |
| 📥 Peminjaman Buku       | Mengelola antrian peminjam buku menggunakan **Queue** |
| 📤 Pengembalian Buku     | Menyimpan data pengembalian menggunakan **Stack** |
| 🤝 Rekomendasi Buku      | Merekomendasikan buku lain berdasarkan **genre** menggunakan **DFS pada Graph** |

---

## 🛠️ Struktur Data

- `struct Buku`: Menyimpan informasi buku.
- `stackBuku[]`: Menyimpan daftar buku secara global.
- `BNode`: Node untuk **Binary Search Tree** (judul → ID buku).
- `Queue`: Untuk peminjaman buku (FIFO).
- `Stack`: Untuk pengembalian buku (LIFO).
- `adjMatrix[][]`: Matriks ketetanggaan antar buku berdasarkan genre (untuk rekomendasi Graph DFS).

---

## 🧪 Cara Menjalankan Program

1. **Compile Program**:
   ```bash
   g++ -o perpustakaan main.cpp
