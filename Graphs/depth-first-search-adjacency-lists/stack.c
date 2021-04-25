#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Node * createNode(int key)
{
    Node * node = (Node *)malloc(sizeof(Node));

    node->key = key;
    node->next = NULL;

    return node;
}

void initializeStack(Node ** stack)
{
    *stack = NULL;
}

int empty(Node * stack)
{
    return stack == NULL;
}

void push(Node ** stack, int givenKey)
{
    Node * node = createNode(givenKey);

    if (*stack == NULL)
        *stack = node;
    else
    {
        node->next = *stack;
        *stack = node;
    }
}

int pop(Node ** stack)
{
    int deletedKey = -1;

    if (*stack != NULL)
    {
        Node * toDelete = *stack;

        *stack = (*stack)->next;
        deletedKey = toDelete->key;

        free(toDelete);
    }

    return deletedKey;
}
