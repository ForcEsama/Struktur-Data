/*
Nama File       : 13_5StudiKasus6.c
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
    int stok;
    struct Node *left;
    struct Node *right;
} Node;
Node *createNode(int kode, char *nama, int stok);
Node *insert(Node *root, int kode, char *nama, int stok);
Node *search(Node *root, int kode);
Node *findMin(Node *root);
Node *deleteNode(Node *root, int kode);
void inOrderTraversal(Node *root);

// Fungsi Utama
int main()
{
    judul();
    Node *root = NULL;

    // Menambah Barang
    root = insert(root, 3003, "Laptop", 10);
    root = insert(root, 3001, "Mouse", 50);
    root = insert(root, 3004, "Keyboard", 30);
    root = insert(root, 3002, "Monitor", 20);

    printf("\nDaftar Barang Setelah Penambahan:\n");
    inOrderTraversal(root);

    // Mencari Barang
    printf("\nPencarian Barang dengan Kode 3004:\n");
    Node *found = search(root, 3004);
    if (found != NULL)
    {
        printf("Barang ditemukan: Kode: %d | Nama: %s | Stok: %d\n", found->kode, found->nama, found->stok);
    }
    else
    {
        printf("Barang dengan kode 3004 tidak ditemukan.\n");
    }

    // Menghapus Barang
    printf("\nMenghapus Barang dengan Kode 3003:\n");
    root = deleteNode(root, 3003);

    printf("\nDaftar Barang Setelah Penghapusan:\n");
    inOrderTraversal(root);

    return 0;
}

void judul()
{
    printf("Nama Program  : Sistem Manajemen Inventaris Barang Berdasarkan Kode Barang\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

// Fungsi Membuat Node Baru
Node *createNode(int kode, char *nama, int stok)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->kode = kode;
    strcpy(newNode->nama, nama);
    newNode->stok = stok;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Fungsi Menambahkan Node ke BST
Node *insert(Node *root, int kode, char *nama, int stok)
{
    if (root == NULL)
        return createNode(kode, nama, stok); // Membuat node baru jika root kosong
    if (kode < root->kode)
        root->left = insert(root->left, kode, nama, stok); // Rekursif ke kiri jika kode lebih kecil
    else if (kode > root->kode)
        root->right = insert(root->right, kode, nama, stok); // Rekursif ke kanan jika kode lebih besar
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
        root->stok = temp->stok;
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
        printf("Kode: %d | Nama: %s | Stok: %d\n", root->kode, root->nama, root->stok);
        inOrderTraversal(root->right); // Traversal ke kanan
    }
}
