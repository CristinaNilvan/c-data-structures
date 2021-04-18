#ifndef BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H

#define COUNT 10

typedef struct nodeType
{
    int key;
    struct nodeType * left;
    struct nodeType * right;
} Node;

Node * createNode(int key);

Node * insertNode(Node * root, int key);
Node * searchNode(Node * root, int key);
Node * findMin(Node * root);
Node * findMax(Node * root);
Node * findSuccessor(Node * root, Node * node);
Node * findPredecessor(Node * root, Node * node);
Node * deleteNode(Node * root, int key);

void inOrder(Node * root);
void preOrder(Node * root);
void postOrder(Node * root);
void printPretty(Node * root, int space);

#endif //BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H
