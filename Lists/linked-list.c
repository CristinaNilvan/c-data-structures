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

void insertFirst(NodeT ** first, NodeT ** last, int givenKey)
{
    NodeT * node = allocateNode(givenKey);

    if (*first == NULL)
        *last = node;
    else
        node->next = *first;

    *first = node;
}

void insertLast(NodeT ** first, NodeT ** last, int givenKey)
{
    NodeT * node = allocateNode(givenKey);

    if (*last == NULL)
        *first = node;
    else
        (*last)->next = node;

    *last = node;
}

void insertAfterKey(NodeT ** first, NodeT ** last, int afterKey, int givenKey)
{
    NodeT * current = *first;

    while (current != NULL)
    {
        if (current->key == afterKey)
            break;

        current = current->next;
    }

    if (current != NULL)
    {
        NodeT * node = allocateNode(givenKey);

        node->next = current->next;
        current->next = node;

        if (current == *last)
            *last = node;
    }
}

NodeT * searchNode(NodeT * first, int givenKey)
{
    NodeT * current = first;

    while (current != NULL)
    {
        if (current->key == givenKey)
            break;

        current = current->next;
    }

    return current;
}

void deleteFirst(NodeT ** first, NodeT ** last)
{
    NodeT * toDelete;

    if (*first != NULL)
    {
        toDelete = *first;
        *first = (*first)->next;

        free(toDelete);

        if (*first == NULL)
            *last = NULL;
    }
}

void deleteLast(NodeT ** first, NodeT ** last)
{
    NodeT * toDelete = *first;
    NodeT * previousNode = NULL;

    if (toDelete != NULL)
    {
        while (toDelete != *last)
        {
            previousNode = toDelete;
            toDelete = toDelete->next;
        }

        if (toDelete == *first)
            first = last = NULL;
        else
        {
            previousNode->next = NULL;
            *last = previousNode;
        }
    }
}

void deleteGivenKey(NodeT ** first, NodeT ** last, int givenKey)
{
    NodeT * toDelete = *first;
    NodeT * previousNode = NULL;

    while (toDelete != NULL)
    {
        if (toDelete->key == givenKey)
            break;

        previousNode = toDelete;
        toDelete = toDelete->next;
    }

    if (toDelete != NULL)
    {
        if (toDelete == *first)
        {
            *first = (*first)->next;

            free(toDelete);

            if (*first == NULL)
                *last = NULL;
        }
        else
        {
            previousNode->next = toDelete->next;

            if (toDelete == *last)
                *last = previousNode;

            free(toDelete);
        }
    }
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

void testsTheInsertion(NodeT ** first, NodeT ** last)
{
    insertFirst(first, last, 4);
    insertFirst(first, last, 1);

    insertLast(first, last, 3);
    insertLast(first, last, 8);

    insertAfterKey(first, last, 4, 22);
    insertAfterKey(first, last, 3, 25);
}

void testsTheSearch(NodeT * first)
{
    if (searchNode(first, 2) != NULL)
        printf("The key was found. \n");
    else
        printf("The key was not found. \n");

    if (searchNode(first, 3) != NULL)
        printf("The key was found. \n");
    else
        printf("The key was not found. \n");
}

void testsTheDeletion(NodeT ** first, NodeT ** last)
{
    deleteFirst(first, last);

    deleteLast(first, last);

    deleteGivenKey(first, last, 22);
}

int main()
{
    NodeT * first = NULL;
    NodeT * last = NULL;

    testsTheInsertion(&first, &last);
    testsTheSearch(first);

    printList(first);

    testsTheDeletion(&first, &last);

    printList(first);

    return 0;
}
