#include <stdio.h>

// Fungsi untuk menambahkan elemen ke array
void tambahData(int arr[], int *size, int capacity, int data, int pos)
{
    if (*size >= capacity)
    { // Memeriksa apakah array penuh
        printf("Array penuh! Tidak dapat menambahkan data.\n");
        return;
    }
    for (int i = *size; i > pos; i--)
    { // Geser elemen ke kanan
        arr[i] = arr[i - 1];
    }
    arr[pos] = data; // Tambahkan elemen baru
    (*size)++;       // Perbarui ukuran array
}

void judul()
{
    printf("Nama Program : Tambah Data\n");
    printf("Nama         : Dirgantara Anantathur\n");
    printf("Nim          : 24343032\n");
    printf("Prodi        : Teknik Informatika\n");
}

int main()
{
    judul();
    int arr[10] = {10, 20, 30, 40, 50}; // Deklarasi array
    int size = 5;                       // Ukuran awal array
    int capacity = 10;                  // Kapasitas maksimum array

    printf("\nSebelum penambahan:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\nMenambahkan elemen 25 di posisi 2...\n");
    tambahData(arr, &size, capacity, 25, 2); // Menambahkan elemen baru

    printf("Setelah penambahan:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
