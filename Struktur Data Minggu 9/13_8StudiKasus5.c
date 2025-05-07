/*
Nama File       : 13_5StudiKasus5.c
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
    int ID;
    char nama[50];
    char kategori[30];
    struct Node *left;
    struct Node *right;
} Node;
Node *createNode(int ID, char *nama, char *kategori);
Node *insert(Node *root, int ID, char *nama, char *kategori);
Node *search(Node *root, int ID);
Node *findMin(Node *root);
Node *deleteNode(Node *root, int ID);
void inOrderTraversal(Node *root);

// Fungsi Utama
int main()
{
    judul();
    Node *root = NULL;

    // Menambah Pemesanan
    root = insert(root, 2003, "Rina", "VIP");
    root = insert(root, 2001, "Ari", "Reguler");
    root = insert(root, 2004, "Nina", "VIP");
    root = insert(root, 2002, "Budi", "Reguler");

    printf("\nDaftar Pemesanan Setelah Penambahan:\n");
    inOrderTraversal(root);

    // Mencari Pemesanan
    printf("\nPencarian Pemesanan dengan ID 2004:\n");
    Node *found = search(root, 2004);
    if (found != NULL)
    {
        printf("Pemesanan ditemukan: ID: %d | Nama: %s | Kategori: %s\n", found->ID, found->nama, found->kategori);
    }
    else
    {
        printf("Pemesanan dengan ID 2004 tidak ditemukan.\n");
    }

    // Menghapus Pemesanan
    printf("\nMenghapus Pemesanan dengan ID 2003:\n");
    printf("Daftar akan terstruktur ulang\n");
    root = deleteNode(root, 2003);

    printf("\nDaftar Pemesanan Setelah Penghapusan:\n");
    inOrderTraversal(root);

    return 0;
}

void judul()
{
    printf("Nama Program  : Sistem Pemesanan Tiket Konser Berdasarkan ID Pemesanan\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

// Fungsi Membuat Node Baru
Node *createNode(int ID, char *nama, char *kategori)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->ID = ID;
    strcpy(newNode->nama, nama);
    strcpy(newNode->kategori, kategori);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Fungsi Menambahkan Node ke BST
Node *insert(Node *root, int ID, char *nama, char *kategori)
{
    if (root == NULL)
        return createNode(ID, nama, kategori);
    if (ID < root->ID)
        root->left = insert(root->left, ID, nama, kategori);
    else if (ID > root->ID)
        root->right = insert(root->right, ID, nama, kategori);
    return root;
}

// Fungsi Mencari Node Berdasarkan ID
Node *search(Node *root, int ID)
{
    if (root == NULL || root->ID == ID)
        return root;
    if (ID < root->ID)
        return search(root->left, ID);
    else
        return search(root->right, ID);
}

// Fungsi Menemukan Node dengan Nilai Terkecil
Node *findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Fungsi Menghapus Node Berdasarkan ID
Node *deleteNode(Node *root, int ID)
{
    if (root == NULL)
        return root;
    if (ID < root->ID)
        root->left = deleteNode(root->left, ID);
    else if (ID > root->ID)
        root->right = deleteNode(root->right, ID);
    else
    {
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
        Node *temp = findMin(root->right);
        root->ID = temp->ID;
        strcpy(root->nama, temp->nama);
        strcpy(root->kategori, temp->kategori);
        root->right = deleteNode(root->right, temp->ID);
    }
    return root;
}

// Fungsi Traversal In-Order untuk Menampilkan Node
void inOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("ID: %d | Nama: %s | Kategori: %s\n", root->ID, root->nama, root->kategori);
        inOrderTraversal(root->right);
    }
}
