#include <stdio.h>

int jumlah(int n)
{

    if (n == 0)
    {
        return 0;
    }

    return (n % 10) + jumlah(n / 10);
}

void judul()
{
    printf("Nama Program : Menghitung Jumlah Angka dalam Bilangan  \n");
    printf("Nama         : Dirgantara Anantathur\n");
    printf("Nim          : 24343032\n");
    printf("Prodi        : Teknik Informatika\n");
}

int main()
{

    judul();

    int n;

    printf("\nMasukkan sebuah bilangan : ");
    scanf("%d", &n);

    printf("Jumlah digit dalam bilangan: %d\n", jumlah(n));
    return 0;
}