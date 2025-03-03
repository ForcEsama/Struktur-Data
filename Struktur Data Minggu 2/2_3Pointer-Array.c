/*
Nama File       : 2_3Pointer&Array.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/02/2025
Deskripsi       : Pointer dan Array
*/
#include <stdio.h>

int main();
void judul();

int main()
{
    judul();
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Pointer menunjuk ke elemen pertama array

    printf("Mengakses elemen array melalui pointer:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Elemen ke-%d: %d\n", i, *(ptr + i)); // Aritmatika pointer
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
