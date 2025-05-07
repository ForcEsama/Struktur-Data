/*
Nama File       : 1_7TraversalCircularDoublyLinkedList.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 24/02/2025
Deskripsi       : Traversal Circular Doubly Linked List
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

int main()
{
    judul();
    Node *head = NULL;
    Node *tail = NULL;

    // Contoh manual untuk Circular Doubly Linked List
    Node *node1 = (Node *)malloc(sizeof(Node));
    Node *node2 = (Node *)malloc(sizeof(Node));
    Node *node3 = (Node *)malloc(sizeof(Node));

    node1->data = 10;
    node2->data = 20;
    node3->data = 30;

    node1->prev = node3;
    node1->next = node2;

    node2->prev = node1;
    node2->next = node3;

    node3->prev = node2;
    node3->next = node1;

    head = node1;
    tail = node3;

    traversalKeDepan(head);
    traversalKeBelakang(tail);

    return 0;
}

void judul()
{
    printf("Nama Program  : Traversal Circular Doubly Linked List\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n\n");
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
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(kembali ke head)\n");
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
    do
    {
        printf("%d -> ", current->data);
        current = current->prev;
    } while (current != tail);
    printf("(kembali ke tail)\n");
}
