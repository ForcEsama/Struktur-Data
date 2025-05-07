/*
Nama File       : 6_7SistemPengelolaanTImOlahraga.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi       : Penerapan Circular Doubly Linked List dalam Studi Kasus
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main();
void judul();
typedef struct Node
{
    char nama[50];
    int nomorPunggung;
    char posisi[30];
    struct Node *prev;
    struct Node *next;
} Node;
void tambahPemain(Node **head, Node **tail, const char *nama, int nomorPunggung, const char *posisi);
void tampilkanPemain(Node *head);
void cariPemain(Node *head, int nomorPunggung);
void hapusPemain(Node **head, Node **tail, int nomorPunggung);

int main()
{
    judul();
    Node *head = NULL;
    Node *tail = NULL;

    // Tambah pemain
    tambahPemain(&head, &tail, "John", 10, "Penyerang");
    tambahPemain(&head, &tail, "Alex", 7, "Gelandang");
    tambahPemain(&head, &tail, "Chris", 4, "Bek");

    // Tampilkan daftar pemain
    tampilkanPemain(head);

    // Cari pemain
    printf("\nMencari pemain dengan nomor punggung 7:\n");
    cariPemain(head, 7);

    // Hapus pemain
    printf("\nMenghapus pemain dengan nomor punggung 10:\n");
    hapusPemain(&head, &tail, 10);

    // Tampilkan daftar pemain setelah penghapusan
    printf("\nDaftar pemain setelah penghapusan:\n");
    tampilkanPemain(head);

    return 0;
}

void judul()
{
    printf("Nama Program  : Sistem Pengelolaan Tim Olahraga Menggunakan Circular Doubly Linked List\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n\n");
}

// Tambah pemain baru
void tambahPemain(Node **head, Node **tail, const char *nama, int nomorPunggung, const char *posisi)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    snprintf(newNode->nama, sizeof(newNode->nama), "%s", nama);
    newNode->nomorPunggung = nomorPunggung;
    snprintf(newNode->posisi, sizeof(newNode->posisi), "%s", posisi);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL)
    {
        newNode->prev = newNode;
        newNode->next = newNode;
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        newNode->prev = *tail;
        newNode->next = *head;
        (*tail)->next = newNode;
        (*head)->prev = newNode;
        *tail = newNode;
    }

    printf("Pemain '%s' dengan nomor punggung %d berhasil ditambahkan.\n", nama, nomorPunggung);
}

// Tampilkan daftar pemain
void tampilkanPemain(Node *head)
{
    if (head == NULL)
    {
        printf("Daftar pemain kosong.\n");
        return;
    }

    Node *current = head;
    printf("Daftar Pemain Tim:\n");
    do
    {
        printf("Nama: %s, Nomor Punggung: %d, Posisi: %s\n", current->nama, current->nomorPunggung, current->posisi);
        current = current->next;
    } while (current != head);
}

// Cari pemain berdasarkan nomor punggung
void cariPemain(Node *head, int nomorPunggung)
{
    if (head == NULL)
    {
        printf("Daftar pemain kosong.\n");
        return;
    }

    Node *current = head;

    do
    {
        if (current->nomorPunggung == nomorPunggung)
        {
            printf("Pemain ditemukan: Nama: %s, Nomor Punggung: %d, Posisi: %s\n",
                   current->nama, current->nomorPunggung, current->posisi);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Pemain dengan nomor punggung %d tidak ditemukan.\n", nomorPunggung);
}

// Hapus pemain dari daftar
void hapusPemain(Node **head, Node **tail, int nomorPunggung)
{
    if (*head == NULL)
    {
        printf("Daftar pemain kosong. Tidak ada pemain untuk dihapus.\n");
        return;
    }

    Node *current = *head;

    do
    {
        if (current->nomorPunggung == nomorPunggung)
        {
            if (current == *head)
            {
                *head = current->next;
                (*head)->prev = *tail;
                (*tail)->next = *head;
            }
            else if (current == *tail)
            {
                *tail = current->prev;
                (*tail)->next = *head;
                (*head)->prev = *tail;
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            printf("Pemain '%s' dengan nomor punggung %d berhasil dihapus.\n", current->nama, nomorPunggung);
            free(current);
            return;
        }
        current = current->next;
    } while (current != *head);

    printf("Pemain dengan nomor punggung %d tidak ditemukan.\n", nomorPunggung);
}
