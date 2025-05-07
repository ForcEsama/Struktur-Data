/*
Nama File      	: 4_6UpdateData.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi      	: Update Data Doubly Linked List
*/

#include <stdio.h>
#include <stdlib.h>

int main();
void judul();
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;
void traversalKeDepan(Node *head);
void traversalKeBelakang(Node *tail);
void tambahDiAwal(Node **head, Node **tail, int data);
void tambahDiAkhir(Node **head, Node **tail, int data);
void updateDataBerdasarkanIndeks(Node *head, int indeks, int nilaiBaru);

int main()
{
    judul();
    Node *head = NULL;
    Node *tail = NULL;

    // Tambah data
    tambahDiAwal(&head, &tail, 20);
    tambahDiAwal(&head, &tail, 10);
    tambahDiAkhir(&head, &tail, 30);

    traversalKeDepan(head);

    // Update data berdasarkan indeks
    printf("\nMemperbarui data pada indeks 1 menjadi 25:\n");
    updateDataBerdasarkanIndeks(head, 1, 25);

    // Tampilkan hasil update
    traversalKeDepan(head);

    return 0;
}

void judul()
{
    printf("Nama Program  : Update Data Doubly Linked List\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

// Traversal ke depan
void traversalKeDepan(Node *head)
{
    if (head == NULL)
    {
        printf("List kosong.\n");
        return;
    }

    Node *current = head;
    printf("Traversal ke Depan:\n");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next; // geserkan ke belakangnya
    }
    printf("NULL\n");
}

// Traversal ke belakang
void traversalKeBelakang(Node *tail)
{
    if (tail == NULL)
    {
        printf("List kosong.\n");
        return;
    }

    Node *current = tail;
    printf("Traversal ke Belakang:\n");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

void tambahDiAwal(Node **head, Node **tail, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    else
    {
        *tail = newNode; // Jika list kosong, tail juga diperbarui
    }

    *head = newNode;
}

void tambahDiAkhir(Node **head, Node **tail, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = *tail;

    if (*tail != NULL)
    {
        (*tail)->next = newNode;
    }
    else
    {
        *head = newNode; // Jika list kosong, head juga diperbarui
    }

    *tail = newNode;
}

void updateDataBerdasarkanIndeks(Node *head, int indeks, int nilaiBaru)
{
    if (head == NULL)
    {
        printf("List kosong. Tidak ada data untuk diperbarui.\n");
        return;
    }

    Node *current = head;
    int count = 0;

    while (current != NULL)
    {
        if (count == indeks)
        {
            current->data = nilaiBaru;
            printf("Data pada indeks %d berhasil diperbarui menjadi %d.\n", indeks, nilaiBaru);
            return;
        }
        current = current->next;
        count++;
    }

    printf("Indeks %d tidak valid.\n", indeks);
}
