#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUMBER_OF_NODES 50

typedef struct node
{
    int id;
    struct node * left;
    struct node * right;
} Node;

FILE * openFile(const char * fileName)
{
    FILE * file = fopen(fileName, "r");

    return file;
}

FILE * validateFile(const char * fileName)
{
    FILE * file = openFile(fileName);

    if (!file)
    {
        printf("File not found.");
        exit(5);
    }

    return file;
}

Node * createBinaryTreeFromFile(FILE * file)
{
    Node * node;
    int id;

    fscanf(file, "%d", &id);

    if (id == 0)
        return NULL;
    else
    {
        node = (Node *)malloc(sizeof(Node));

        if (node == NULL)
        {
            printf("We don't have memory in createBinaryTree!");
            exit(5);
        }

        node->id = id;
        node->left = createBinaryTreeFromFile(file);
        node->right = createBinaryTreeFromFile(file);
    }

    return node;
}

void inOrderCrossing(Node * node, int * vectorOfNodes, int * numberOfNodes)
{
    if (node != NULL)
    {
        inOrderCrossing(node->left, vectorOfNodes, numberOfNodes);

        vectorOfNodes[*numberOfNodes] = node->id;
        *numberOfNodes += 1;

        inOrderCrossing(node->right, vectorOfNodes, numberOfNodes);
    }
}

bool isBinarySearchTree(int * vectorOfNodes, int numberOfNodes)
{
    for (int i = 0; i < numberOfNodes - 1; i++)
        if (vectorOfNodes[i] > vectorOfNodes[i + 1])
            return false;

    return true;
}

void checkTheTree(int * vectorOfNodes, int numberOfNodes)
{
    bool binarySearchTree = isBinarySearchTree(vectorOfNodes, numberOfNodes);

    if (binarySearchTree)
        printf("This binary tree is a binary search tree!");
    else
        printf("This binary tree is not a binary search tree!");
}

int main()
{
    FILE * file = validateFile("Tree.txt");

    Node * root = createBinaryTreeFromFile(file);

    fclose(file);

    int * vectorOfNodes = (int *)malloc(MAX_NUMBER_OF_NODES * sizeof(int));
    int numberOfNodes = 0;

    inOrderCrossing(root, vectorOfNodes, &numberOfNodes);
    checkTheTree(vectorOfNodes, numberOfNodes);

    free(vectorOfNodes);

    return 0;
}
