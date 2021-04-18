#include "queue.h"

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
