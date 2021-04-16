#include <stdio.h>
#include <stdlib.h>

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

void printList(Node * node)
{
    if (node == NULL)
    {
        printf("\n");
        return;
    }

    printf("%d ", node->key);
    printList(node->next);
}

Queue testsEnqueue(Queue * queue)
{
    enqueue(queue, 6);
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 9);
    enqueue(queue, 10);

    printList((*queue).first);

    return (*queue);
}

void testsDequeue(Queue * queue)
{
    dequeue(queue);
    dequeue(queue);

    printList((*queue).first);
}

int main()
{
    Queue queue;
    initializeQueue(&queue);

    queue = testsEnqueue(&queue);

    testsDequeue(&queue);

    return 0;
}
