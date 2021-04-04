#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType
{
    int key;
    struct nodeType * next;
} NodeT;

NodeT * allocateNode(int key)
{
    NodeT * node = (NodeT *)malloc(sizeof(NodeT));

    node->key = key;
    node->next = NULL;

    return node;
}

void push(NodeT ** stack, int givenKey)
{
    NodeT * node = allocateNode(givenKey);

    if (*stack == NULL)
        *stack = node;
    else
    {
        node->next = *stack;
        *stack = node;
    }
}

void pop(NodeT ** stack)
{
    NodeT * toDelete;

    if (*stack != NULL)
    {
        toDelete = *stack;
        *stack = (*stack)->next;

        free(toDelete);
    }
}

void initializeList(NodeT ** stack)
{
    *stack = NULL;
}

void printList(NodeT * node)
{
    if (node == NULL)
    {
        printf("\n");
        return;
    }

    printf("%d ", node->key);
    printList(node->next);
}

void testsPush(NodeT ** stack)
{
    push(stack, 3);
    printList(*stack);

    push(stack, 4);
    printList(*stack);

    push(stack, 7);
    printList(*stack);
}

void testsPop(NodeT ** stack)
{
    pop(stack);
    printList(*stack);
}

int main()
{
    NodeT * stack;

    initializeList(&stack);

    testsPush(&stack);
    testsPop(&stack);

    return 0;
}
