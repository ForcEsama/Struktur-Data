/*
Nama File      	: 5_5HapusData.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi      	: Hapus Data Circular Singly Linked List
*/

#include <stdio.h>
#include <stdlib.h>

int main();
void judul();
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
void traversal(Node *head);
void tambahDiAwal(Node **head, int data);
void tambahDiAkhir(Node **head, int data);
void hapusData(Node **head, int posisi);

int main()
{
    judul();
    Node *head = NULL;

    // Menambahkan data untuk contoh
    tambahDiAwal(&head, 10);
    tambahDiAkhir(&head, 20);
    tambahDiAkhir(&head, 30);
    traversal(head);

    printf("\nMenghapus node pada posisi 2:\n");
    hapusData(&head, 2); // Hapus posisi ke-2

    printf("\nLinked List Setelah Penghapusan:\n");
    traversal(head);

    return 0;
}

void judul()
{
    printf("Nama Program  : Hapus Data Circular Singly Linked List\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

// Traversal circular singly linked list
void traversal(Node *head)
{
    if (head == NULL)
    {
        printf("List kosong.\n");
        return;
    }

    Node *current = head;
    printf("Isi Circular Singly Linked List:\n");
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(kembali ke head)\n");
}

void tambahDiAwal(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (*head == NULL)
    {
        newNode->next = newNode; // Node menunjuk dirinya sendiri
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != *head)
        {
            current = current->next;
        }
        newNode->next = *head;
        current->next = newNode;
        *head = newNode;
    }
}

void tambahDiAkhir(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (*head == NULL)
    {
        newNode->next = newNode; // Node menunjuk dirinya sendiri
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
}

void hapusData(Node **head, int posisi)
{
    if (*head == NULL)
    {
        printf("List kosong. Tidak ada data untuk dihapus.\n");
        return;
    }

    Node *current = *head;
    Node *prev = NULL;
    int count = 1;

    if (posisi == 1)
    {
        while (current->next != *head)
        {
            current = current->next;
        }
        Node *temp = *head;
        current->next = (*head)->next;
        *head = (*head)->next;
        free(temp);
        printf("Node pada posisi 1 berhasil dihapus.\n");
        return;
    }

    current = *head;
    do
    {
        if (count == posisi)
        {
            prev->next = current->next;
            free(current);
            printf("Node pada posisi %d berhasil dihapus.\n", posisi);
            return;
        }
        prev = current;
        current = current->next;
        count++;
    } while (current != *head);

    printf("Posisi %d tidak valid.\n", posisi);
}