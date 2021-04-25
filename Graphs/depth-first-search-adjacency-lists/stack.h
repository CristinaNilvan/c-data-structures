#ifndef DEPTH_FIRST_SEARCH_ADJACENCY_LISTS_STACK_H
#define DEPTH_FIRST_SEARCH_ADJACENCY_LISTS_STACK_H

typedef struct node
{
    int key;
    struct node * next;
} Node;

Node * createNode(int key);

void initializeStack(Node ** stack);
int empty(Node * stack);

void push(Node ** stack, int givenKey);
int pop(Node ** stack);

#endif //DEPTH_FIRST_SEARCH_ADJACENCY_LISTS_STACK_H
