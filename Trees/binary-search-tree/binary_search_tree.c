#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

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

Node * searchNode(Node * root, int key)
{
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return searchNode(root->right, key);

    return searchNode(root->left, key);
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

Node * deleteNode(Node * root, int key)
{
    Node * node;

    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else
    if (key > root->key)
        root->right = deleteNode(root->right, key);
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
        root->right = deleteNode(root->right, node->key);
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
