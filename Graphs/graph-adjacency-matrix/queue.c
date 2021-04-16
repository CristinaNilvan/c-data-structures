#include <stdlib.h>
#include "queue.h"

Node * createNode(int key)
{
    Node * node = (Node *)malloc(sizeof(Node));

    node->key = key;
    node->next = NULL;

    return node;
}

void initializeQueue(Queue * queue)
{
    queue->first = NULL;
    queue->last = NULL;
}

int empty(Queue queue)
{
    return queue.first == NULL;
}

void enqueue(Queue * queue, int givenKey)
{
    Node * node = createNode(givenKey);

    if (queue->last == NULL)
        queue->first = node;
    else
        queue->last->next = node;

    queue->last = node;
}

int dequeue(Queue * queue)
{
    if (queue->first == NULL)
        return -1;

    Node * node = queue->first;

    int element = node->key;

    queue->first = queue->first->next;
    free(node);

    if (queue->first == NULL)
        queue->last = NULL;

    return element;
}


