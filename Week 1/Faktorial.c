#include <stdio.h>

int faktorial(int n)
{
    if (n == 0)
    {
        return 1; // Base case
    }
    else
    {
        return n * faktorial(n - 1); // Recursive case
    }
}

void judul()
{
    printf("Nama Program : Implementasi Fungsi Rekursi dalam Program Faktorial\n");
    printf("Nama         : Dirgantara Anantathur\n");
    printf("Nim          : 24343032\n");
    printf("Prodi        : Teknik Informatika\n");
}

int main()
{

    judul();

    int angka = 5;
    printf("Faktorial dari %d adalah %d\n", angka, faktorial(angka));
    return 0;
}
