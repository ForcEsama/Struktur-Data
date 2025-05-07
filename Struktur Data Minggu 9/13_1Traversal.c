/*
Nama File       : 13_1Traversal.c
Programmer      : Dirgantara Anantathur
NIM             : 24343032
Tgl. pembuatan  : 17/03/2025
Deskripsi       : Tree dan Operasinya
*/

#include <stdio.h>
#include <stdlib.h>

int main();
void judul();

typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} Node;
Node *createNode(char data);
void preOrder(Node *node);
void inOrder(Node *node);
void postOrder(Node *node);

int main()
{
    judul();
    Node *root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    root->right->left = createNode('F');
    root->right->right = createNode('G');

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}

void judul()
{
    printf("Nama Program  : Traversal Pada Tree\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void preOrder(Node *node)
{
    if (node != NULL)
    {
        printf("%c ", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(Node *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        printf("%c ", node->data);
        inOrder(node->right);
    }
}

void postOrder(Node *node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        printf("%c ", node->data);
    }
}
