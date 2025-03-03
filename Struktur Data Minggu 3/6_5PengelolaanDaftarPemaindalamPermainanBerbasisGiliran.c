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
    int idPemain;
    char nama[50];
    struct Node *next;
} Node;
void tambahPemain(Node **head, int idPemain, const char *nama);
void tampilkanPemain(Node *head);
void hapusPemain(Node **head, int idPemain);
void giliranPemainBerikutnya(Node **current);

int main()
{
    judul();
    Node *head = NULL;
    Node *current = NULL;

    while (1)
    {
        printf("\nMenu Sistem Giliran Pemain:\n");
        printf("1. Tambah Pemain\n");
        printf("2. Tampilkan Pemain\n");
        printf("3. Hapus Pemain\n");
        printf("4. Giliran Pemain Berikutnya\n");
        printf("5. Keluar\n");
        printf("Pilih operasi: ");
        int pilihan;
        scanf("%d", &pilihan);

        if (pilihan == 5)
            break;

        int idPemain;
        char nama[50];

        switch (pilihan)
        {
        case 1:
            printf("Masukkan ID Pemain: ");
            scanf("%d", &idPemain);
            printf("Masukkan Nama Pemain: ");
            scanf(" %[^\n]s", nama);
            tambahPemain(&head, idPemain, nama);
            if (current == NULL)
            {
                current = head;
            }
            break;
        case 2:
            tampilkanPemain(head);
            break;
        case 3:
            printf("Masukkan ID Pemain yang Ingin Dihapus: ");
            scanf("%d", &idPemain);
            hapusPemain(&head, idPemain);
            if (current != NULL && current->idPemain == idPemain)
            {
                current = head;
            }
            break;
        case 4:
            giliranPemainBerikutnya(&current);
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }
    }

    // Bebaskan memori sisa
    while (head != NULL)
    {
        hapusPemain(&head, head->idPemain);
    }

    return 0;
}

void judul()
{
    printf("Nama Program  : Pengelolaan Daftar Pemain dalam Permainan Berbasis Giliran Menggunakan Circular Singly Linked List\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

// Tambah pemain baru
void tambahPemain(Node **head, int idPemain, const char *nama)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->idPemain = idPemain;
    snprintf(newNode->nama, sizeof(newNode->nama), "%s", nama);

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

    printf("Pemain dengan ID %d berhasil ditambahkan.\n", idPemain);
}

// Tampilkan daftar pemain
void tampilkanPemain(Node *head)
{
    if (head == NULL)
    {
        printf("Tidak ada pemain dalam permainan.\n");
        return;
    }

    Node *current = head;
    printf("Daftar Pemain:\n");
    do
    {
        printf("ID: %d, Nama: %s\n", current->idPemain, current->nama);
        current = current->next;
    } while (current != head);
}

// Hapus pemain berdasarkan ID
void hapusPemain(Node **head, int idPemain)
{
    if (*head == NULL)
    {
        printf("Tidak ada pemain untuk dihapus.\n");
        return;
    }

    Node *current = *head;
    Node *prev = NULL;

    if (current->idPemain == idPemain && current->next == *head)
    {
        free(current);
        *head = NULL;
        printf("Pemain dengan ID %d telah dihapus.\n", idPemain);
        return;
    }

    do
    {
        if (current->idPemain == idPemain)
        {
            if (prev == NULL)
            {
                Node *temp = *head;
                while (current->next != *head)
                {
                    current = current->next;
                }
                current->next = (*head)->next;
                *head = (*head)->next;
                free(temp);
            }
            else
            {
                prev->next = current->next;
                free(current);
            }
            printf("Pemain dengan ID %d telah dihapus.\n", idPemain);
            return;
        }
        prev = current;
        current = current->next;
    } while (current != *head);

    printf("Pemain dengan ID %d tidak ditemukan.\n", idPemain);
}

// Tentukan giliran pemain berikutnya
void giliranPemainBerikutnya(Node **current)
{
    if (*current == NULL)
    {
        printf("Tidak ada pemain dalam permainan.\n");
        return;
    }

    printf("Giliran pemain: ID %d, Nama: %s\n", (*current)->idPemain, (*current)->nama);
    *current = (*current)->next;
}
