#include <stdio.h>
#include "binary_tree.h"

void testsFunctions(Node * root)
{
    int numberOfLeaves = leafNode(root);
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
