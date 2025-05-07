/*
Nama File      	: 1_4TraversalSinglyLinkedList.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi      	: Traversal Singly Linked List
*/

#include <stdio.h>
#include <stdlib.h>

int main();
void judul();
void traversal();
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
void tambahDiAwal(Node **head, int data);
void tambahDiAkhir(Node **head, int data);
void tambahDiTengah(Node *head, int posisi, int data);

int main()
{
    judul();
    Node *head = NULL;

    // Menambah data di awal
    tambahDiAwal(&head, 30);
    tambahDiAwal(&head, 20);
    tambahDiAwal(&head, 10);
    printf("Setelah menambah di awal:\n");
    traversal(head);

    // Menambah data di akhir
    tambahDiAkhir(&head, 40);
    tambahDiAkhir(&head, 50);
    printf("\nSetelah menambah di akhir:\n");
    traversal(head);

    // Menambah data di tengah
    tambahDiTengah(head, 3, 25);
    printf("\nSetelah menambah di tengah:\n");
    traversal(head);

    return 0;
}

void judul()
{
    printf("Nama Program  : Tambah Data Linked List\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

void traversal(Node *head)
{
    if (head == NULL)
    {
        printf("List kosong.\n");
        return;
    }

    Node *current = head;
    printf("Isi Linked List:\n");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void tambahDiAwal(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void tambahDiAkhir(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

void tambahDiTengah(Node *head, int posisi, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    Node *current = head;
    for (int i = 1; i < posisi - 1; i++)
    {
        if (current == NULL)
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
