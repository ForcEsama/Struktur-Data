/*
Nama File       : 13_4SoalKasusNyata.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/03/2025
Deskripsi       : Tree dan Operasinya
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main();
void judul();
typedef struct Produk
{
    int id;
    char nama[50];
    int harga;
    struct Produk *left;
    struct Produk *right;
} Produk;
Produk *createProduk(int id, const char *nama, int harga);
Produk *insertProduk(Produk *root, int id, const char *nama, int harga);
void inOrderProduk(Produk *root);

int main()
{
    judul();
    Produk *katalog = NULL;
    katalog = insertProduk(katalog, 101, "Mouse", 150000);
    katalog = insertProduk(katalog, 102, "Keyboard", 300000);
    katalog = insertProduk(katalog, 103, "Monitor", 1500000);
    katalog = insertProduk(katalog, 104, "Headset", 450000);

    printf("Daftar Produk Berdasarkan Harga:\n");
    inOrderProduk(katalog);

    return 0;
}

void judul()
{
    printf("Nama Program  : Implementasi Tree dalam Studi Kasus Nyata\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

Produk *createProduk(int id, const char *nama, int harga)
{
    Produk *newProduk = (Produk *)malloc(sizeof(Produk));
    newProduk->id = id;
    strcpy(newProduk->nama, nama);
    newProduk->harga = harga;
    newProduk->left = newProduk->right = NULL;
    return newProduk;
}

Produk *insertProduk(Produk *root, int id, const char *nama, int harga)
{
    if (root == NULL)
        return createProduk(id, nama, harga);

    if (harga < root->harga)
        root->left = insertProduk(root->left, id, nama, harga);
    else
        root->right = insertProduk(root->right, id, nama, harga);
    return root;
}

void inOrderProduk(Produk *root)
{
    if (root != NULL)
    {
        inOrderProduk(root->left);
        printf("ID: %d, Nama: %s, Harga: %d\n", root->id, root->nama, root->harga);
        inOrderProduk(root->right);
    }
}
