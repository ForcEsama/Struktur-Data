#include <stdio.h>
#include <string.h>

int main();
void tukar(char *a, char *b);
void balikStringRekursif(char str[], int start, int end);
void judul();

int main()
{

    judul();
    char str[100];

    printf("\nMasukkan string: ");
    scanf("%[^\n]s", str);

    int panjang = strlen(str);

    balikStringRekursif(str, 0, panjang - 1);

    printf("String yang dibalik: %s\n", str);

    return 0;
}

void judul()
{
    printf("Nama Program : Membalik String Menggunakan Rekursi  \n");
    printf("Nama         : Dirgantara Anantathur\n");
    printf("Nim          : 24343032\n");
    printf("Prodi        : Teknik Informatika\n");
}

void tukar(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi rekursif untuk membalikkan string
void balikStringRekursif(char str[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    tukar(&str[start], &str[end]);
    balikStringRekursif(str, start + 1, end - 1);
}
