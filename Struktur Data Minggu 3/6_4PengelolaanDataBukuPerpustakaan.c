/*
Nama File      	: 6_4PengelolaanDataBukuPerpustakaan.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi      	: Penerapan Singly Linked List dalam Studi Kasus
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main();
void judul();
typedef struct Node
{
    char kode[10];
    char judul[100];
    char penulis[50];
    struct Node *next;
} Node;
void tambahBuku(Node **head, const char *kode, const char *judul, const char *penulis);
void tampilkanBuku(Node *head);
void hapusBuku(Node **head, const char *kode);
void cariBuku(Node *head, const char *kode);

int main()
{
    judul();
    Node *head = NULL;

    while (1)
    {
        printf("\nMenu Pengelolaan Data Buku:\n");
        printf("1. Tambah Buku\n");
        printf("2. Tampilkan Buku\n");
        printf("3. Hapus Buku\n");
        printf("4. Cari Buku\n");
        printf("5. Keluar\n");
        printf("Pilih operasi: ");
        int pilihan;
        scanf("%d", &pilihan);

        if (pilihan == 5)
            break;

        char kode[10], judul[100], penulis[50];

        switch (pilihan)
        {
        case 1:
            printf("Masukkan Kode Buku: ");
            scanf(" %[^\n]s", kode);
            printf("Masukkan Judul Buku: ");
            scanf(" %[^\n]s", judul);
            printf("Masukkan Penulis Buku: ");
            scanf(" %[^\n]s", penulis);
            tambahBuku(&head, kode, judul, penulis);
            break;
        case 2:
            tampilkanBuku(head);
            break;
        case 3:
            printf("Masukkan Kode Buku yang ingin dihapus: ");
            scanf(" %[^\n]s", kode);
            hapusBuku(&head, kode);
            break;
        case 4:
            printf("Masukkan Kode Buku yang ingin dicari: ");
            scanf(" %[^\n]s", kode);
            cariBuku(head, kode);
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }
    }

    // Bebaskan memori sisa
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

void judul()
{
    printf("Nama Program  : Pengelolaan Data Buku Perpustakaan Menggunakan Singly Linked List \n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

// Tambah buku baru ke daftar
void tambahBuku(Node **head, const char *kode, const char *judul, const char *penulis)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    snprintf(newNode->kode, sizeof(newNode->kode), "%s", kode);
    snprintf(newNode->judul, sizeof(newNode->judul), "%s", judul);
    snprintf(newNode->penulis, sizeof(newNode->penulis), "%s", penulis);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Buku dengan kode %s berhasil ditambahkan.\n", kode);
}

// Tampilkan seluruh buku
void tampilkanBuku(Node *head)
{
    if (head == NULL)
    {
        printf("Tidak ada buku dalam daftar.\n");
        return;
    }

    Node *current = head;
    printf("Daftar Buku:\n");
    while (current != NULL)
    {
        printf("Kode: %s, Judul: %s, Penulis: %s\n",
               current->kode, current->judul, current->penulis);
        current = current->next;
    }
}

// Hapus buku berdasarkan kode
void hapusBuku(Node **head, const char *kode)
{
    if (*head == NULL)
    {
        printf("Tidak ada buku dalam daftar untuk dihapus.\n");
        return;
    }

    Node *current = *head, *prev = NULL;

    // Jika buku pertama yang dihapus
    if (strcmp(current->kode, kode) == 0)
    {
        *head = current->next;
        free(current);
        printf("Buku dengan kode %s berhasil dihapus.\n", kode);
        return;
    }

    while (current != NULL && strcmp(current->kode, kode) != 0)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Buku dengan kode %s tidak ditemukan.\n", kode);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Buku dengan kode %s berhasil dihapus.\n", kode);
}

// Cari buku berdasarkan kode
void cariBuku(Node *head, const char *kode)
{
    Node *current = head;

    while (current != NULL)
    {
        if (strcmp(current->kode, kode) == 0)
        {
            printf("Buku ditemukan! Kode: %s, Judul: %s, Penulis: %s\n",
                   current->kode, current->judul, current->penulis);
            return;
        }
        current = current->next;
    }
    printf("Buku dengan kode %s tidak ditemukan.\n", kode);
}
