/*
Nama File       : 4_7UpdateDataCircularDoublyLinkedList.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi       : Update Data Circular Doubly Linked List
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
    printf("Nama Program  : Update Data Circular Doubly Linked List\n");
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

void updateDataBerdasarkanIndeks(Node *head, int indeks, int nilaiBaru)
{
    if (head == NULL)
    {
        printf("List kosong. Tidak ada data untuk diperbarui.\n");
        return;
    }

    Node *current = head;
    int count = 0;

    do
    {
        if (count == indeks)
        {
            current->data = nilaiBaru;
            printf("Data pada indeks %d berhasil diperbarui menjadi %d.\n", indeks, nilaiBaru);
            return;
        }
        current = current->next;
        count++;
    } while (current != head);

    printf("Indeks %d tidak valid.\n", indeks);
}
