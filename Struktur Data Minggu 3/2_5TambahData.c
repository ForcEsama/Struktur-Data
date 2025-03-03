/*
Nama File      	: 2_5TambahData.c
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
void tambahDiPosisi(Node **head, int posisi, int data);

int main()
{
    judul();
    Node *head = NULL;

    // Menambah data di awal
    tambahDiAwal(&head, 10);
    tambahDiAwal(&head, 20);
    traversal(head);

    // Menambah data di akhir
    tambahDiAkhir(&head, 30);
    tambahDiAkhir(&head, 40);
    traversal(head);

    // Menambah data di posisi tertentu
    tambahDiPosisi(&head, 3, 25);
    traversal(head);

    return 0;
}

void judul()
{
    printf("Nama Program  : Tambah Data Circular Singly Linked List\n");
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

void tambahDiPosisi(Node **head, int posisi, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (*head == NULL)
    {
        printf("List kosong. Gunakan fungsi tambahDiAwal.\n");
        free(newNode);
        return;
    }

    Node *current = *head;
    for (int i = 1; i < posisi - 1; i++)
    {
        if (current->next == *head)
        {
            printf("Posisi tidak valid.\n");
            free(newNode);
            return;
        }
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}
