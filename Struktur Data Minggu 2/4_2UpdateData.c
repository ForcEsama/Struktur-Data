/*
Nama File      	 : 4UpdateData.c
Programmer       : Dirgantara Anantathur
NIM              : 24343032
Tgl. pembuatan   : 17/02/2025
Deskripsi      	 : Update Data Array 2 Dimensi
*/

#include <stdio.h>

// FDeklarasi fungsi untuk memperbarui elemen array 2 dimensi
int main();
void judul();
void updateData(int arr[][3], int baris, int kolom, int barisMax, int kolomMax, int nilaiBaru);

int main()
{
    judul();
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    printf("Array sebelum pembaruan:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nMasukkan posisi baris dan kolom untuk pembaruan (contoh: 1 2): ");
    int baris, kolom;
    scanf("%d %d", &baris, &kolom);

    printf("Masukkan nilai baru: ");
    int nilaiBaru;
    scanf("%d", &nilaiBaru);

    updateData(arr, baris, kolom, 2, 3, nilaiBaru);

    printf("\nArray setelah pembaruan:\n");
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
    printf("Nama Program  : Update Data Array 2 Dimensi\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

// Definisi fungsi untuk memperbarui elemen array 2 dimensi
void updateData(int arr[][3], int baris, int kolom, int barisMax, int kolomMax, int nilaiBaru)
{
    if (baris >= 0 && baris < barisMax && kolom >= 0 && kolom < kolomMax)
    {
        arr[baris][kolom] = nilaiBaru; // Perbarui elemen
        printf("Data pada posisi [%d][%d] telah diperbarui menjadi %d.\n", baris, kolom, nilaiBaru);
    }
    else
    {
        printf("Posisi tidak valid! Tidak dapat memperbarui data.\n");
    }
}
