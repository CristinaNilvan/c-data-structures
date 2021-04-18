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

void initializeList(Node ** stack)
{
    *stack = NULL;
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

void pop(Node ** stack)
{
    Node * toDelete;

    if (*stack != NULL)
    {
        toDelete = *stack;
        *stack = (*stack)->next;

        free(toDelete);
    }
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