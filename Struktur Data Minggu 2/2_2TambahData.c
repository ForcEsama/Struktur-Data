/*
Nama File      	 : 2TambahData.c
Programmer       : Dirgantara Anantathur
NIM             	 : 24343032
Tgl. pembuatan  : 17/02/2025
Deskripsi      	 : Tambah Data Array 2 Dimensi
*/

#include <stdio.h>

// deklarasi fungsi untuk menambahkan elemen ke array 2 dimensi
int main();
void judul();
void tambahData(int arr[][3], int baris, int kolom, int barisMax, int kolomMax, int data);

int main()
{
    judul();
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    printf("Array sebelum penambahan:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int baris = 1, kolom = 2, data = 10;

    printf("\nMenambahkan data baru...\n");
    tambahData(arr, baris, kolom, 2, 3, data);

    printf("\nArray setelah penambahan:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void judul()
{
    printf("Nama Program            : Tambah Data Array 2 Dimensi\n");
    printf("Nama                    : Dirgantara Anantathur\n");
    printf("Nim                     : 24343032\n");
    printf("Prodi                   : Teknik Informatika\n");
}
// Definisi Fungsi untuk menambahkan elemen ke array 2 dimensi
void tambahData(int arr[][3], int baris, int kolom, int barisMax, int kolomMax, int data)
{
    if (baris >= 0 && baris < barisMax && kolom >= 0 && kolom < kolomMax)
    {
        arr[baris][kolom] = data; // Tambahkan elemen baru
        printf("Data berhasil ditambahkan di posisi [%d][%d].\n", baris, kolom);
    }
    else
    {
        printf("Posisi tidak valid! Tidak dapat menambahkan data.\n");
    }
}
