#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

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

void enqueue(Queue * queue, int givenKey);
int dequeue(Queue * queue);

void printList(Node * node);

#endif //QUEUE_QUEUE_H
