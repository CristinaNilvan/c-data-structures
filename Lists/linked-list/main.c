#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType
{
    int key;
    struct nodeType * next;
} Node;

Node * allocateNode(int key)
{
    Node * node = (Node *)malloc(sizeof(Node));

    node->key = key;
    node->next = NULL;

    return node;
}

void insertFirst(Node ** first, Node ** last, int givenKey)
{
    Node * node = allocateNode(givenKey);

    *first == NULL ? (*last = node) : (node->next = *first);

    *first = node;
}

void insertLast(Node ** first, Node ** last, int givenKey)
{
    Node * node = allocateNode(givenKey);

    *last == NULL ? (*first = node) : ((*last)->next = node);

    *last = node;
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

void insertAfterKey(Node ** first, Node ** last, int afterKey, int givenKey)
{
    Node * current = *first;

    current = searchNode(current, afterKey);

    if (current == NULL)
        return;

    Node * node = allocateNode(givenKey);

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

void testsTheInsertion(Node ** first, Node ** last)
{
    insertFirst(first, last, 4);
    insertFirst(first, last, 1);

    insertLast(first, last, 3);
    insertLast(first, last, 8);

    insertAfterKey(first, last, 4, 22);
    insertAfterKey(first, last, 3, 25);
}

void testsTheSearch(Node * first)
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

void testsTheDeletion(Node ** first, Node ** last)
{
    deleteFirst(first, last);

    deleteLast(first, last);

    deleteGivenKey(first, last, 22);
}

int main()
{
    Node * first = NULL;
    Node * last = NULL;

    testsTheInsertion(&first, &last);
    testsTheSearch(first);

    printList(first);

    testsTheDeletion(&first, &last);

    printList(first);

    return 0;
}
