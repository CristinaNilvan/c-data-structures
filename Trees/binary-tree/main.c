#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int id;
    struct node * left;
    struct node * right;
}Node;

FILE * validateFile(const char * fileName)
{
    FILE * file = fopen(fileName, "r");
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
            printf("We don't have memory in createBinTree!");
            exit(5);
        }

        node->id = id;
        node->left = createBinaryTreeFromFile(file);
        node->right = createBinaryTreeFromFile(file);
    }

    return node;
}

int nodeLeaf(Node * node)
{
    if (node == NULL)
        return 0;

    if (node->left == NULL && node->right == NULL)
        return 1;

    return nodeLeaf(node->left) + nodeLeaf(node->right);
}

int internNode(Node * node)
{
    if (node == NULL)
        return 0;

    if (node->left != NULL || node->right != NULL)
        return 1 + internNode(node->left) + internNode(node->right);

    return 0;
}

int height(Node * node)
{
    if (node == NULL)
        return -1;
    else
        if (height(node->left) > height(node->right))
            return 1 + height(node->left);
        else
            return 1 + height(node->right);
}

Node * searchNode(Node * root, int key)
{
    if (root == NULL || root->id == key)
        return root;

    return searchNode(root->left, key);

    return searchNode(root->right, key);
}

void preOrder(Node * node)
{
    if (node != NULL)
    {
        printf("%d ", node->id);
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(Node * node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        printf("%d ", node->id);
        inOrder(node->right);
    }
}

void postOrder(Node * node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        printf("%d ", node->id);
    }
}

void testsFunctions(Node * root)
{
    int numberOfLeaves = nodeLeaf(root);
    int heightOfTheTree = height(root);
    int numberOfInternNodes = internNode(root);

    printf("Number of leaves : %d \n", numberOfLeaves);
    printf("Number of intern nodes : %d \n", numberOfInternNodes);
    printf("Tree height : %d \n", heightOfTheTree);
    printf("Searched node height : %d \n", height(searchNode(root, 7)));
}

void testsPrint(Node * root)
{
    preOrder(root);
    printf("\n");

    inOrder(root);
    printf("\n");

    postOrder(root);
    printf("\n");
}

int main()
{
    Node * root;
    FILE * file = validateFile("BinaryTree.txt");

    if (!file)
    {
        printf("The file can not be open! \n");
        return -1;
    }

    root = createBinaryTreeFromFile(file);

    testsFunctions(root);
    testsPrint(root);

    fclose(file);

    return 0;
}
