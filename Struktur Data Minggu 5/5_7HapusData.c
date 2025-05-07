/*
Nama File       : 5_7HapusDataCircularDoublyLinkedList.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi       : Hapus Data Circular Doubly Linked List
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
void hapusDataBerdasarkanIndeks(Node **head, Node **tail, int indeks);

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

    // Hapus data berdasarkan indeks
    printf("\nMenghapus data pada indeks 1:\n");
    hapusDataBerdasarkanIndeks(&head, &tail, 1);

    // Tampilkan hasil penghapusan
    traversalKeDepan(head);
    traversalKeBelakang(tail);

    return 0;
}

void judul()
{
    printf("Nama Program  : Hapus Data Circular Doubly Linked List\n");
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
    do
    {
        printf("%d -> ", current->data);
        current = current->prev;
    } while (current != tail);
    printf("(kembali ke tail)\n");
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

void hapusDataBerdasarkanIndeks(Node **head, Node **tail, int indeks)
{
    if (*head == NULL)
    {
        printf("List kosong. Tidak ada data untuk dihapus.\n");
        return;
    }

    Node *current = *head;
    int count = 0;

    do
    {
        if (count == indeks)
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

            printf("Node pada indeks %d berhasil dihapus.\n", indeks);
            free(current);
            return;
        }
        current = current->next;
        count++;
    } while (current != *head);

    printf("Indeks %d tidak valid.\n", indeks);
}
