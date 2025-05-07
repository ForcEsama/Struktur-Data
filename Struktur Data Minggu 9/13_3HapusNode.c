/*
Nama File       : 13_3HapusNode.c
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
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node *createNode(int data);
Node *insert(Node *node, int data);
Node *findMin(Node *node);
Node *deleteNode(Node *root, int key);
void inOrder(Node *node);

int main()
{
    judul();
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("In-order Traversal Tree: ");
    inOrder(root);
    printf("\n");

    printf("Deleting node 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal after deletion: ");
    inOrder(root);
    printf("\n");

    printf("Deleting node 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal after deletion: ");
    inOrder(root);
    printf("\n");

    printf("Deleting node 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal after deletion: ");
    inOrder(root);
    printf("\n");

    return 0;
}

void judul()
{
    printf("Nama Program  : Hapus Node Pada Tree\n");
    printf("Nama          : Dirgantara Anantathur\n");
    printf("Nim           : 24343032\n");
    printf("Prodi         : Teknik Informatika\n");
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *node, int data)
{
    if (node == NULL)
    {
        return createNode(data);
    }
    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }
    return node;
}

Node *findMin(Node *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inOrder(Node *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
}
