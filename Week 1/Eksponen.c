#include <stdio.h>

int pangkat(int a, int b)
{
    if (b == 0)
        return 1;                 // Base case
    return a * pangkat(a, b - 1); // Recursive case
}

void judul()
{
    printf("Nama Program : Implementasi Fungsi Rekursi dalam Program Eksponen\n");
    printf("Nama         : Dirgantara Anantathur\n");
    printf("Nim          : 24343032\n");
    printf("Prodi        : Teknik Informatika\n");
}

int main()
{

    judul();

    int basis = 2, eksponen = 3;
    printf("%d^%d = %d\n", basis, eksponen, pangkat(basis, eksponen));
    return 0;
}
