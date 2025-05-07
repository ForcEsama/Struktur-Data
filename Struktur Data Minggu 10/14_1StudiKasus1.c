/*
Nama File       : 14_1StudiKasus1.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 07/05/2025
Deskripsi       : Heap dan Operasinya
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main();
void judul();
typedef struct
{
    char name[50];
    int priority;
} Patient;

typedef struct
{
    Patient data[100];
    int size;
} MaxHeap;
void swap(Patient *a, Patient *b);
void upHeapify(MaxHeap *heap, int index);
void downHeapify(MaxHeap *heap, int index);
void insertPatient(MaxHeap *heap, char name[], int priority);
Patient servePatient(MaxHeap *heap);

int main()
{
    judul();
    MaxHeap heap;
    heap.size = 0;

    insertPatient(&heap, "Alice", 2);
    insertPatient(&heap, "Bob", 5);
    insertPatient(&heap, "Charlie", 3);

    Patient p = servePatient(&heap);
    printf("\nServing patient: %s with priority %d\n", p.name, p.priority);

    return 0;
}

void judul()
{
    printf("Nama Program  : Manajemen Antrian Prioritas di Rumah Sakit\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

void swap(Patient *a, Patient *b)
{
    Patient temp = *a;
    *a = *b;
    *b = temp;
}

void upHeapify(MaxHeap *heap, int index)
{
    if (index == 0)
        return;
    int parent = (index - 1) / 2;
    if (heap->data[index].priority > heap->data[parent].priority)
    {
        swap(&heap->data[index], &heap->data[parent]);
        upHeapify(heap, parent);
    }
}

void downHeapify(MaxHeap *heap, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < heap->size && heap->data[left].priority > heap->data[largest].priority)
        largest = left;
    if (right < heap->size && heap->data[right].priority > heap->data[largest].priority)
        largest = right;
    if (largest != index)
    {
        swap(&heap->data[index], &heap->data[largest]);
        downHeapify(heap, largest);
    }
}

void insertPatient(MaxHeap *heap, char name[], int priority)
{
    strcpy(heap->data[heap->size].name, name);
    heap->data[heap->size].priority = priority;
    upHeapify(heap, heap->size);
    heap->size++;
}

Patient servePatient(MaxHeap *heap)
{
    Patient top = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    downHeapify(heap, 0);
    return top;
}
