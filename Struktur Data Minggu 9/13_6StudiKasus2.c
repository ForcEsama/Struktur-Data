/*
Nama File       : 13_5StudiKasus2.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/03/2025
Deskripsi       : Tree dan Operasinya
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define true 1
#define false 0

int main();
void judul();
typedef struct FileSystemNode
{
    char name[100];
    bool isFolder;
    struct FileSystemNode *firstChild;
    struct FileSystemNode *nextSibling;
} FileSystemNode;
FileSystemNode *createNode(const char *name, bool isFolder);
void addNode(FileSystemNode *parent, FileSystemNode *newNode);
FileSystemNode *searchNode(FileSystemNode *root, const char *name);
void deleteTree(FileSystemNode *node);
bool removeNode(FileSystemNode *root, const char *name);
void displayStructure(FileSystemNode *node, int level);

int main()
{
    judul();
    // Membuat root (folder utama)
    FileSystemNode *root = createNode("C:", true);

    // Membuat beberapa folder dan file
    FileSystemNode *documents = createNode("Documents", true);
    FileSystemNode *downloads = createNode("Downloads", true);
    FileSystemNode *notes = createNode("notes.txt", false);
    FileSystemNode *image = createNode("image.jpg", false);

    // Membangun struktur
    addNode(root, documents);
    addNode(root, downloads);
    addNode(documents, notes);
    addNode(downloads, image);

    // Menampilkan struktur
    printf("Struktur File System:\n");
    displayStructure(root, 0);

    // Mencari file
    char searchName[] = "notes.txt";
    FileSystemNode *found = searchNode(root, searchName);
    if (found != NULL)
    {
        printf("\nFile '%s' ditemukan.\n", searchName);
    }
    else
    {
        printf("\nFile '%s' tidak ditemukan.\n", searchName);
    }

    // Menghapus folder
    char deleteName[] = "Downloads";
    if (removeNode(root, deleteName))
    {
        printf("\nFolder '%s' berhasil dihapus.\n", deleteName);
    }
    else
    {
        printf("\nGagal menghapus folder '%s'.\n", deleteName);
    }

    // Menampilkan struktur setelah penghapusan
    printf("\nStruktur setelah penghapusan:\n");
    displayStructure(root, 0);

    // Membersihkan memory
    deleteTree(root);

    return 0;
}

void judul()
{
    printf("Nama Program  : Sistem Penelusuran File dan Folder\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

FileSystemNode *createNode(const char *name, bool isFolder)
{
    FileSystemNode *newNode = (FileSystemNode *)malloc(sizeof(FileSystemNode));
    strcpy(newNode->name, name);
    newNode->isFolder = isFolder;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

void addNode(FileSystemNode *parent, FileSystemNode *newNode)
{
    if (parent == NULL || newNode == NULL || !parent->isFolder)
        return;

    if (parent->firstChild == NULL)
    {
        parent->firstChild = newNode;
    }
    else
    {
        FileSystemNode *current = parent->firstChild;
        while (current->nextSibling != NULL)
        {
            current = current->nextSibling;
        }
        current->nextSibling = newNode;
    }
}

FileSystemNode *searchNode(FileSystemNode *root, const char *name)
{
    if (root == NULL)
        return NULL;

    if (strcmp(root->name, name) == 0)
    {
        return root;
    }

    FileSystemNode *found = searchNode(root->firstChild, name);
    if (found != NULL)
        return found;

    return searchNode(root->nextSibling, name);
}

void deleteTree(FileSystemNode *node)
{
    if (node == NULL)
        return;

    deleteTree(node->firstChild);
    deleteTree(node->nextSibling);
    free(node);
}

bool removeNode(FileSystemNode *root, const char *name)
{
    if (root == NULL)
        return false;

    FileSystemNode *prev = NULL;
    FileSystemNode *current = root->firstChild;

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            if (prev == NULL)
            {
                root->firstChild = current->nextSibling;
            }
            else
            {
                prev->nextSibling = current->nextSibling;
            }
            deleteTree(current);
            return true;
        }

        if (removeNode(current, name))
        {
            return true;
        }

        prev = current;
        current = current->nextSibling;
    }

    return false;
}

void displayStructure(FileSystemNode *node, int level)
{
    if (node == NULL)
        return;

    for (int i = 0; i < level; i++)
        printf("  ");
    printf("[%s] %s\n", node->isFolder ? "Folder" : "File", node->name);

    displayStructure(node->firstChild, level + 1);
    displayStructure(node->nextSibling, level);
}
