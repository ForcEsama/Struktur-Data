/*
Nama File       : 4_8SoalKasus1.c
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
void push(char stack[], int *top, char elemen);
char pop(char stack[], int *top);
int isEmpty(int top);
int validasiKurung(char ekspresi[]);

int main()
{
    judul();
    char ekspresi[MAX];

    printf("\nMasukkan ekspresi matematika: ");
    scanf("%s", ekspresi);

    if (validasiKurung(ekspresi))
    {
        printf("Ekspresi valid.\n");
    }
    else
    {
        printf("Ekspresi tidak valid.\n");
    }

    return 0;
}

void judul()
{
    printf("Nama Program  : Validasi Kurung\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

void push(char stack[], int *top, char elemen)
{
    if (*top == MAX - 1)
    {
        printf("Stack penuh.\n");
        return;
    }
    stack[++(*top)] = elemen;
}

char pop(char stack[], int *top)
{
    if (*top == -1)
    {
        return '\0';
    }
    return stack[(*top)--];
}

int isEmpty(int top)
{
    return top == -1;
}

int validasiKurung(char ekspresi[])
{
    char stack[MAX];
    int top = -1;

    for (int i = 0; i < strlen(ekspresi); i++)
    {
        if (ekspresi[i] == '(')
        {
            push(stack, &top, '(');
        }
        else if (ekspresi[i] == ')')
        {
            if (isEmpty(top))
            {
                return 0; // Tidak valid
            }
            pop(stack, &top);
        }
    }

    return isEmpty(top);
}
