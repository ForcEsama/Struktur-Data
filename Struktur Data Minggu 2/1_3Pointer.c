/*
Nama File      	: 1_3Pointer.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/02/2025
Deskripsi      	: Pointer
*/

#include <stdio.h>

int main();
void judul();
int *ptr;

int main()
{
    judul();
    int a = 10; // Variabel integer
    int *ptr;   // Deklarasi pointer untuk integer

    ptr = &a; // Menyimpan alamat variabel a ke pointer

    printf("\nNilai a               : %d\n", a);
    printf("Alamat memori a       : %p\n", ptr);  // Alamat memori
    printf("Nilai melalui pointer : %d\n", *ptr); // Dereferensi pointer

    return 0;
}

void judul()
{
    printf("Nama Program  : Pointer\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}