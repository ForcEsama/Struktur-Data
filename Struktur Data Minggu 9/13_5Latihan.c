/*
Nama File       : 13_5Latihan.c
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
// Struktur Mahasiswa
typedef struct Mahasiswa
{
    int nim;
    char nama[50];
    float nilai;
    struct Mahasiswa *left;
    struct Mahasiswa *right;
} Mahasiswa;
Mahasiswa *createNode(int nim, const char *nama, float nilai);
Mahasiswa *insert(Mahasiswa *root, int nim, const char *nama, float nilai);
Mahasiswa *search(Mahasiswa *root, float nilai);
Mahasiswa *findMin(Mahasiswa *node);
Mahasiswa *deleteNode(Mahasiswa *root, float nilai);
void inOrder(Mahasiswa *root);
void preOrder(Mahasiswa *root);
void postOrder(Mahasiswa *root);

// Fungsi utama
int main()
{
    judul();
    Mahasiswa *root = NULL;

    // Menambahkan data mahasiswa
    root = insert(root, 101, "Andi", 85.5);
    root = insert(root, 102, "Budi", 90.0);
    root = insert(root, 103, "Citra", 75.0);
    root = insert(root, 104, "Dewi", 80.0);

    // Menampilkan seluruh data dengan traversal
    printf("In-order Traversal (Urut Kecil ke Besar):\n");
    inOrder(root);

    printf("\nPre-order Traversal:\n");
    preOrder(root);

    printf("\nPost-order Traversal:\n");
    postOrder(root);

    // Mencari mahasiswa berdasarkan nilai
    float cariNilai = 80.0;
    Mahasiswa *hasil = search(root, cariNilai);
    if (hasil != NULL)
        printf("\nMahasiswa dengan nilai %.2f ditemukan: %s\n", cariNilai, hasil->nama);
    else
        printf("\nMahasiswa dengan nilai %.2f tidak ditemukan.\n", cariNilai);

    // Menghapus node berdasarkan nilai
    float hapusNilai = 75.0;
    root = deleteNode(root, hapusNilai);
    printf("\nSetelah menghapus mahasiswa dengan nilai %.2f:\n", hapusNilai);
    inOrder(root);

    return 0;
}

void judul()
{
    printf("Nama Program  : Implementasi Tree dalam Studi Kasus Nyata\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

// Fungsi membuat node baru
Mahasiswa *createNode(int nim, const char *nama, float nilai)
{
    Mahasiswa *newNode = (Mahasiswa *)malloc(sizeof(Mahasiswa));
    newNode->nim = nim;
    strcpy(newNode->nama, nama);
    newNode->nilai = nilai;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Fungsi menambahkan node ke dalam tree
Mahasiswa *insert(Mahasiswa *root, int nim, const char *nama, float nilai)
{
    if (root == NULL)
        return createNode(nim, nama, nilai);
    if (nilai < root->nilai)
        root->left = insert(root->left, nim, nama, nilai);
    else
        root->right = insert(root->right, nim, nama, nilai);
    return root;
}

// Fungsi mencari mahasiswa berdasarkan nilai
Mahasiswa *search(Mahasiswa *root, float nilai)
{
    if (root == NULL || root->nilai == nilai)
        return root;
    if (nilai < root->nilai)
        return search(root->left, nilai);
    return search(root->right, nilai);
}

// Fungsi menemukan node dengan nilai terkecil
Mahasiswa *findMin(Mahasiswa *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

// Fungsi menghapus node berdasarkan nilai
Mahasiswa *deleteNode(Mahasiswa *root, float nilai)
{
    if (root == NULL)
        return root;
    if (nilai < root->nilai)
        root->left = deleteNode(root->left, nilai);
    else if (nilai > root->nilai)
        root->right = deleteNode(root->right, nilai);
    else
    {
        if (root->left == NULL)
        {
            Mahasiswa *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Mahasiswa *temp = root->left;
            free(root);
            return temp;
        }
        Mahasiswa *temp = findMin(root->right);
        root->nilai = temp->nilai;
        root->nim = temp->nim;
        strcpy(root->nama, temp->nama);
        root->right = deleteNode(root->right, temp->nilai);
    }
    return root;
}

// Fungsi traversal in-order
void inOrder(Mahasiswa *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("NIM: %d, Nama: %s, Nilai: %.2f\n", root->nim, root->nama, root->nilai);
        inOrder(root->right);
    }
}

// Fungsi traversal pre-order
void preOrder(Mahasiswa *root)
{
    if (root != NULL)
    {
        printf("NIM: %d, Nama: %s, Nilai: %.2f\n", root->nim, root->nama, root->nilai);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Fungsi traversal post-order
void postOrder(Mahasiswa *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("NIM: %d, Nama: %s, Nilai: %.2f\n", root->nim, root->nama, root->nilai);
    }
}
