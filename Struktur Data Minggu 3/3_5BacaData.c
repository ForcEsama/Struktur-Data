/*
Nama File      	: 3_5BacaData.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi      	: Tambah Data Circular Singly Linked List
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
void bacaData(Node *head, int posisi);

int main()
{
    judul();
    Node *head = NULL;

    // Menambahkan data untuk contoh
    tambahDiAwal(&head, 10);
    tambahDiAkhir(&head, 20);
    tambahDiAkhir(&head, 30);
    traversal(head);

    printf("\nMembaca data pada posisi 2:\n");
    bacaData(head, 2); // Membaca data pada posisi ke-2

    printf("\nMembaca data pada posisi 5:\n");
    bacaData(head, 5); // Posisi tidak valid

    return 0;
}

void judul()
{
    printf("Nama Program  : Baca Data Circular Singly Linked List\n");
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

void bacaData(Node *head, int posisi)
{
    if (head == NULL)
    {
        printf("List kosong.\n");
        return;
    }

    Node *current = head;
    int count = 1;

    do
    {
        if (count == posisi)
        {
            printf("Data pada posisi %d adalah: %d\n", posisi, current->data);
            return;
        }
        current = current->next;
        count++;
    } while (current != head);

    printf("Posisi %d tidak valid.\n", posisi);
}