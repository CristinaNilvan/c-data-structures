#ifndef BINARY_TREE_BINARY_TREE_H
#define BINARY_TREE_BINARY_TREE_H

typedef struct node
{
    int id;
    struct node * left;
    struct node * right;
} Node;

FILE * validateFile(const char * fileName);

Node * createBinaryTreeFromFile(FILE * file);

int leafNode(Node * node);
int internNode(Node * node);
int height(Node * node);
Node * searchNode(Node * root, int key);

void preOrder(Node * node);
void inOrder(Node * node);
void postOrder(Node * node);

#endif //BINARY_TREE_BINARY_TREE_H
