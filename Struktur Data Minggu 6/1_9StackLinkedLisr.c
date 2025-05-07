/*
Nama File       : 1_9StackLinkedList.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/03/2025
Deskripsi       : Implementasi Stack Linked List dalam Bahasa C.
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
void push(Node **top, int elemen);
int pop(Node **top);
int peek(Node *top);
int isEmpty(Node *top);
void display(Node *top);

int main()
{
    judul();
    Node *top = NULL;
    int pilihan, elemen;

    do
    {
        printf("\nMenu Stack:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("Masukkan elemen: ");
            scanf("%d", &elemen);
            push(&top, elemen);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            printf("Elemen di puncak: %d\n", peek(top));
            break;
        case 4:
            display(top);
            break;
        case 5:
            printf("Keluar dari program.\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);

    return 0;
}

void judul()
{
    printf("Nama Program  : Implementasi Stack Linked List\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

void push(Node **top, int elemen)
{
    Node *nodeBaru = (Node *)malloc(sizeof(Node));
    nodeBaru->data = elemen;
    nodeBaru->next = *top;
    *top = nodeBaru;
    printf("Elemen %d ditambahkan ke stack.\n", elemen);
}

int pop(Node **top)
{
    if (*top == NULL)
    {
        printf("Stack kosong.\n");
        return -1;
    }
    Node *temp = *top;
    int elemen = temp->data;
    *top = temp->next;
    free(temp);
    printf("Elemen %d dihapus dari stack.\n", elemen);
    return elemen;
}

int peek(Node *top)
{
    if (top == NULL)
    {
        printf("Stack kosong.\n");
        return -1;
    }
    return top->data;
}

int isEmpty(Node *top)
{
    return top == NULL;
}

void display(Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack kosong.\n");
        return;
    }
    Node *current = top;
    printf("Isi stack: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
