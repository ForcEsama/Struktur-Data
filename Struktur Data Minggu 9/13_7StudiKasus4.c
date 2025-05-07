/*
Nama File       : 13_5StudiKasus4.c
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
typedef struct Node
{
    int NIM;
    char Nama[50];
    char Jurusan[50];
    struct Node *Left;
    struct Node *Right;
} Node;
Node *createNode(int NIM, char *Nama, char *Jurusan);
Node *insert(Node *root, int NIM, char *Nama, char *Jurusan);
Node *search(Node *root, int NIM);
Node *findMin(Node *root);
Node *deleteNode(Node *root, int NIM);
void inOrderTraversal(Node *root);

int main()
{
    judul();
    Node *root = NULL;
    int choice, NIM;
    char Nama[50], Jurusan[50];
    Node *found;

    do
    {
        printf("\nMenu:\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Cari Mahasiswa\n");
        printf("3. Hapus Mahasiswa\n");
        printf("4. Tampilkan Mahasiswa (In-Order Traversal)\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nMasukkan NIM: ");
            scanf("%d", &NIM);
            printf("Masukkan Nama: ");
            scanf(" %[^\n]", Nama); // Menggunakan " %[^\n]" untuk membaca string dengan spasi
            printf("Masukkan Jurusan: ");
            scanf(" %[^\n]", Jurusan);
            root = insert(root, NIM, Nama, Jurusan);
            printf("Mahasiswa berhasil ditambahkan!\n");
            break;

        case 2:
            printf("\nMasukkan NIM yang dicari: ");
            scanf("%d", &NIM);
            found = search(root, NIM);
            if (found != NULL)
            {
                printf("Mahasiswa ditemukan: NIM: %d | Nama: %s | Jurusan: %s\n", found->NIM, found->Nama, found->Jurusan);
            }
            else
            {
                printf("Mahasiswa dengan NIM %d tidak ditemukan.\n", NIM);
            }
            break;

        case 3:
            printf("\nMasukkan NIM yang ingin dihapus: ");
            scanf("%d", &NIM);
            root = deleteNode(root, NIM);
            printf("Mahasiswa dengan NIM %d berhasil dihapus (jika ada).\n", NIM);
            break;

        case 4:
            printf("\nData Mahasiswa (In-Order Traversal):\n");
            inOrderTraversal(root);
            break;

        case 5:
            printf("Keluar dari program.\n");
            break;

        default:
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 5);

    return 0;
}

void judul()
{
    printf("Nama Program  : Manajemen Data Mahasiswa\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

Node *createNode(int NIM, char *Nama, char *Jurusan)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->NIM = NIM;
    strcpy(newNode->Nama, Nama);
    strcpy(newNode->Jurusan, Jurusan);
    newNode->Left = newNode->Right = NULL;
    return newNode;
}

Node *insert(Node *root, int NIM, char *Nama, char *Jurusan)
{
    if (root == NULL)
        return createNode(NIM, Nama, Jurusan);
    if (NIM < root->NIM)
        root->Left = insert(root->Left, NIM, Nama, Jurusan);
    else if (NIM > root->NIM)
        root->Right = insert(root->Right, NIM, Nama, Jurusan);
    return root;
}

Node *search(Node *root, int NIM)
{
    if (root == NULL || root->NIM == NIM)
        return root;
    if (NIM < root->NIM)
        return search(root->Left, NIM);
    else
        return search(root->Right, NIM);
}

Node *findMin(Node *root)
{
    while (root->Left != NULL)
        root = root->Left;
    return root;
}

Node *deleteNode(Node *root, int NIM)
{
    if (root == NULL)
        return root;
    if (NIM < root->NIM)
        root->Left = deleteNode(root->Left, NIM);
    else if (NIM > root->NIM)
        root->Right = deleteNode(root->Right, NIM);
    else
    {
        if (root->Left == NULL)
        {
            Node *temp = root->Right;
            free(root);
            return temp;
        }
        else if (root->Right == NULL)
        {
            Node *temp = root->Left;
            free(root);
            return temp;
        }

        Node *temp = findMin(root->Right);
        root->NIM = temp->NIM;
        strcpy(root->Nama, temp->Nama);
        strcpy(root->Jurusan, temp->Jurusan);
        root->Right = deleteNode(root->Right, temp->NIM);
    }
    return root;
}

void inOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->Left);
        printf("NIM: %d | Nama: %s | Jurusan: %s\n", root->NIM, root->Nama, root->Jurusan);
        inOrderTraversal(root->Right);
    }
}
