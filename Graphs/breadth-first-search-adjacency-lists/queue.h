#ifndef BREADTH_FIRST_SEARCH_ADJACENCY_LISTS_QUEUE_H
#define BREADTH_FIRST_SEARCH_ADJACENCY_LISTS_QUEUE_H

typedef struct node
{
    int key;
    struct node * next;
} Node;

typedef struct
{
    Node * first;
    Node * last;
} Queue;

Node * createNode(int key);

void initializeQueue(Queue * queue);
int empty(Queue queue);

void enqueue(Queue * queue, int givenKey);
int dequeue(Queue * queue);

#endif //BREADTH_FIRST_SEARCH_ADJACENCY_LISTS_QUEUE_H
