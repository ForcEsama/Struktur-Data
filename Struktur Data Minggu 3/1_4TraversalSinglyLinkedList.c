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

int main()
{
    judul();
    Node *head = NULL; // List kosong

    // Traversal pada list kosong
    traversal(head);

    // Menambahkan node secara manual untuk contoh
    head = (Node *)malloc(sizeof(Node));
    head->data = 10;
    head->next = (Node *)malloc(sizeof(Node));
    head->next->data = 20;
    head->next->next = NULL;

    // Traversal setelah menambahkan node
    traversal(head);

    return 0;
}

void judul()
{
    printf("Nama Program  : Traversal Singly Linked List\n");
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
