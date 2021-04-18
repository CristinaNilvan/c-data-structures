#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node * createNode(int key)
{
    Node * node = (Node *)malloc(sizeof(Node));

    node->key = key;
    node->next = NULL;

    return node;
}

Node * searchNode(Node * first, int givenKey)
{
    Node * current = first;

    while (current != NULL)
    {
        if (current->key == givenKey)
            break;

        current = current->next;
    }

    return current;
}

void insertFirst(Node ** first, Node ** last, int givenKey)
{
    Node * node = createNode(givenKey);

    *first == NULL ? (*last = node) : (node->next = *first);

    *first = node;
}

void insertLast(Node ** first, Node ** last, int givenKey)
{
    Node * node = createNode(givenKey);

    *last == NULL ? (*first = node) : ((*last)->next = node);

    *last = node;
}

void insertAfterKey(Node ** first, Node ** last, int afterKey, int givenKey)
{
    Node * current = *first;

    current = searchNode(current, afterKey);

    if (current == NULL)
        return;

    Node * node = createNode(givenKey);

    node->next = current->next;
    current->next = node;

    if (current == *last)
        *last = node;
}

void deleteFirst(Node ** first, Node ** last)
{
    Node * toDelete;

    if (*first == NULL)
        return;

    toDelete = *first;
    *first = (*first)->next;

    free(toDelete);

    if (*first == NULL)
        *last = NULL;
}

void getLastTwoElementsAddress(Node ** last, Node ** toDelete, Node ** previousNode)
{
    while ((*toDelete) != *last)
    {
        (*previousNode) = (*toDelete);
        (*toDelete) = (*toDelete)->next;
    }
}

void setLastElement(Node ** last, Node * previousNode)
{
    previousNode->next = NULL;
    *last = previousNode;
}

void setNodeToDelete(Node ** first, Node ** last, const Node * toDelete, Node * previousNode)
{

    if (toDelete == *first)
        first = last = NULL;
    else
        setLastElement(last, previousNode);
}

void deleteLast(Node ** first, Node ** last)
{
    Node * toDelete = *first;
    Node * previousNode = NULL;

    if (toDelete == NULL)
        return;

    getLastTwoElementsAddress(last, &toDelete, &previousNode);

    setNodeToDelete(first, last, toDelete, previousNode);
}

void deleteGivenKey(Node ** first, Node ** last, int givenKey)
{
    Node * toDelete = *first;
    Node * previousNode = NULL;

    while (toDelete != NULL)
    {
        if (toDelete->key == givenKey)
            break;

        previousNode = toDelete;
        toDelete = toDelete->next;
    }

    if (toDelete == NULL)
        return;

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

