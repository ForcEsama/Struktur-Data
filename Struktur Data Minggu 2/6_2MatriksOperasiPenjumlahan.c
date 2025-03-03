/*
Nama File      	: MatriksOperasiPenjumlahan.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/02/2025
Deskripsi      	: Penerapan Array 2 Dimensi dalam Studi Kasus Matriks Operasi Penjumlahan

*/

#include <stdio.h>

// Deklarasi fungsi-fungsi
int main();
void judul();
void tampilkanMatriks(int matriks[][3], int baris, int kolom);
void jumlahkanMatriks(int matriks1[][3], int matriks2[][3], int hasil[][3], int baris, int kolom);

int main()
{
    judul();
    int matriks1[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};
    int matriks2[2][3] = {
        {6, 5, 4},
        {3, 2, 1}};
    int hasil[2][3];

    printf("Matriks Pertama:\n");
    tampilkanMatriks(matriks1, 2, 3);

    printf("\nMatriks Kedua:\n");
    tampilkanMatriks(matriks2, 2, 3);

    jumlahkanMatriks(matriks1, matriks2, hasil, 2, 3);

    printf("\nHasil Penjumlahan Matriks:\n");
    tampilkanMatriks(hasil, 2, 3);

    return 0;
}

void judul()
{
    printf("Nama Program  : Matriks Operasi Penjumlahan\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

// Implementasi fungsi tampilkanMatriks
void tampilkanMatriks(int matriks[][3], int baris, int kolom)
{
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            printf("%d ", matriks[i][j]);
        }
        printf("\n");
    }
}

// Implementasi fungsi jumlahkanMatriks
void jumlahkanMatriks(int matriks1[][3], int matriks2[][3], int hasil[][3], int baris, int kolom)
{
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
        }
    }
}
