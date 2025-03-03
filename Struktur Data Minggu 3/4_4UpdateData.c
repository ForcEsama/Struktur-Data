/*
Nama File      	: 4_4UpdateData.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi      	: Update Data Singly Linked List
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
void updateData(Node *head, int indeks, int nilaiBaru);

int main()
{
    judul();
    Node *head = NULL;

    // Menambahkan data untuk contoh
    tambahDiAwal(&head, 30);
    tambahDiAwal(&head, 20);
    tambahDiAwal(&head, 10);

    printf("Linked List Sebelum Update:\n");
    traversal(head);

    printf("\nMemperbarui data pada indeks 1:\n");
    updateData(head, 1, 25); // Update node kedua (indeks 1)

    printf("\nLinked List Setelah Update:\n");
    traversal(head);

    printf("\nMemperbarui data pada indeks 5:\n");
    updateData(head, 5, 40); // Indeks tidak valid

    return 0;
}

void judul()
{
    printf("Nama Program  : Update Data Singly Linked List \n");
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

void tambahDiAwal(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void updateData(Node *head, int indeks, int nilaiBaru)
{
    int count = 0;
    Node *current = head;

    while (current != NULL)
    {
        if (count == indeks)
        {
            current->data = nilaiBaru;
            printf("Data pada indeks %d berhasil diperbarui menjadi %d.\n", indeks, nilaiBaru);
            return;
        }
        current = current->next;
        count++;
    }

    printf("Indeks %d tidak valid. Tidak dapat memperbarui data.\n", indeks);
}
