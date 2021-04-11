#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

typedef struct nodeType
{
    int key;
    struct nodeType * left;
    struct nodeType * right;
} Node;

Node * createNode(int key)
{
    Node * newNode = (Node *)malloc(sizeof(Node));

    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node * insertNode(Node * root, int key)
{
    Node * newNode = createNode(key);

    Node * currentNode = root;
    Node * toInsert = NULL;

    while (currentNode != NULL)
    {
        toInsert = currentNode;

        if (key < currentNode->key)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;
    }

    if (toInsert == NULL)
        toInsert = newNode;
    else
        if (key < toInsert->key)
            toInsert->left = newNode;
        else
            toInsert->right = newNode;

    return toInsert;
}

Node * searchKey(Node * root, int key)
{
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return searchKey(root->left, key);

    return searchKey(root->right, key);
}

Node * findMin(Node * root)
{
    if (root == NULL)
        return NULL;

    Node * currentNode = root;

    while (currentNode->left != NULL)
        currentNode = currentNode->left;

    return currentNode;
}

Node * findMax(Node * root)
{
    if (root == NULL)
        return NULL;

    Node * currentNode = root;

    while (currentNode->right != NULL)
        currentNode = currentNode->right;

    return currentNode;
}

Node * findSuccessor(Node * root, Node * node)
{
    if (node == NULL || root == NULL)
        return NULL;

    if (node->right != NULL)
        return findMin(node->right);

    Node * currentNode = root;
    Node * successor = NULL;

    while (currentNode != NULL && currentNode->key != node-> key)
    {
        if (node->key < currentNode->key)
        {
            successor = currentNode;
            currentNode = currentNode->left;
        }
        else
            currentNode = currentNode->right;
    }

    if (currentNode == NULL)
        return NULL;

    return successor;
}

Node * findPredecessor(Node * root, Node * node)
{
    if (node == NULL || root == NULL)
        return NULL;

    if (node->left != NULL)
        return findMax(node->left);

    Node * currentNode = root;
    Node * predecessor = NULL;

    while (currentNode != NULL && currentNode->key != node-> key)
    {
        if (node->key < currentNode->key)
            currentNode = currentNode->left;
        else
        {
            predecessor = currentNode;
            currentNode = currentNode->right;
        }
    }

    if (currentNode == NULL)
        return NULL;

    return predecessor;
}

Node * deleteKey(Node * root, int key)
{
    Node * node;

    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteKey(root->left, key);
    else
        if (key > root->key)
            root->right = deleteKey(root->right, key);
        else
        {
            if (root->left == NULL)
            {
                node = root->right;
                free(root);
                return node;
            }
            else
                if (root->right == NULL)
                {
                    node = root->left;
                    free(root);
                    return node;
                }

            node = findMin(root->right);
            root->key = node->key;
            root->right = deleteKey(root->right, node->key);
        }

    return root;
}


void inOrder(Node * root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void preOrder(Node * root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node * root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

void printPretty(Node * root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;

    printPretty(root->right, space);

    printf("\n");

    for (int i = COUNT; i < space; i++)
        printf(" ");

    printf("%d \n", root->key);

    printPretty(root->left, space);
}

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
    Node * node = searchKey(root, key);

    if (node != NULL)
        printf(" Node with key = %d has been found. \n\n" , key);
    else
        printf(" The node has not been found. \n\n");
}

void testsSuccessor(Node * root)
{
    int key = 15;
    Node * node = searchKey(root, key);

    Node * successor = findSuccessor(root, node);

    if (successor != NULL)
        printf(" Node with key = %d has %d as successor. \n\n" , node->key, successor->key);
    else
        printf(" The node doesn't have a successor. \n\n");
}

void testsPredecessor(Node * root)
{
    int key = 15;
    Node * node = searchKey(root, key);

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

    *root = deleteKey(*root, key);

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
