#include <stdio.h>

// Fungsi rekursif untuk menghitung pangkat
int pangkat(int a, int b)
{

    if (b == 0)
    {
        return 1;
    }

    return a * pangkat(a, b - 1);
}

void judul()
{
    printf("Nama Program : Menghitung Nilai Pangkat dengan Rekursi  \n");
    printf("Nama         : Dirgantara Anantathur\n");
    printf("Nim          : 24343032\n");
    printf("Prodi        : Teknik Informatika\n");
}

int main()
{

    judul();

    int a, b;

    printf("\nMasukkan basis (a)    : ");
    scanf("%d", &a);
    printf("Masukkan eksponen (b) : ");
    scanf("%d", &b);

    printf("Hasil dari %d^%d adalah: %d\n", a, b, pangkat(a, b));

    return 0;
}
