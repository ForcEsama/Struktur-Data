#include <stdio.h>

// Fungsi untuk membaca elemen array pada indeks tertentu
void bacaData(int arr[], int pos, int size)
{
    if (pos >= 0 && pos < size)
    { // Memeriksa apakah indeks valid
        printf("Data pada posisi %d adalah: %d\n", pos, arr[pos]);
    }
    else
    {
        printf("Posisi tidak valid!\n"); // Pesan kesalahan jika indeks di luar jangkauan
    }
}

void judul()
{
    printf("Nama Program : Baca Data\n");
    printf("Nama         : Dirgantara Anantathur\n");
    printf("Nim          : 24343032\n");
    printf("Prodi        : Teknik Informatika\n");
}

int main()
{
    judul();
    int arr[] = {10, 20, 30, 40, 50};        // Deklarasi array
    int size = sizeof(arr) / sizeof(arr[0]); // Menghitung ukuran array

    printf("\nMasukkan posisi data yang ingin dibaca (0-%d): ", size - 1);
    int pos;
    scanf("%d", &pos); // Meminta input indeks dari pengguna

    bacaData(arr, pos, size); // Memanggil fungsi untuk membaca data

    return 0;
}
