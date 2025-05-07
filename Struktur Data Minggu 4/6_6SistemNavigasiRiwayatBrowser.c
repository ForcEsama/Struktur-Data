/*
Nama File       : 6_6SistemNavigasiRiwayatBrowser.c
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
    char data[100];
    struct Node *prev;
    struct Node *next;
} Node;
void tambahRiwayat(Node **head, Node **tail, const char *url);
void tampilkanRiwayat(Node *head);

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    judul();

    // Tambah riwayat
    tambahRiwayat(&head, &tail, "www.google.com");
    tambahRiwayat(&head, &tail, "www.github.com");
    tambahRiwayat(&head, &tail, "www.stackoverflow.com");

    tampilkanRiwayat(head);

    return 0;
}

void judul()
{
    printf("Nama Program  : Sistem Navigasi Riwayat Browser Menggunakan Doubly Linked List\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n\n");
}

void tambahRiwayat(Node **head, Node **tail, const char *url)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Gagal mengalokasikan memori.\n");
        return;
    }

    // Salin URL ke data node
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
