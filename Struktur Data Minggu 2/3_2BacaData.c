/*
Nama File      	: 3BacaData.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/02/2025
Deskripsi      	: Baca Data Array 2 Dimensi
*/

#include <stdio.h>

// Deklarasi fungsi untuk membaca elemen dari array 2 dimensi
int main();
void judul();
void bacaData(int arr[][3], int baris, int kolom, int barisMax, int kolomMax);

int main()
{
    judul();
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    printf("Masukkan posisi baris dan kolom untuk membaca data (contoh: 1 2): ");
    int baris, kolom;
    scanf("%d %d", &baris, &kolom);

    bacaData(arr, baris, kolom, 2, 3);

    return 0;
}

void judul()
{
    printf("Nama Program   : Baca Data Array 2 Dimensi\n");
    printf("Nama           : Dirgantara Anantathur\n");
    printf("Nim            : 24343032\n");
    printf("Prodi          : Teknik Informatika\n");
}

// Definisi fungsi untuk membaca elemen dari array 2 dimensi
void bacaData(int arr[][3], int baris, int kolom, int barisMax, int kolomMax)
{
    if (baris >= 0 && baris < barisMax && kolom >= 0 && kolom < kolomMax)
    {
        printf("Data pada posisi [%d][%d] adalah: %d\n", baris, kolom, arr[baris][kolom]);
    }
    else
    {
        printf("Posisi tidak valid! Tidak dapat membaca data.\n");
    }
}
