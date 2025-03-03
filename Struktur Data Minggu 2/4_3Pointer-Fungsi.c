/*
Nama File       : 4_3Pointer-Fungsi.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/02/2025
Deskripsi       : Pointer ke Fungsi
*/
#include <stdio.h>

int main();
void judul();
void cetakPesan(const char *pesan);

int main()
{
    judul();
    void (*ptrFunc)(const char *) = cetakPesan;                // Pointer ke fungsi
    ptrFunc("Halo, ini dipanggil melalui pointer ke fungsi!"); // Pemanggilan fungsi

    return 0;
}

void judul()
{
    printf("Nama Program  : Pointer ke Fungsi\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

void cetakPesan(const char *pesan)
{
    printf("%s\n", pesan);
}
