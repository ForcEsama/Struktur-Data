/*
Nama File       : 6_7SistemPemesananTiketBioskop.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi       : Penerapan Circular Doubly Linked List dalam Studi Kasus
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define true 1
#define false 0

int main();
void judul();
typedef struct Node
{
    int nomorKursi;
    bool tersedia; // True jika kursi tersedia, False jika sudah dipesan
    struct Node *prev;
    struct Node *next;
} Node;
void tambahKursi(Node **head, Node **tail, int nomorKursi);
void tampilkanKursi(Node *head);
void pilihKursi(Node *head, int nomorKursi);
void hapusKursi(Node **head, Node **tail, int nomorKursi);

int main()
{
    judul();
    Node *head = NULL;
    Node *tail = NULL;

    // Tambah kursi
    tambahKursi(&head, &tail, 1);
    tambahKursi(&head, &tail, 2);
    tambahKursi(&head, &tail, 3);

    // Tampilkan kursi
    tampilkanKursi(head);

    // Pilih kursi
    printf("\nPilih kursi 2:\n");
    pilihKursi(head, 2);

    // Tampilkan daftar setelah pemilihan kursi
    printf("\nDaftar kursi setelah pemilihan:\n");
    tampilkanKursi(head);

    // Hapus kursi
    printf("\nHapus kursi 3:\n");
    hapusKursi(&head, &tail, 3);

    // Tampilkan daftar setelah penghapusan kursi
    printf("\nDaftar kursi setelah penghapusan:\n");
    tampilkanKursi(head);

    return 0;
}

void judul()
{
    printf("Nama Program  : Sistem Pemesanan Tiket Bioskop Menggunakan Circular Doubly Linked List\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n\n");
}

// Tambah kursi baru
void tambahKursi(Node **head, Node **tail, int nomorKursi)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->nomorKursi = nomorKursi;
    newNode->tersedia = true; // Semua kursi baru dianggap tersedia
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

    printf("Kursi %d berhasil ditambahkan.\n", nomorKursi);
}

// Tampilkan daftar kursi
void tampilkanKursi(Node *head)
{
    if (head == NULL)
    {
        printf("Tidak ada kursi yang tersedia.\n");
        return;
    }

    Node *current = head;
    printf("Daftar Kursi:\n");
    do
    {
        printf("Kursi %d [%s]\n", current->nomorKursi, current->tersedia ? "Tersedia" : "Sudah Dipesan");
        current = current->next;
    } while (current != head);
}

// Pilih kursi
void pilihKursi(Node *head, int nomorKursi)
{
    if (head == NULL)
    {
        printf("Tidak ada kursi untuk dipilih.\n");
        return;
    }

    Node *current = head;

    do
    {
        if (current->nomorKursi == nomorKursi)
        {
            if (current->tersedia)
            {
                printf("Kursi %d berhasil dipilih.\n", nomorKursi);
                current->tersedia = false;
            }
            else
            {
                printf("Kursi %d sudah dipesan.\n", nomorKursi);
            }
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Kursi %d tidak ditemukan.\n", nomorKursi);
}

// Hapus kursi dari daftar
void hapusKursi(Node **head, Node **tail, int nomorKursi)
{
    if (*head == NULL)
    {
        printf("Tidak ada kursi untuk dihapus.\n");
        return;
    }

    Node *current = *head;

    do
    {
        if (current->nomorKursi == nomorKursi)
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

            printf("Kursi %d berhasil dihapus.\n", nomorKursi);
            free(current);
            return;
        }
        current = current->next;
    } while (current != *head);

    printf("Kursi %d tidak ditemukan.\n", nomorKursi);
}
