#ifndef STACK_STACK_H
#define STACK_STACK_H

typedef struct nodeType
{
    int key;
    struct nodeType * next;
} Node;

Node * createNode(int key);
void initializeList(Node ** stack);

void push(Node ** stack, int givenKey);
void pop(Node ** stack);

void printList(Node * node);

#endif //STACK_STACK_H
