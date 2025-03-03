/*
Nama File      	: 3_6BacaData.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi      	: Baca Data Doubly Linked List
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
void bacaDataBerdasarkanIndeks(Node *head, int indeks);
void bacaDataBerdasarkanNilai(Node *head, int nilai);

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

    // Baca data berdasarkan indeks
    printf("\nMembaca data pada indeks 1:\n");
    bacaDataBerdasarkanIndeks(head, 1);

    // Baca data berdasarkan nilai
    printf("\nMembaca data dengan nilai 30:\n");
    bacaDataBerdasarkanNilai(head, 30);

    printf("\nMembaca data dengan nilai 50:\n");
    bacaDataBerdasarkanNilai(head, 50);

    return 0;
}

void judul()
{
    printf("Nama Program  : Baca Data Doubly Linked List\n");
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

void bacaDataBerdasarkanIndeks(Node *head, int indeks)
{
    if (head == NULL)
    {
        printf("List kosong.\n");
        return;
    }

    Node *current = head;
    int count = 0;

    while (current != NULL)
    {
        if (count == indeks)
        {
            printf("Data pada indeks %d adalah: %d\n", indeks, current->data);
            return;
        }
        current = current->next;
        count++;
    }

    printf("Indeks %d tidak valid.\n", indeks);
}

void bacaDataBerdasarkanNilai(Node *head, int nilai)
{
    if (head == NULL)
    {
        printf("List kosong.\n");
        return;
    }

    Node *current = head;

    while (current != NULL)
    {
        if (current->data == nilai)
        {
            printf("Data ditemukan: %d\n", current->data);
            return;
        }
        current = current->next;
    }

    printf("Data %d tidak ditemukan.\n", nilai);
}
