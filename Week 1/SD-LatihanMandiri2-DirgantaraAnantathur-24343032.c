#include <stdio.h>
#include <stdbool.h>
#define true 1
#define false 0
#include <string.h>

bool isPalindromeRekursif(char str[], int start, int end)
{
    if (start >= end)
    {
        return true; // Base case
    }
    if (str[start] != str[end])
    {
        return false; // Karakter pertama dan terakhir berbeda
    }
    return isPalindromeRekursif(str, start + 1, end - 1); // Recursive case
}

void judul()
{
    printf("Nama Program : Menghitung Jumlah Elemen Array Menggunakan Rekursi\n");
    printf("Nama         : Dirgantara Anantathur\n");
    printf("Nim          : 24343032\n");
    printf("Prodi        : Teknik Informatika\n");
}

int main()
{
    judul();
    char str[] = "radar";
    int panjang = strlen(str);
    if (isPalindromeRekursif(str, 0, panjang - 1))
    {
        printf("String '%s' adalah palindrom.\n", str);
    }
    else
    {
        printf("String '%s' bukan palindrom.\n", str);
    }
    return 0;
}