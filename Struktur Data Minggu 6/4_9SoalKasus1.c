/*
Nama File       : 4_9SoalKasus1.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/03/2025
Deskripsi       : Implementasi Stack Linked List dalam Bahasa C.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main();
void judul();
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
void push(Node **top, int elemen);
int pop(Node **top);
int evaluasiPostfix(char ekspresi[]);

int main()
{
    judul();
    char ekspresi[100];

    printf("\nMasukkan ekspresi postfix: ");
    scanf("%s", ekspresi);

    int hasil = evaluasiPostfix(ekspresi);
    printf("Hasil evaluasi: %d\n", hasil);

    return 0;
}

void judul()
{
    printf("Nama Program  : Evaluasi Ekspresi Postfix\n");
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
    return elemen;
}

int evaluasiPostfix(char ekspresi[])
{
    Node *top = NULL;

    for (int i = 0; ekspresi[i] != '\0'; i++)
    {
        if (isdigit(ekspresi[i]))
        {
            push(&top, ekspresi[i] - '0'); // Konversi char ke int
        }
        else
        {
            int operand2 = pop(&top);
            int operand1 = pop(&top);
            int hasil;

            switch (ekspresi[i])
            {
            case '+':
                hasil = operand1 + operand2;
                break;
            case '-':
                hasil = operand1 - operand2;
                break;
            case '*':
                hasil = operand1 * operand2;
                break;
            case '/':
                hasil = operand1 / operand2;
                break;
            default:
                printf("Operator tidak valid.\n");
                return -1;
            }
            push(&top, hasil);
        }
    }
    return pop(&top);
}
