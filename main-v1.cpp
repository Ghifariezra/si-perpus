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

// ================== STRUKTUR DATA MANUAL TANPA STL ==================

// Maksimal data
const int MAX_BOOKS = 20;
const int MAX_GENRES = 5;

// Struktur Buku
struct Book
{
    int id;
    string title;
    string author;
    string genre;
    bool isAvailable;
    Book *next; // Untuk linked list

    Book(int i, string t, string a, string g)
        : id(i), title(t), author(a), genre(g), isAvailable(true), next(nullptr) {}
};

// Linked List untuk daftar buku
struct BookList
{
    Book *head;
    int size;

    BookList() : head(nullptr), size(0) {}

    void add(Book *book)
    {
        if (!head)
        {
            head = book;
        }
        else
        {
            Book *curr = head;
            while (curr->next)
                curr = curr->next;
            curr->next = book;
        }
        size++;
    }

    Book *getByIndex(int idx)
    {
        Book *curr = head;
        int i = 0;
        while (curr && i < idx)
        {
            curr = curr->next;
            i++;
        }
        return curr;
    }

    Book *findById(int id)
    {
        Book *curr = head;
        while (curr)
        {
            if (curr->id == id)
                return curr;
            curr = curr->next;
        }
        return nullptr;
    }
};

// Stack manual (linked list)
struct StackNode
{
    string data;
    StackNode *next;
    StackNode(string value) : data(value), next(nullptr) {}
};

struct Stack
{
    StackNode *top;
    Stack() : top(nullptr) {}
    void push(string value)
    {
        StackNode *node = new StackNode(value);
        node->next = top;
        top = node;
    }
    string pop()
    {
        if (!top)
            return "";
        string val = top->data;
        StackNode *tmp = top;
        top = top->next;
        delete tmp;
        return val;
    }
    bool isEmpty() { return top == nullptr; }
    void display()
    {
        StackNode *curr = top;
        while (curr)
        {
            cout << curr->data << endl;
            curr = curr->next;
        }
    }
};

// Queue manual (linked list)
struct QueueNode
{
    string data;
    QueueNode *next;
    QueueNode(string value) : data(value), next(nullptr) {}
};

struct Queue
{
    QueueNode *front, *rear;
    Queue() : front(nullptr), rear(nullptr) {}
    void enqueue(string value)
    {
        QueueNode *node = new QueueNode(value);
        if (!rear)
            front = rear = node;
        else
        {
            rear->next = node;
            rear = node;
        }
    }
    string dequeue()
    {
        if (!front)
            return "";
        string val = front->data;
        QueueNode *tmp = front;
        front = front->next;
        if (!front)
            rear = nullptr;
        delete tmp;
        return val;
    }
    bool isEmpty() { return front == nullptr; }
    void display()
    {
        QueueNode *curr = front;
        while (curr)
        {
            cout << curr->data << endl;
            curr = curr->next;
        }
    }
};

// BST untuk pencarian ID
struct TreeNode
{
    Book *book;
    TreeNode *left, *right;
    TreeNode(Book *b) : book(b), left(nullptr), right(nullptr) {}
};

struct BST
{
    TreeNode *root;
    BST() : root(nullptr) {}
    TreeNode *insert(TreeNode *node, Book *book)
    {
        if (!node)
            return new TreeNode(book);
        if (book->id < node->book->id)
            node->left = insert(node->left, book);
        else if (book->id > node->book->id)
            node->right = insert(node->right, book);
        return node;
    }
    void insert(Book *book) { root = insert(root, book); }
    Book *search(TreeNode *node, int id)
    {
        if (!node)
            return nullptr;
        if (node->book->id == id)
            return node->book;
        if (id < node->book->id)
            return search(node->left, id);
        return search(node->right, id);
    }
    Book *search(int id) { return search(root, id); }
    void inorder(TreeNode *node, Book **arr, int &idx)
    {
        if (!node)
            return;
        inorder(node->left, arr, idx);
        arr[idx++] = node->book;
        inorder(node->right, arr, idx);
    }
    void getAllBooks(Book **arr, int &count)
    {
        count = 0;
        inorder(root, arr, count);
    }
};

// Graph manual untuk genre
struct Graph
{
    int adj[MAX_GENRES][MAX_GENRES];
    string genres[MAX_GENRES];
    int genreCount;
    bool visited[MAX_GENRES];

    Graph() : genreCount(0)
    {
        for (int i = 0; i < MAX_GENRES; i++)
            for (int j = 0; j < MAX_GENRES; j++)
                adj[i][j] = 0;
    }
    void addGenre(string genre)
    {
        if (genreCount < MAX_GENRES)
            genres[genreCount++] = genre;
    }
    void addEdge(int a, int b)
    {
        adj[a][b] = adj[b][a] = 1;
    }
    void DFS(int idx, string *rec, int &recCount)
    {
        visited[idx] = true;
        rec[recCount++] = genres[idx];
        for (int i = 0; i < genreCount; i++)
            if (adj[idx][i] && !visited[i])
                DFS(i, rec, recCount);
    }
    int getGenreIdx(string genre)
    {
        for (int i = 0; i < genreCount; i++)
            if (genres[i] == genre)
                return i;
        return -1;
    }
    void getRecommendations(string genre, string *rec, int &recCount)
    {
        for (int i = 0; i < MAX_GENRES; i++)
            visited[i] = false;
        recCount = 0;
        int idx = getGenreIdx(genre);
        if (idx != -1)
            DFS(idx, rec, recCount);
    }
};

// ========== GLOBAL DATA ==========
BookList allBooks;
BST bookTree;
Stack riwayatPeminjamanStack;
Queue antrianPeminjaman;
Graph genreGraph;

// ========== INISIALISASI DATA ==========
void initializeData()
{
    // Data buku
    Book *b1 = new Book(1, "Harry Potter", "J.K. Rowling", "Fantasy");
    Book *b2 = new Book(2, "Lord of the Rings", "J.R.R. Tolkien", "Fantasy");
    Book *b3 = new Book(3, "1984", "George Orwell", "Dystopian");
    Book *b4 = new Book(4, "Pride and Prejudice", "Jane Austen", "Romance");
    Book *b5 = new Book(5, "The Great Gatsby", "F. Scott Fitzgerald", "Classic");
    Book *b6 = new Book(6, "To Kill a Mockingbird", "Harper Lee", "Classic");
    Book *b7 = new Book(7, "The Catcher in the Rye", "J.D. Salinger", "Classic");
    Book *b8 = new Book(8, "Brave New World", "Aldous Huxley", "Dystopian");
    Book *b9 = new Book(9, "The Hobbit", "J.R.R. Tolkien", "Fantasy");
    Book *b10 = new Book(10, "Romeo and Juliet", "William Shakespeare", "Romance");

    Book *arr[] = {b1, b2, b3, b4, b5, b6, b7, b8, b9, b10};
    for (int i = 0; i < 10; i++)
    {
        allBooks.add(arr[i]);
        bookTree.insert(arr[i]);
    }

    // Genre
    genreGraph.addGenre("Fantasy");
    genreGraph.addGenre("Dystopian");
    genreGraph.addGenre("Romance");
    genreGraph.addGenre("Classic");
    genreGraph.addGenre("Science Fiction");
    genreGraph.addEdge(0, 1); // Fantasy - Dystopian
    genreGraph.addEdge(0, 4); // Fantasy - Science Fiction
    genreGraph.addEdge(1, 4); // Dystopian - Science Fiction
    genreGraph.addEdge(2, 3); // Romance - Classic
    genreGraph.addEdge(3, 1); // Classic - Dystopian
}

// ========== SORTING MANUAL ==========
void bubbleSort(Book **arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j]->title > arr[j + 1]->title)
            {
                Book *tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}
void selectionSort(Book **arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j]->author < arr[minIdx]->author)
                minIdx = j;
        Book *tmp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = tmp;
    }
}

// ========== SEARCHING MANUAL ==========
Book *linearSearch(BookList &list, string title)
{
    Book *curr = list.head;
    while (curr)
    {
        if (curr->title == title)
            return curr;
        curr = curr->next;
    }
    return nullptr;
}
Book *binarySearch(Book **arr, int n, string title)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (arr[m]->title == title)
            return arr[m];
        if (arr[m]->title < title)
            l = m + 1;
        else
            r = m - 1;
    }
    return nullptr;
}

// ========== FITUR UTAMA ==========
void tampilanUtama()
{
    cout << "\n========================================\n";
    cout << "    SISTEM MANAJEMEN PERPUSTAKAAN\n";
    cout << "========================================\n";
    cout << "1. Daftar Buku\n";
    cout << "2. Cari Buku\n";
    cout << "3. Peminjaman Buku\n";
    cout << "4. Pengembalian Buku\n";
    cout << "5. Riwayat Peminjaman\n";
    cout << "6. Antrian Peminjaman\n";
    cout << "7. Rekomendasi Buku\n";
    cout << "8. Sorting Buku\n";
    cout << "9. Exit (Keluar Sementara)\n";
    cout << "0. Keluar Program (Benar-benar keluar)\n";
    cout << "========================================\n";
}

void daftarBuku()
{
    cout << "\n========== DAFTAR BUKU ==========\n";
    cout << setw(5) << "ID" << setw(25) << "Judul" << setw(20) << "Penulis"
         << setw(15) << "Genre" << setw(12) << "Status" << endl;
    cout << string(77, '-') << endl;
    Book *curr = allBooks.head;
    while (curr)
    {
        cout << setw(5) << curr->id
             << setw(25) << curr->title.substr(0, 24)
             << setw(20) << curr->author.substr(0, 19)
             << setw(15) << curr->genre.substr(0, 14)
             << setw(12) << (curr->isAvailable ? "Tersedia" : "Dipinjam") << endl;
        curr = curr->next;
    }
    cout << endl;
}

void cariBuku()
{
    cout << "\n========== PENCARIAN BUKU ==========\n";
    cout << "1. Cari berdasarkan ID (BST)\n";
    cout << "2. Cari berdasarkan Judul (Linear Search)\n";
    cout << "3. Cari berdasarkan Judul (Binary Search - perlu sorting)\n";
    cout << "Pilihan: ";
    int pilihan;
    cin >> pilihan;
    cin.ignore();
    if (pilihan == 1)
    {
        cout << "Masukkan ID buku: ";
        int id;
        cin >> id;
        Book *book = bookTree.search(id);
        if (book)
        {
            cout << "\nBuku ditemukan:\n";
            cout << "ID: " << book->id << "\nJudul: " << book->title << "\nPenulis: " << book->author
                 << "\nGenre: " << book->genre << "\nStatus: " << (book->isAvailable ? "Tersedia" : "Dipinjam") << endl;
        }
        else
            cout << "Buku tidak ditemukan!\n";
    }
    else if (pilihan == 2)
    {
        cout << "Masukkan judul buku: ";
        string title;
        getline(cin, title);
        Book *book = linearSearch(allBooks, title);
        if (book)
        {
            cout << "\nBuku ditemukan:\n";
            cout << "ID: " << book->id << "\nJudul: " << book->title << "\nPenulis: " << book->author
                 << "\nGenre: " << book->genre << "\nStatus: " << (book->isAvailable ? "Tersedia" : "Dipinjam") << endl;
        }
        else
            cout << "Buku tidak ditemukan!\n";
    }
    else if (pilihan == 3)
    {
        Book *arr[MAX_BOOKS];
        int n = 0;
        bookTree.getAllBooks(arr, n);
        bubbleSort(arr, n);
        cout << "Masukkan judul buku: ";
        string title;
        getline(cin, title);
        Book *book = binarySearch(arr, n, title);
        if (book)
        {
            cout << "\nBuku ditemukan:\n";
            cout << "ID: " << book->id << "\nJudul: " << book->title << "\nPenulis: " << book->author
                 << "\nGenre: " << book->genre << "\nStatus: " << (book->isAvailable ? "Tersedia" : "Dipinjam") << endl;
        }
        else
            cout << "Buku tidak ditemukan!\n";
    }
    else
    {
        cout << "Pilihan tidak valid!\n";
    }
}

void peminjaman()
{
    cout << "\n========== PEMINJAMAN BUKU ==========\n";
    cout << "Masukkan ID buku yang ingin dipinjam: ";
    int id;
    cin >> id;
    cin.ignore();
    Book *book = bookTree.search(id);
    if (book && book->isAvailable)
    {
        cout << "Masukkan nama peminjam: ";
        string nama;
        getline(cin, nama);
        book->isAvailable = false;
        string record = "ID: " + to_string(book->id) + " | " + book->title + " | Peminjam: " + nama;
        riwayatPeminjamanStack.push(record);
        cout << "Buku berhasil dipinjam!\nJudul: " << book->title << "\nPeminjam: " << nama << endl;
    }
    else if (book && !book->isAvailable)
    {
        cout << "Masukkan nama untuk antrian: ";
        string nama;
        getline(cin, nama);
        string queueRecord = "ID: " + to_string(book->id) + " | " + book->title + " | Menunggu: " + nama;
        antrianPeminjaman.enqueue(queueRecord);
        cout << "Buku sedang dipinjam. Anda telah ditambahkan ke antrian!\n";
    }
    else
    {
        cout << "Buku tidak ditemukan!\n";
    }
}

void pengembalian()
{
    cout << "\n========== PENGEMBALIAN BUKU ==========\n";
    cout << "Masukkan ID buku yang ingin dikembalikan: ";
    int id;
    cin >> id;
    Book *book = bookTree.search(id);
    if (book && !book->isAvailable)
    {
        book->isAvailable = true;
        cout << "Buku berhasil dikembalikan!\nJudul: " << book->title << endl;
        if (!antrianPeminjaman.isEmpty())
        {
            cout << "\nMemproses antrian peminjaman...\n";
            string nextInQueue = antrianPeminjaman.dequeue();
            cout << "Peminjam berikutnya: " << nextInQueue << endl;
        }
    }
    else if (book && book->isAvailable)
    {
        cout << "Buku ini tidak sedang dipinjam!\n";
    }
    else
    {
        cout << "Buku tidak ditemukan!\n";
    }
}

void riwayatPeminjaman()
{
    cout << "\n========== RIWAYAT PEMINJAMAN (STACK) ==========\n";
    if (riwayatPeminjamanStack.isEmpty())
        cout << "Tidak ada riwayat peminjaman.\n";
    else
    {
        cout << "Riwayat peminjaman (terbaru ke terlama):\n";
        riwayatPeminjamanStack.display();
    }
}

void antrianPeminjamanFunc()
{
    cout << "\n========== ANTRIAN PEMINJAMAN (QUEUE) ==========\n";
    if (antrianPeminjaman.isEmpty())
        cout << "Tidak ada antrian peminjaman.\n";
    else
    {
        cout << "Antrian peminjaman:\n";
        antrianPeminjaman.display();
    }
}

void rekomendasiBuku()
{
    cout << "\n========== REKOMENDASI BUKU (GRAPH DFS) ==========\n";
    cout << "Genre yang tersedia:\n";
    for (int i = 0; i < genreGraph.genreCount; i++)
        cout << i + 1 << ". " << genreGraph.genres[i] << endl;
    cout << "Masukkan nama genre untuk rekomendasi: ";
    cin.ignore();
    string genre;
    getline(cin, genre);
    string rec[MAX_GENRES];
    int recCount = 0;
    genreGraph.getRecommendations(genre, rec, recCount);
    if (recCount > 0)
    {
        cout << "\nRekomendasi genre berdasarkan " << genre << " (DFS):\n";
        for (int i = 0; i < recCount; i++)
            cout << "- " << rec[i] << endl;
        cout << "\nBuku-buku dalam genre rekomendasi:\n";
        Book *curr = allBooks.head;
        while (curr)
        {
            for (int i = 0; i < recCount; i++)
                if (curr->genre == rec[i] && curr->isAvailable)
                    cout << "• " << curr->title << " oleh " << curr->author << " (Genre: " << curr->genre << ")\n";
            curr = curr->next;
        }
    }
    else
    {
        cout << "Genre tidak ditemukan!\n";
    }
}
 
void sortingBuku()
{
    cout << "\n========== SORTING BUKU ==========\n";
    cout << "1. Sort berdasarkan Judul (Bubble Sort)\n";
    cout << "2. Sort berdasarkan Penulis (Selection Sort)\n";
    cout << "Pilihan: ";
    int pilihan;
    cin >> pilihan;
    Book *arr[MAX_BOOKS];
    int n = 0;
    bookTree.getAllBooks(arr, n);
    if (pilihan == 1)
    {
        bubbleSort(arr, n);
        cout << "\nBuku diurutkan berdasarkan judul (Bubble Sort):\n";
    }
    else if (pilihan == 2)
    {
        selectionSort(arr, n);
        cout << "\nBuku diurutkan berdasarkan penulis (Selection Sort):\n";
    }
    else
    {
        cout << "Pilihan tidak valid!\n";
        return;
    }
    cout << setw(5) << "ID" << setw(25) << "Judul" << setw(20) << "Penulis"
         << setw(15) << "Genre" << setw(12) << "Status" << endl;
    cout << string(77, '-') << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(5) << arr[i]->id
             << setw(25) << arr[i]->title.substr(0, 24)
             << setw(20) << arr[i]->author.substr(0, 19)
             << setw(15) << arr[i]->genre.substr(0, 14)
             << setw(12) << (arr[i]->isAvailable ? "Tersedia" : "Dipinjam") << endl;
    }
}

// ========== MAIN FUNCTION ==========
int main()
{
    initializeData();
    int pilihan;
    bool running = true;
    while (running)
    {
        daftarBuku();
        tampilanUtama();
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            daftarBuku();
            break;
        case 2:
            cariBuku();
            break;
        case 3:
            peminjaman();
            break;
        case 4:
            pengembalian();
            break;
        case 5:
            riwayatPeminjaman();
            break;
        case 6:
            antrianPeminjamanFunc();
            break;
        case 7:
            rekomendasiBuku();
            break;
        case 8:
            sortingBuku();
            break;
        case 9:
            cout << "Anda memilih keluar sementara. Tekan Enter untuk kembali ke menu utama...";
            cin.ignore();
            cin.get();
            break;
        case 0:
            cout << "Apakah Anda yakin ingin keluar dari program? (y/n): ";
            char konfirmasi;
            cin >> konfirmasi;
            if (konfirmasi == 'y' || konfirmasi == 'Y')
                running = false;
            break;
        default:
            cout << "Pilihan tidak valid! Silakan coba lagi.\n";
        }
        if (running)
        {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
            system("cls");
        }
    }
    cout << "Terima kasih telah menggunakan sistem perpustakaan!\n";
    return 0;
}