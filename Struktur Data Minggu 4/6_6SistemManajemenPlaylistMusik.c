/*
Nama File       : 6_6SistemManajemenPlaylistMusik.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi       : Penggunaan Doubly Linked List dalam Studi Kasus
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main();
void judul();
typedef struct Node
{
    char judul[100];
    char artis[100];
    struct Node *prev;
    struct Node *next;
} Node;
void tambahLagu(Node **head, Node **tail, const char *judul, const char *artis);
void tampilkanPlaylist(Node *head);
void navigasiKeLaguBerikutnya(Node **current);
void navigasiKeLaguSebelumnya(Node **current);
void hapusLagu(Node **head, Node **tail, int indeks);

int main()
{
    judul();
    Node *head = NULL;
    Node *tail = NULL;
    Node *current = NULL;

    // Tambah lagu ke playlist
    tambahLagu(&head, &tail, "Shape of You", "Ed Sheeran");
    tambahLagu(&head, &tail, "Blinding Lights", "The Weeknd");
    tambahLagu(&head, &tail, "Levitating", "Dua Lipa");

    // Tampilkan playlist
    tampilkanPlaylist(head);

    // Navigasi antar lagu
    current = head; // Mulai dari lagu pertama
    printf("\nNavigasi lagu:\n");
    navigasiKeLaguBerikutnya(&current); // Lagu berikutnya
    navigasiKeLaguBerikutnya(&current); // Lagu berikutnya
    navigasiKeLaguBerikutnya(&current); // Tidak bisa ke depan lagi~
    navigasiKeLaguSebelumnya(&current); // Lagu sebelumnya

    // Hapus lagu
    printf("\nHapus lagu pada indeks 1:\n");
    hapusLagu(&head, &tail, 1);

    // Tampilkan playlist setelah penghapusan
    tampilkanPlaylist(head);

    return 0;
}

void judul()
{
    printf("Nama Program  : Sistem Manajemen Playlist Musik Menggunakan Doubly Linked List\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n\n");
}

// Tambah lagu ke playlist
void tambahLagu(Node **head, Node **tail, const char *judul, const char *artis)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    snprintf(newNode->judul, sizeof(newNode->judul), "%s", judul);
    snprintf(newNode->artis, sizeof(newNode->artis), "%s", artis);
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
    printf("Lagu '%s' oleh '%s' berhasil ditambahkan ke playlist.\n", judul, artis);
}

// Tampilkan playlist
void tampilkanPlaylist(Node *head)
{
    if (head == NULL)
    {
        printf("Playlist kosong.\n");
        return;
    }

    Node *current = head;
    printf("Playlist Musik:\n");
    while (current != NULL)
    {
        printf("Lagu: '%s', Artis: '%s'\n", current->judul, current->artis);
        current = current->next;
    }
}

// Navigasi ke lagu berikutnya
void navigasiKeLaguBerikutnya(Node **current)
{
    if (*current == NULL)
    {
        printf("Playlist kosong.\n");
        return;
    }

    if ((*current)->next != NULL)
    {
        *current = (*current)->next;
        printf("Sekarang memutar lagu: '%s' oleh '%s'.\n", (*current)->judul, (*current)->artis);
    }
    else
    {
        printf("Sudah berada di akhir playlist.\n");
    }
}

// Navigasi ke lagu sebelumnya
void navigasiKeLaguSebelumnya(Node **current)
{
    if (*current == NULL)
    {
        printf("Playlist kosong.\n");
        return;
    }

    if ((*current)->prev != NULL)
    {
        *current = (*current)->prev;
        printf("Sekarang memutar lagu: '%s' oleh '%s'.\n", (*current)->judul, (*current)->artis);
    }
    else
    {
        printf("Sudah berada di awal playlist.\n");
    }
}

// Hapus lagu berdasarkan indeks
void hapusLagu(Node **head, Node **tail, int indeks)
{
    if (*head == NULL)
    {
        printf("Playlist kosong. Tidak ada lagu untuk dihapus.\n");
        return;
    }

    Node *current = *head;
    int count = 0;

    while (current != NULL)
    {
        if (count == indeks)
        {
            if (current == *head)
            {
                *head = current->next;
                if (*head != NULL)
                {
                    (*head)->prev = NULL;
                }
                else
                {
                    *tail = NULL; // Jika playlist kosong setelah penghapusan
                }
            }
            else if (current == *tail)
            {
                *tail = current->prev;
                (*tail)->next = NULL;
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            printf("Lagu '%s' oleh '%s' berhasil dihapus.\n", current->judul, current->artis);
            free(current);
            return;
        }
        current = current->next;
        count++;
    }

    printf("Indeks %d tidak valid.\n", indeks);
}
