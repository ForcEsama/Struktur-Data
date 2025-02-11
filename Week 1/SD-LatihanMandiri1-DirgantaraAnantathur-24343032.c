#include <stdio.h>
int jumlahElemenRekursif(int arr[], int n)
{
    if (n == 0)
    {
        return 0; // Base case
    }
    else
    {
        return arr[0] + jumlahElemenRekursif(arr + 1, n - 1); // Recursive case
    }
}

void judul()
{
    printf("Nama Program : Menghitung Jumlah Elemen Array Menggunakan Rekursi\n");
    printf("Nama         : Dirgantara Anantathur\n");
    printf("Nim          : 24343032\n");
    printf("Prodi        : Teknik Informatika\n");
}

int main()
{
    judul();
    int array[] = {1, 2, 3, 4, 5};
    int panjang = sizeof(array) / sizeof(array[0]);
    printf("", judul);
    printf("\nJumlah elemen array: %d\n", jumlahElemenRekursif(array, panjang));
    return 0;
}