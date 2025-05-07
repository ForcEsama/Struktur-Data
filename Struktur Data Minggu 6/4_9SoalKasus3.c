/*
Nama File       : 4_9SoalKasus3.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/03/2025
Deskripsi       : Implementasi Stack Linked List dalam Bahasa C.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main();
void judul();
typedef struct Node
{
    char data[100];
    struct Node *next;
} Node;
void push(Node **top, char data[]);
char *pop(Node **top);
int isEmpty(Node *top);
void display(Node *top);

int main()
{
    judul();
    Node *undo = NULL;
    Node *redo = NULL;

    int pilihan;
    char data[100];

    do
    {
        printf("\nMenu:\n");
        printf("1. Tambah Data\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Tampilkan Data\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("Masukkan data: ");
            scanf(" %[^\n]", data);
            push(&undo, data);
            redo = NULL; // Kosongkan stack redo
            break;
        case 2:
            if (isEmpty(undo))
            {
                printf("Tidak ada data untuk di-undo.\n");
            }
            else
            {
                push(&redo, pop(&undo));
            }
            break;
        case 3:
            if (isEmpty(redo))
            {
                printf("Tidak ada data untuk di-redo.\n");
            }
            else
            {
                push(&undo, pop(&redo));
            }
            break;
        case 4:
            display(undo);
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
    printf("Nama Program  : Penimpanan Data Temporer\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

void push(Node **top, char data[])
{
    Node *nodeBaru = (Node *)malloc(sizeof(Node));
    strcpy(nodeBaru->data, data);
    nodeBaru->next = *top;
    *top = nodeBaru;
}

char *pop(Node **top)
{
    if (*top == NULL)
    {
        return NULL;
    }
    Node *temp = *top;
    char *data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
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
    printf("Data dalam stack: ");
    while (current != NULL)
    {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}
