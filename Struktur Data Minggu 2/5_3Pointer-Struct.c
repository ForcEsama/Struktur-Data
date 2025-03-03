/*
Nama File       : 5_3Pointer-Struct.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/02/2025
Deskripsi       : Pointer ke Struct
*/
#include <stdio.h>
#include <stdlib.h>

int main();
void judul();
typedef struct
{
    int id;
    char nama[50];
} Mahasiswa;

int main()
{
    judul();
    Mahasiswa *mhs = (Mahasiswa *)malloc(sizeof(Mahasiswa)); // Alokasi memori

    mhs->id = 1;
    snprintf(mhs->nama, sizeof(mhs->nama), "John Doe");

    printf("ID: %d\n", mhs->id);
    printf("Nama: %s\n", mhs->nama);

    free(mhs); // Membebaskan memori
    return 0;
}

void judul()
{
    printf("Nama Program  : Pointer ke Struct\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}
