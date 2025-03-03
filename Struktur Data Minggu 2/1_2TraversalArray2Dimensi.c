#include <stdio.h>

/*
   Nama :
*/

// Deklarasi Fungsi untuk traversal array 2 dimensi
int main();
void judul();
void traversalArray(int arr[][3], int baris, int kolom);

int main()
{
    judul();
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    printf("Hasil Traversal Array 2 Dimensi:\n");
    traversalArray(arr, 2, 3); // Memanggil fungsi traversal

    return 0;
}

void judul()
{
    printf("Nama Program : Traversal Array 2 Dimensi\n");
    printf("Nama         : Dirgantara Anantathur\n");
    printf("Nim          : 24343032\n");
    printf("Prodi        : Teknik Informatika\n");
}

// Definisi Fungsi untuk traversal array 2 dimensi
void traversalArray(int arr[][3], int baris, int kolom)
{
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            printf("%d ", arr[i][j]); // Cetak elemen array
        }
        printf("\n"); // Pindah ke baris berikutnya
    }
}
