/*
Nama File       : 3_7BacaDataCircularDoublyLinkedList.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi       : Baca Data Circular Doubly Linked List
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
void tambahDiAwal(Node **head, Node **tail, int data);
void tambahDiAkhir(Node **head, Node **tail, int data);
void bacaDataBerdasarkanIndeks(Node *head, int indeks);
void bacaDataBerdasarkanNilai(Node *head, int nilai);

int main()
{
    judul();
    Node *head = NULL;
    Node *tail = NULL;

    // Tambah data untuk contoh
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
    printf("Nama Program  : Baca Data Circular Doubly Linked List\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n\n");
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
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(kembali ke head)\n");
}

void tambahDiAwal(Node **head, Node **tail, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

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
        (*head)->prev = newNode;
        (*tail)->next = newNode;
        *head = newNode;
    }

    printf("Node dengan data %d berhasil ditambahkan di awal.\n", data);
}

void tambahDiAkhir(Node **head, Node **tail, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

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
        (*head)->prev = newNode;
        (*tail)->next = newNode;
        *tail = newNode;
    }

    printf("Node dengan data %d berhasil ditambahkan di akhir.\n", data);
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

    do
    {
        if (count == indeks)
        {
            printf("Data pada indeks %d adalah: %d\n", indeks, current->data);
            return;
        }
        current = current->next;
        count++;
    } while (current != head);

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

    do
    {
        if (current->data == nilai)
        {
            printf("Data ditemukan: %d\n", current->data);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Data %d tidak ditemukan.\n", nilai);
}
