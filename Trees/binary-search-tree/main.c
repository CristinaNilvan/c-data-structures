#include <stdio.h>
#include "binary_search_tree.h"

void testsInsertion(Node ** root)
{
    int nodesToInsert = 11;
    int keys[] = {15, 6, 18, 17, 20, 3, 7, 2, 4, 13, 9};

    *root = insertNode(*root, keys[0]);

    for (int i = 1; i < nodesToInsert; i++)
        insertNode(*root, keys[i]);
}

void testsSearch(Node * root)
{
    int key = 15;
    Node * node = searchNode(root, key);

    if (node != NULL)
        printf(" Node with key = %d has been found. \n\n" , key);
    else
        printf(" The node has not been found. \n\n");
}

void testsSuccessor(Node * root)
{
    int key = 15;
    Node * node = searchNode(root, key);

    Node * successor = findSuccessor(root, node);

    if (successor != NULL)
        printf(" Node with key = %d has %d as successor. \n\n" , node->key, successor->key);
    else
        printf(" The node doesn't have a successor. \n\n");
}

void testsPredecessor(Node * root)
{
    int key = 15;
    Node * node = searchNode(root, key);

    Node * predecessor = findPredecessor(root, node);

    if (predecessor != NULL)
        printf(" Node with key = %d has %d as predecessor. \n\n" , node->key, predecessor->key);
    else
        printf(" The node doesn't have a predecessor. \n\n");
}

void testsDeletion(Node ** root)
{
    int key = 15;
    
    printf(" Node to delete : %d. \n\n", key);

    *root = deleteNode(*root, key);

    preOrder(*root);
    printf("\n");
}

void testsPrint(Node * root)
{
    preOrder(root);
    printf("\n");

    inOrder(root);
    printf("\n");

    postOrder(root);
    printf("\n");

    int space = 0;
    printPretty(root, space);
    printf("\n");
}

int main() {

    Node * root = NULL;

    testsInsertion(&root);

    testsSearch(root);

    testsSuccessor(root);

    testsPredecessor(root);

    testsPrint(root);

    testsDeletion(&root);

    return 0;
}
