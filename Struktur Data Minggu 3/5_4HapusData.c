/*
Nama File      	: 5_4HapusData.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi      	: Hapus Data Singly Linked List
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
void hapusData(Node **head, int indeks);

int main()
{
    judul();
    Node *head = NULL;

    // Menambahkan data untuk contoh
    tambahDiAwal(&head, 30);
    tambahDiAwal(&head, 20);
    tambahDiAwal(&head, 10);

    printf("Linked List Sebelum Penghapusan:\n");
    traversal(head);

    printf("\nMenghapus node pada indeks 1:\n");
    hapusData(&head, 1); // Hapus node kedua (indeks 1)

    printf("\nLinked List Setelah Penghapusan:\n");
    traversal(head);

    return 0;
}

void judul()
{
    printf("Nama Program  : Hapus Data Singly Linked List \n");
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

void hapusData(Node **head, int indeks)
{
    if (*head == NULL)
    {
        printf("List kosong. Tidak ada yang dapat dihapus.\n");
        return;
    }

    Node *current = *head;
    if (indeks == 0)
    {
        *head = current->next;
        free(current);
        printf("Node pada indeks 0 berhasil dihapus.\n");
        return;
    }

    Node *prev = NULL;
    int count = 0;

    while (current != NULL && count != indeks)
    {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL)
    {
        printf("Indeks %d tidak valid. Tidak dapat menghapus data.\n", indeks);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Node pada indeks %d berhasil dihapus.\n", indeks);
}
