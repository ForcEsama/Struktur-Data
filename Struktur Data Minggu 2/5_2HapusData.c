/*
Nama File      	: 5HapusData.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/02/2025
Deskripsi      	: Hapus Data Array 2 Dimensi
*/
#include <stdio.h>

// Deklarasi fungsi untuk menghapus elemen dari array 2 dimensi
int main();
void judul();
void hapusData(int arr[][3], int baris, int kolom, int barisMax, int kolomMax);

int main()
{
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    printf("Array sebelum penghapusan:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nMasukkan posisi baris dan kolom untuk penghapusan (contoh: 1 2): ");
    int baris, kolom;
    scanf("%d %d", &baris, &kolom);

    hapusData(arr, baris, kolom, 2, 3);

    printf("\nArray setelah penghapusan:\n");
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
    printf("Nama Program  : Hapus Data Array 2 Dimensi\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}
// Definisi fungsi untuk menghapus elemen dari array 2 dimensi
void hapusData(int arr[][3], int baris, int kolom, int barisMax, int kolomMax)
{
    if (baris >= 0 && baris < barisMax && kolom >= 0 && kolom < kolomMax)
    {
        arr[baris][kolom] = 0; // Mengganti elemen dengan nilai default (0)
        printf("Data pada posisi [%d][%d] telah dihapus.\n", baris, kolom);
    }
    else
    {
        printf("Posisi tidak valid! Tidak dapat menghapus data.\n");
    }
}
