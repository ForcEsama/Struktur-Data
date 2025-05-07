/*
Nama File       : 4_8SoalKasus2.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/03/2025
Deskripsi       : Implementasi Stack dalam Sebuah Kasus.
*/

#include <stdio.h>
#include <ctype.h>

#define MAX 100

int main();
void judul();
int prioritas(char op);
void push(char stack[], int *top, char elemen);
char pop(char stack[], int *top);
int isEmpty(int top);
void konversiInfixToPostfix(char infix[], char postfix[]);

int main()
{
    judul();
    char infix[MAX], postfix[MAX];

    printf("\nMasukkan ekspresi infix: ");
    scanf("%s", infix);

    konversiInfixToPostfix(infix, postfix);

    printf("Ekspresi postfix: %s\n", postfix);

    return 0;
}

void judul()
{
    printf("Nama Program  : Konversi Infix ke Postfix\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

int prioritas(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void push(char stack[], int *top, char elemen)
{
    stack[++(*top)] = elemen;
}

char pop(char stack[], int *top)
{
    return stack[(*top)--];
}

int isEmpty(int top)
{
    return top == -1;
}

void konversiInfixToPostfix(char infix[], char postfix[])
{
    char stack[MAX];
    int top = -1, j = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else
        {
            while (!isEmpty(top) && prioritas(stack[top]) >= prioritas(infix[i]))
            {
                postfix[j++] = pop(stack, &top);
            }
            push(stack, &top, infix[i]);
        }
    }

    while (!isEmpty(top))
    {
        postfix[j++] = pop(stack, &top);
    }
    postfix[j] = '\0';
}
