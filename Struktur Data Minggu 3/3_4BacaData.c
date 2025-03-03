/*
Nama File      	: 3_4TambahData.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi      	: Baca Data Singly Linked List
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
void bacaData(Node *head, int indeks);
void tambahDiAwal(Node **head, int data);

int main()
{
    judul();
    Node *head = NULL;

    // Menambahkan data untuk contoh
    tambahDiAwal(&head, 30);
    tambahDiAwal(&head, 20);
    tambahDiAwal(&head, 10);

    printf("Linked List:\n");
    traversal(head);

    printf("\nMembaca data pada indeks 1...\n");
    bacaData(head, 1); // Membaca node kedua (indeks 1)

    printf("\nMembaca data pada indeks 5...\n");
    bacaData(head, 5); // Indeks tidak valid

    return 0;
}

void judul()
{
    printf("Nama Program  : Baca Data Singly Linked List \n");
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
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void bacaData(Node *head, int indeks)
{
    int count = 0;
    Node *current = head;

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

    printf("Indeks %d tidak valid. List terlalu pendek.\n", indeks);
}

void tambahDiAwal(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
