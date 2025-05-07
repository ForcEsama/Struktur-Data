/*
Nama File       : 14_5KelebihanHeap.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 07/05/2025
Deskripsi       : Heap dan Operasinya
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int size;
} MaxHeap;

// Prototipe fungsi
void judul();
void insert(MaxHeap *heap, int value);
int deleteRoot(MaxHeap *heap);
void heapifyDown(MaxHeap *heap, int index);
void swap(int *a, int *b);

int main()
{
    judul();

    MaxHeap heap;
    heap.size = 0;

    // Menambahkan elemen ke heap
    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 15);

    printf("\nHeap setelah insert:\n");
    for (int i = 0; i < heap.size; i++)
    {
        printf("%d ", heap.data[i]);
    }
    printf("\n");

    printf("Elemen terbesar: %d\n", heap.data[0]); // Output: 20

    printf("Delete root: %d\n", deleteRoot(&heap)); // Output: 20

    printf("Heap setelah delete root:\n");
    for (int i = 0; i < heap.size; i++)
    {
        printf("%d ", heap.data[i]);
    }
    printf("\n");

    return 0;
}

void judul()
{
    printf("Nama Program  : Kelebihan Heap dalam C\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("NIM           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

// Fungsi untuk menukar dua nilai
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk memasukkan elemen ke dalam heap
void insert(MaxHeap *heap, int value)
{
    if (heap->size >= MAX_SIZE)
    {
        printf("Heap penuh! Tidak dapat menambahkan elemen.\n");
        return;
    }

    // Tambahkan elemen baru di akhir
    heap->data[heap->size] = value;
    int currentIndex = heap->size;
    heap->size++;

    // Perbaiki heap dengan percolate up
    while (currentIndex > 0)
    {
        int parentIndex = (currentIndex - 1) / 2;
        if (heap->data[currentIndex] > heap->data[parentIndex])
        {
            swap(&heap->data[currentIndex], &heap->data[parentIndex]);
            currentIndex = parentIndex;
        }
        else
        {
            break;
        }
    }
}

// Fungsi untuk menghapus root dari heap
int deleteRoot(MaxHeap *heap)
{
    if (heap->size <= 0)
    {
        printf("Heap kosong! Tidak ada elemen untuk dihapus.\n");
        return -1;
    }

    int rootValue = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    // Perbaiki heap dengan percolate down
    heapifyDown(heap, 0);

    return rootValue;
}

// Fungsi untuk memperbaiki heap dari atas ke bawah
void heapifyDown(MaxHeap *heap, int index)
{
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && heap->data[leftChild] > heap->data[largest])
    {
        largest = leftChild;
    }
    if (rightChild < heap->size && heap->data[rightChild] > heap->data[largest])
    {
        largest = rightChild;
    }

    if (largest != index)
    {
        swap(&heap->data[index], &heap->data[largest]);
        heapifyDown(heap, largest);
    }
}
