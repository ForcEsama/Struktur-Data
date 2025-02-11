#include <stdio.h>

// Fungsi untuk traversal array
void traversalArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    { // Iterasi melalui setiap elemen array
        printf("Elemen ke-%d: %d\n", i, arr[i]);
    }
}

void judul()
{
    printf("Nama Program : Traversal Array 1 Dimensi\n");
    printf("Nama         : Dirgantara Anantathur\n");
    printf("Nim          : 24343032\n");
    printf("Prodi        : Teknik Informatika\n");
}

int main()
{
    judul();
    int arr[] = {10, 20, 30, 40, 50};        // Deklarasi array
    int size = sizeof(arr) / sizeof(arr[0]); // Menghitung jumlah elemen dalam array

    printf("Hasil Traversal Array:\n");
    traversalArray(arr, size); // Memanggil fungsi traversal untuk mencetak elemen array

    return 0;
}
