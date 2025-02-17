#include <stdio.h>

void judul()
{
    printf("Nama Program : Menara Hanoi\n");
    printf("Nama         : Dirgantara Anantathur\n");
    printf("Nim          : 24343032\n");
    printf("Prodi        : Teknik Informatika\n");
}

void hanoi(int n, char asal, char tujuan, char bantu)
{
    if (n == 1)
    {
        printf("Pindahkan cakram 1 dari %c ke %c\n", asal, tujuan);
        return;
    }
    hanoi(n - 1, asal, bantu, tujuan);
    printf("Pindahkan cakram %d dari %c ke %c\n", n, asal, tujuan);
    hanoi(n - 1, bantu, tujuan, asal);
}

int main()
{
    int n;
    judul();
    printf("Masukkan jumlah cakram: ");
    scanf("%d", &n);
    printf("Menyelesaikan Tower of Hanoi dengan %d cakram:\n", n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}