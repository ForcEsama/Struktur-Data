/*
Nama File       : 3_3Pointer-String.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/02/2025
Deskripsi       : Pointer dan String
*/
#include <stdio.h>

int main();
void judul();

int main()
{
    judul();
    char str[] = "Halo, Dunia!";
    char *ptr = str; // Pointer menunjuk ke string

    printf("String: %s\n", str);
    printf("Traversal string menggunakan pointer:\n");
    while (*ptr != '\0')
    {
        printf("%c ", *ptr); // Dereferensi pointer
        ptr++;
    }

    return 0;
}

void judul()
{
    printf("Nama Program  : Pointer dan Array\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}
