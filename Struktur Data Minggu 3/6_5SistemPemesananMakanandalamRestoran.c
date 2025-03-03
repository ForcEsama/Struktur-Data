/*
Nama File      	: 6_5SistemPemesananMakanandalamRestoran.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi      	: Penerapan Circular Singly Linked List dalam Studi Kasus
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main();
void judul();
typedef struct Node
{
    int nomorPesanan;
    char namaPelanggan[50];
    char daftarMenu[100];
    struct Node *next;
} Node;
void tambahPesanan(Node **head, int nomorPesanan, const char *namaPelanggan, const char *daftarMenu);
void tampilkanPesanan(Node *head);
void prosesPesanan(Node **head);
void perbaruiPesanan(Node *head, int nomorPesanan, const char *namaBaru, const char *menuBaru);

int main()
{
    judul();
    Node *head = NULL;

    while (1)
    {
        printf("\nMenu Sistem Pemesanan Makanan:\n");
        printf("1. Tambah Pesanan\n");
        printf("2. Tampilkan Pesanan\n");
        printf("3. Proses Pesanan\n");
        printf("4. Perbarui Pesanan\n");
        printf("5. Keluar\n");
        printf("Pilih operasi: ");
        int pilihan;
        scanf("%d", &pilihan);

        if (pilihan == 5)
            break;

        int nomorPesanan;
        char namaPelanggan[50];
        char daftarMenu[100];

        switch (pilihan)
        {
        case 1:
            printf("Masukkan Nomor Pesanan: ");
            scanf("%d", &nomorPesanan);
            printf("Masukkan Nama Pelanggan: ");
            scanf(" %[^\n]s", namaPelanggan);
            printf("Masukkan Daftar Menu: ");
            scanf(" %[^\n]s", daftarMenu);
            tambahPesanan(&head, nomorPesanan, namaPelanggan, daftarMenu);
            break;
        case 2:
            tampilkanPesanan(head);
            break;
        case 3:
            prosesPesanan(&head);
            break;
        case 4:
            printf("Masukkan Nomor Pesanan yang Ingin Diperbarui: ");
            scanf("%d", &nomorPesanan);
            printf("Masukkan Nama Baru: ");
            scanf(" %[^\n]s", namaPelanggan);
            printf("Masukkan Menu Baru: ");
            scanf(" %[^\n]s", daftarMenu);
            perbaruiPesanan(head, nomorPesanan, namaPelanggan, daftarMenu);
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }
    }

    // Bebaskan memori sisa
    while (head != NULL)
    {
        prosesPesanan(&head);
    }

    return 0;
}

void judul()
{
    printf("Nama Program  : Sistem Pemesanan Makanan dalam Restoran Menggunakan Circular Singly Linked List\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

// Tambah pesanan baru
void tambahPesanan(Node **head, int nomorPesanan, const char *namaPelanggan, const char *daftarMenu)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->nomorPesanan = nomorPesanan;
    snprintf(newNode->namaPelanggan, sizeof(newNode->namaPelanggan), "%s", namaPelanggan);
    snprintf(newNode->daftarMenu, sizeof(newNode->daftarMenu), "%s", daftarMenu);

    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != *head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }

    printf("Pesanan dengan nomor %d berhasil ditambahkan.\n", nomorPesanan);
}

// Tampilkan semua pesanan
void tampilkanPesanan(Node *head)
{
    if (head == NULL)
    {
        printf("Tidak ada pesanan yang aktif.\n");
        return;
    }

    Node *current = head;
    printf("Daftar Pesanan:\n");
    do
    {
        printf("Nomor: %d, Nama: %s, Menu: %s\n",
               current->nomorPesanan, current->namaPelanggan, current->daftarMenu);
        current = current->next;
    } while (current != head);
}

// Proses pesanan pertama
void prosesPesanan(Node **head)
{
    if (*head == NULL)
    {
        printf("Tidak ada pesanan untuk diproses.\n");
        return;
    }

    Node *current = *head;

    if (current->next == *head)
    {
        printf("Pesanan dengan nomor %d telah diproses.\n", current->nomorPesanan);
        free(current);
        *head = NULL;
        return;
    }

    while (current->next != *head)
    {
        current = current->next;
    }

    Node *temp = *head;
    current->next = (*head)->next;
    *head = (*head)->next;
    printf("Pesanan dengan nomor %d telah diproses.\n", temp->nomorPesanan);
    free(temp);
}

// Perbarui data pesanan
void perbaruiPesanan(Node *head, int nomorPesanan, const char *namaBaru, const char *menuBaru)
{
    if (head == NULL)
    {
        printf("Tidak ada pesanan yang dapat diperbarui.\n");
        return;
    }

    Node *current = head;
    do
    {
        if (current->nomorPesanan == nomorPesanan)
        {
            snprintf(current->namaPelanggan, sizeof(current->namaPelanggan), "%s", namaBaru);
            snprintf(current->daftarMenu, sizeof(current->daftarMenu), "%s", menuBaru);
            printf("Pesanan dengan nomor %d berhasil diperbarui.\n", nomorPesanan);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Pesanan dengan nomor %d tidak ditemukan.\n", nomorPesanan);
}
