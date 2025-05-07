/*
Nama File       : 13_10TugasMandiri.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/03/2025
Deskripsi       : Tree dan Operasinya
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main();
void judul();
// Definisi Struktur Node
typedef struct Node
{
    int kode;
    char nama[50];
    int harga;
    struct Node *left;
    struct Node *right;
} Node;
Node *createNode(int kode, char *nama, int stok);
Node *insert(Node *root, int kode, char *nama, int stok);
Node *search(Node *root, int kode);
void updateHarga(Node *root, int kode, int newHarga);
Node *findMin(Node *root);
Node *deleteNode(Node *root, int kode);
void inOrderTraversal(Node *root);
// Fungsi Utama
int main()
{
    judul();
    Node *root = NULL;

    // Menambah Barang
    root = insert(root, 3003, "Laptop", 10000000);
    root = insert(root, 3001, "Mouse", 500000);
    root = insert(root, 3004, "Keyboard", 700000);
    root = insert(root, 3002, "Monitor", 2000000);

    // Menampilkan Semua Barang
    printf("\nDaftar Barang Setelah Penambahan:\n");
    inOrderTraversal(root);

    // Mencari Harga Barang
    int kodeCari = 3004;
    printf("\nMencari Barang dengan Kode %d:\n", kodeCari);
    Node *found = search(root, kodeCari);
    if (found != NULL)
    {
        printf("Barang ditemukan: Kode: %d | Nama: %s | Harga: %d\n", found->kode, found->nama, found->harga);
    }
    else
    {
        printf("Barang dengan kode %d tidak ditemukan.\n", kodeCari);
    }

    // Update Harga Barang
    int kodeUpdate = 3002;
    int hargaBaru = 2500000;
    printf("\nUpdate Harga Barang dengan Kode %d:\n", kodeUpdate);
    updateHarga(root, kodeUpdate, hargaBaru);

    // Menampilkan Semua Barang Setelah Update
    printf("\nDaftar Barang Setelah Update Harga:\n");
    inOrderTraversal(root);

    return 0;
}

void judul()
{
    printf("Nama Program  : Tugas Mandiri Tambahan untuk Mahasiswa Sistem Manajemen Inventaris Barang Berdasarkan Kode Barang\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

// Fungsi Membuat Node Baru
Node *createNode(int kode, char *nama, int harga)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->kode = kode;
    strcpy(newNode->nama, nama);
    newNode->harga = harga;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Fungsi Menambahkan Node ke BST
Node *insert(Node *root, int kode, char *nama, int harga)
{
    if (root == NULL)
        return createNode(kode, nama, harga); // Membuat node baru jika root kosong
    if (kode < root->kode)
        root->left = insert(root->left, kode, nama, harga); // Rekursif ke kiri jika kode lebih kecil
    else if (kode > root->kode)
        root->right = insert(root->right, kode, nama, harga); // Rekursif ke kanan jika kode lebih besar
    return root;
}

// Fungsi Mencari Node Berdasarkan Kode
Node *search(Node *root, int kode)
{
    if (root == NULL || root->kode == kode)
        return root; // Mengembalikan node jika ditemukan atau root kosong
    if (kode < root->kode)
        return search(root->left, kode); // Rekursif ke kiri
    else
        return search(root->right, kode); // Rekursif ke kanan
}

// Fungsi Update Harga Barang Berdasarkan Kode
void updateHarga(Node *root, int kode, int newHarga)
{
    Node *foundNode = search(root, kode); // Mencari barang berdasarkan kode
    if (foundNode != NULL)
    {
        foundNode->harga = newHarga; // Memperbarui harga barang
        printf("Harga barang dengan kode %d berhasil diperbarui menjadi %d.\n", kode, newHarga);
    }
    else
    {
        printf("Barang dengan kode %d tidak ditemukan.\n", kode);
    }
}

// Fungsi Menemukan Node dengan Nilai Terkecil
Node *findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left; // Mencari node dengan nilai terkecil
    return root;
}

// Fungsi Menghapus Node Berdasarkan Kode
Node *deleteNode(Node *root, int kode)
{
    if (root == NULL)
        return root; // Jika root kosong, return NULL
    if (kode < root->kode)
        root->left = deleteNode(root->left, kode); // Rekursif ke kiri
    else if (kode > root->kode)
        root->right = deleteNode(root->right, kode); // Rekursif ke kanan
    else
    {
        // Jika node ditemukan, hapus sesuai aturan BST
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = findMin(root->right); // Cari node terkecil di subtree kanan
        root->kode = temp->kode;
        strcpy(root->nama, temp->nama);
        root->harga = temp->harga;
        root->right = deleteNode(root->right, temp->kode); // Hapus node yang telah dipindahkan
    }
    return root;
}

// Fungsi Traversal In-Order untuk Menampilkan Node
void inOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left); // Traversal ke kiri
        printf("Kode: %d | Nama: %s | Harga: %d\n", root->kode, root->nama, root->harga);
        inOrderTraversal(root->right); // Traversal ke kanan
    }
}
