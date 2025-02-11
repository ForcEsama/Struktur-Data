#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void judul()
{
    printf("Nama Program : Implementasi Fungsi Rekursi dalam Program Deret Fibonacci\n");
    printf("Nama         : Dirgantara Anantathur\n");
    printf("Nim          : 24343032\n");
    printf("Prodi        : Teknik Informatika\n");
}

int main()
{

    judul();

    int angka = 10;
    for (int i = 0; i < angka; i++)
    {
        printf("%d ", fibonacci(i));
    }
    return 0;
}
