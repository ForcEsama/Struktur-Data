/*
Nama File       : 6_3Pointer-KasusNyata.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/02/2025
Deskripsi       : Penerapan Pointer dalam Kasus Nyata
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main();
void judul();
typedef struct
{
    int id;
    char nama[50];
    float nilai;
} Mahasiswa;
void tambahMahasiswa(Mahasiswa **mhs, int *jumlah, int id, const char *nama, float nilai);
void tampilkanMahasiswa(Mahasiswa **mhs, int jumlah);
void updateMahasiswa(Mahasiswa **mhs, int jumlah, int id, const char *nama, float nilai);
void hapusMahasiswa(Mahasiswa **mhs, int *jumlah, int id);

int main()
{
    judul();
    Mahasiswa *mhs[100]; // Array pointer untuk menyimpan mahasiswa
    int jumlah = 0;

    while (1)
    {
        printf("\nMenu Manajemen Data Mahasiswa:\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Tampilkan Mahasiswa\n");
        printf("3. Update Mahasiswa\n");
        printf("4. Hapus Mahasiswa\n");
        printf("5. Keluar\n");
        printf("Pilih operasi: ");
        int pilihan;
        scanf("%d", &pilihan);

        if (pilihan == 5)
            break;

        int id;
        char nama[50];
        float nilai;

        switch (pilihan)
        {
        case 1:
            printf("Masukkan ID: ");
            scanf("%d", &id);
            printf("Masukkan Nama: ");
            scanf(" %[^\n]s", nama);
            printf("Masukkan Nilai: ");
            scanf("%f", &nilai);
            tambahMahasiswa(mhs, &jumlah, id, nama, nilai);
            break;
        case 2:
            tampilkanMahasiswa(mhs, jumlah);
            break;
        case 3:
            printf("Masukkan ID yang ingin diupdate: ");
            scanf("%d", &id);
            printf("Masukkan Nama Baru: ");
            scanf(" %[^\n]s", nama);
            printf("Masukkan Nilai Baru: ");
            scanf("%f", &nilai);
            updateMahasiswa(mhs, jumlah, id, nama, nilai);
            break;
        case 4:
            printf("Masukkan ID yang ingin dihapus: ");
            scanf("%d", &id);
            hapusMahasiswa(mhs, &jumlah, id);
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }
    }

    // Bebaskan memori semua mahasiswa
    for (int i = 0; i < jumlah; i++)
    {
        free(mhs[i]);
    }

    return 0;
}

void judul()
{
    printf("Nama Program  : Manajemen Data Mahasiswa Menggunakan Pointer ke Struct\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

void tambahMahasiswa(Mahasiswa **mhs, int *jumlah, int id, const char *nama, float nilai)
{
    mhs[*jumlah] = (Mahasiswa *)malloc(sizeof(Mahasiswa)); // Alokasi memori untuk mahasiswa baru
    mhs[*jumlah]->id = id;
    snprintf(mhs[*jumlah]->nama, sizeof(mhs[*jumlah]->nama), "%s", nama);
    mhs[*jumlah]->nilai = nilai;
    (*jumlah)++;
    printf("Mahasiswa berhasil ditambahkan!\n");
}

void tampilkanMahasiswa(Mahasiswa **mhs, int jumlah)
{
    printf("Data Mahasiswa:\n");
    for (int i = 0; i < jumlah; i++)
    {
        printf("ID: %d, Nama: %s, Nilai: %.2f\n", mhs[i]->id, mhs[i]->nama, mhs[i]->nilai);
    }
}

void updateMahasiswa(Mahasiswa **mhs, int jumlah, int id, const char *nama, float nilai)
{
    for (int i = 0; i < jumlah; i++)
    {
        if (mhs[i]->id == id)
        {
            snprintf(mhs[i]->nama, sizeof(mhs[i]->nama), "%s", nama);
            mhs[i]->nilai = nilai;
            printf("Data mahasiswa dengan ID %d berhasil diperbarui!\n", id);
            return;
        }
    }
    printf("Mahasiswa dengan ID %d tidak ditemukan!\n", id);
}

void hapusMahasiswa(Mahasiswa **mhs, int *jumlah, int id)
{
    for (int i = 0; i < *jumlah; i++)
    {
        if (mhs[i]->id == id)
        {
            free(mhs[i]); // Bebaskan memori mahasiswa
            for (int j = i; j < *jumlah - 1; j++)
            {
                mhs[j] = mhs[j + 1];
            }
            (*jumlah)--;
            printf("Mahasiswa dengan ID %d berhasil dihapus!\n", id);
            return;
        }
    }
    printf("Mahasiswa dengan ID %d tidak ditemukan!\n", id);
}
