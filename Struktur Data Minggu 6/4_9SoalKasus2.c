/*
Nama File       : 4_9SoalKasus2.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/03/2025
Deskripsi       : Implementasi Stack Linked List dalam Bahasa C.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main();
void judul();
typedef struct Node
{
    int x, y;
    struct Node *next;
} Node;
void push(Node **top, int x, int y);
void pop(Node **top);
int isEmpty(Node *top);
void displayPath(Node *top);
int isSafe(int maze[][MAX], int visited[][MAX], int x, int y, int n, int m);
int backtrackingLabirin(int maze[][MAX], int n, int m, int startX, int startY, int endX, int endY);

int main()
{
    judul();
    int maze[MAX][MAX];
    int n, m, startX, startY, endX, endY;

    printf("Masukkan ukuran labirin (n m): ");
    scanf("%d %d", &n, &m);

    printf("Masukkan labirin (1 untuk jalan, 0 untuk penghalang):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }

    printf("Masukkan posisi awal (x y): ");
    scanf("%d %d", &startX, &startY);

    printf("Masukkan posisi tujuan (x y): ");
    scanf("%d %d", &endX, &endY);

    if (!backtrackingLabirin(maze, n, m, startX, startY, endX, endY))
    {
        printf("Tidak ada jalur yang dapat ditemukan.\n");
    }

    return 0;
}

void judul()
{
    printf("Nama Program  : Simulasi Backtracking\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

void push(Node **top, int x, int y)
{
    Node *nodeBaru = (Node *)malloc(sizeof(Node));
    nodeBaru->x = x;
    nodeBaru->y = y;
    nodeBaru->next = *top;
    *top = nodeBaru;
}

void pop(Node **top)
{
    if (*top == NULL)
        return;

    Node *temp = *top;
    *top = temp->next;
    free(temp);
}

int isEmpty(Node *top)
{
    return top == NULL;
}

void displayPath(Node *top)
{
    if (isEmpty(top))
    {
        printf("Tidak ada jalur.\n");
        return;
    }

    printf("Jalur: ");
    Node *current = top;
    while (current != NULL)
    {
        printf("(%d, %d) ", current->x, current->y);
        current = current->next;
    }
    printf("\n");
}

int isSafe(int maze[][MAX], int visited[][MAX], int x, int y, int n, int m)
{
    return (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 1 && visited[x][y] == 0);
}

int backtrackingLabirin(int maze[][MAX], int n, int m, int startX, int startY, int endX, int endY)
{
    int visited[MAX][MAX] = {0};
    Node *stack = NULL;

    // Tambahkan posisi awal ke stack
    push(&stack, startX, startY);
    visited[startX][startY] = 1;

    int row[] = {-1, 1, 0, 0}; // Gerakan atas, bawah, kiri, kanan
    int col[] = {0, 0, -1, 1};

    while (!isEmpty(stack))
    {
        int x = stack->x;
        int y = stack->y;

        // Jika tujuan ditemukan
        if (x == endX && y == endY)
        {
            displayPath(stack);
            return 1;
        }

        int foundPath = 0;

        // Periksa semua arah
        for (int i = 0; i < 4; i++)
        {
            int newX = x + row[i];
            int newY = y + col[i];

            if (isSafe(maze, visited, newX, newY, n, m))
            {
                push(&stack, newX, newY);
                visited[newX][newY] = 1;
                foundPath = 1;
                break;
            }
        }

        // Jika tidak ada jalan, kembali
        if (!foundPath)
        {
            pop(&stack);
        }
    }

    printf("Jalur tidak ditemukan.\n");
    return 0;
}
