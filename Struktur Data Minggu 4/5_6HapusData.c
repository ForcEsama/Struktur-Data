/*
Nama File      	: 5_6HapusData.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi      	: Hapus Data Doubly Linked List
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
    printf("Nama Program  : Hapus Data Doubly Linked List\n");
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
void hapusDataBerdasarkanIndeks(Node **head, Node **tail, int indeks)
{
    if (*head == NULL)
    {
        printf("List kosong. Tidak ada data untuk dihapus.\n");
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
                    *tail = NULL; // Jika list kosong setelah penghapusan
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

            free(current);
            printf("Node pada indeks %d berhasil dihapus.\n", indeks);
            return;
        }
        current = current->next;
        count++;
    }

    printf("Indeks %d tidak valid.\n", indeks);
}
