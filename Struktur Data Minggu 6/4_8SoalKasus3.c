/*
Nama File       : 4_8SoalKasus3.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/03/2025
Deskripsi       : Implementasi Stack dalam Sebuah Kasus.
*/

#include <stdio.h>
#include <string.h>
#define MAX 100

int main();
void judul();
void push(char stack[][MAX], int *top, char elemen[]);
char *pop(char stack[][MAX], int *top);
int isEmpty(int top);
void display(char stack[][MAX], int top);

int main()
{
    judul();
    char undo[MAX][MAX], redo[MAX][MAX];
    int topUndo = -1, topRedo = -1;
    int pilihan;
    char teks[MAX];

    do
    {
        printf("\nMenu Editor Teks:\n");
        printf("1. Tambah Teks\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Tampilkan Teks\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("Masukkan teks: ");
            scanf(" %[^\n]", teks);
            push(undo, &topUndo, teks);
            topRedo = -1; // Kosongkan stack redo
            break;
        case 2:
            if (isEmpty(topUndo))
            {
                printf("Tidak ada operasi untuk di-undo.\n");
            }
            else
            {
                push(redo, &topRedo, pop(undo, &topUndo));
            }
            break;
        case 3:
            if (isEmpty(topRedo))
            {
                printf("Tidak ada operasi untuk di-redo.\n");
            }
            else
            {
                push(undo, &topUndo, pop(redo, &topRedo));
            }
            break;
        case 4:
            display(undo, topUndo);
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
    printf("Nama Program  : Implementasi Undo/Redo\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

void push(char stack[][MAX], int *top, char elemen[])
{
    if (*top == MAX - 1)
    {
        printf("Stack penuh.\n");
        return;
    }
    strcpy(stack[++(*top)], elemen);
}

char *pop(char stack[][MAX], int *top)
{
    if (*top == -1)
    {
        return NULL;
    }
    return stack[(*top)--];
}

int isEmpty(int top)
{
    return top == -1;
}

void display(char stack[][MAX], int top)
{
    if (isEmpty(top))
    {
        printf("Tidak ada teks.\n");
        return;
    }
    printf("Teks saat ini: %s\n", stack[top]);
}
