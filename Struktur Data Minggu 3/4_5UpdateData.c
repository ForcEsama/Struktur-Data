/*
Nama File      	: 4_5UpdatwData.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi      	: Update Data Circular Singly Linked List
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
void updateData(Node *head, int posisi, int nilaiBaru);

int main()
{
    judul();
    Node *head = NULL;

    // Menambahkan data untuk contoh
    tambahDiAwal(&head, 10);
    tambahDiAkhir(&head, 20);
    tambahDiAkhir(&head, 30);
    traversal(head);

    printf("\nMemperbarui data pada posisi 2 menjadi 25:\n");
    updateData(head, 2, 25); // Update posisi ke-2

    printf("\nLinked List Setelah Update:\n");
    traversal(head);

    printf("\nMemperbarui data pada posisi 5:\n");
    updateData(head, 5, 50); // Posisi tidak valid

    return 0;
}

void judul()
{
    printf("Nama Program  : Update Data Circular Singly Linked List\n");
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

void updateData(Node *head, int posisi, int nilaiBaru)
{
    if (head == NULL)
    {
        printf("List kosong. Tidak ada data untuk diperbarui.\n");
        return;
    }

    Node *current = head;
    int count = 1;

    do
    {
        if (count == posisi)
        {
            current->data = nilaiBaru;
            printf("Data pada posisi %d berhasil diperbarui menjadi %d.\n", posisi, nilaiBaru);
            return;
        }
        current = current->next;
        count++;
    } while (current != head);

    printf("Posisi %d tidak valid.\n", posisi);
}