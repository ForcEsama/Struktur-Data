/*
Nama File       : 6_6SistemNavigasiRiwayatBrowser2.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi       : Penggunaan Doubly Linked List dalam Studi Kasus
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data[100];
    struct Node *prev;
    struct Node *next;
} Node;

// Prototipe fungsi
void judul();
void tambahRiwayat(Node **head, Node **tail, const char *url);
void tampilkanRiwayat(Node *head);
void navigasiKeDepan(Node **current);
void navigasiKeBelakang(Node **current);

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *current = NULL;

    judul();

    // Tambah riwayat
    tambahRiwayat(&head, &tail, "www.google.com");
    tambahRiwayat(&head, &tail, "www.github.com");
    tambahRiwayat(&head, &tail, "www.stackoverflow.com");

    tampilkanRiwayat(head);

    current = head; // Mulai dari head

    // Navigasi ke depan
    printf("\nNavigasi ke depan:\n");
    navigasiKeDepan(&current); // Ke URL berikutnya
    navigasiKeDepan(&current); // Ke URL berikutnya
    navigasiKeDepan(&current); // Tidak bisa ke depan lagi

    // Navigasi ke belakang
    printf("\nNavigasi ke belakang:\n");
    navigasiKeBelakang(&current); // Ke URL sebelumnya
    navigasiKeBelakang(&current); // Ke URL sebelumnya
    navigasiKeBelakang(&current); // Tidak bisa ke belakang lagi

    return 0;
}

// Fungsi untuk mencetak judul program
void judul()
{
    printf("Nama Program  : Sistem Navigasi Riwayat Browser Menggunakan Doubly Linked List Operasi Navigasi ke Depan dan Belakang\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("NIM           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n\n");
}

// Fungsi untuk menambahkan riwayat ke dalam list
void tambahRiwayat(Node **head, Node **tail, const char *url)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Gagal mengalokasikan memori.\n");
        return;
    }

    strncpy(newNode->data, url, sizeof(newNode->data) - 1);
    newNode->data[sizeof(newNode->data) - 1] = '\0'; // Pastikan string diakhiri null
    newNode->prev = *tail;
    newNode->next = NULL;

    if (*tail != NULL)
    {
        (*tail)->next = newNode;
    }
    else
    {
        *head = newNode;
    }

    *tail = newNode;
}

// Fungsi untuk menampilkan seluruh riwayat
void tampilkanRiwayat(Node *head)
{
    if (head == NULL)
    {
        printf("Riwayat kosong.\n");
        return;
    }

    Node *current = head;
    printf("Riwayat Browser:\n");
    while (current != NULL)
    {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Fungsi untuk navigasi ke depan
void navigasiKeDepan(Node **current)
{
    if (*current == NULL)
    {
        printf("Tidak ada riwayat untuk dinavigasi.\n");
        return;
    }

    if ((*current)->next != NULL)
    {
        *current = (*current)->next;
        printf("Berpindah ke URL berikutnya: %s\n", (*current)->data);
    }
    else
    {
        printf("Sudah berada di akhir riwayat.\n");
    }
}

// Fungsi untuk navigasi ke belakang
void navigasiKeBelakang(Node **current)
{
    if (*current == NULL)
    {
        printf("Tidak ada riwayat untuk dinavigasi.\n");
        return;
    }

    if ((*current)->prev != NULL)
    {
        *current = (*current)->prev;
        printf("Berpindah ke URL sebelumnya: %s\n", (*current)->data);
    }
    else
    {
        printf("Sudah berada di awal riwayat.\n");
    }
}
