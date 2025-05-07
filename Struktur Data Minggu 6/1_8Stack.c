/*
Nama File       : 1_7Stack.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/03/2025
Deskripsi       : Implementasi Stack dalam Bahasa C.
*/

#include <stdio.h>
#define MAX_SIZE 5

int main();
void judul();
void push(int stack[], int *top, int max_size, int elemen);
int pop(int stack[], int *top);
int peek(int stack[], int top);
int isEmpty(int top);
int isFull(int top, int max_size);
void display(int stack[], int top);

int main()
{
    judul();
    int stack[MAX_SIZE];
    int top = -1;

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
            push(stack, &top, MAX_SIZE, elemen);
            break;
        case 2:
            pop(stack, &top);
            break;
        case 3:
            printf("Elemen di puncak: %d\n", peek(stack, top));
            break;
        case 4:
            display(stack, top);
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
    printf("Nama Program  : Implementasi Stack\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

void push(int stack[], int *top, int max_size, int elemen)
{
    if (*top == max_size - 1)
    {
        printf("Stack penuh.\n");
        return;
    }
    (*top)++;
    stack[*top] = elemen;
    printf("Elemen %d ditambahkan ke stack.\n", elemen);
}

int pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack kosong.\n");
        return -1;
    }
    int elemen = stack[*top];
    (*top)--;
    printf("Elemen %d dihapus dari stack.\n", elemen);
    return elemen;
}

int peek(int stack[], int top)
{
    if (top == -1)
    {
        printf("Stack kosong.\n");
        return -1;
    }
    return stack[top];
}

int isEmpty(int top)
{
    return top == -1;
}

int isFull(int top, int max_size)
{
    return top == max_size - 1;
}

void display(int stack[], int top)
{
    if (top == -1)
    {
        printf("Stack kosong.\n");
        return;
    }
    printf("Isi stack: ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
