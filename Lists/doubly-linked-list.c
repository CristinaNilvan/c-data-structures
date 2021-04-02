#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType
{
    int key;
    struct nodeType * next;
    struct nodeType * prev;
} NodeDL;

struct listHeader
{
    NodeDL * first;
    NodeDL * last;
};

NodeDL * allocateNode(int key)
{
    NodeDL * node = (NodeDL *)malloc(sizeof(NodeDL));

    node->key = key;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void insertFirst(struct listHeader * list, int givenKey)
{
    NodeDL * node = allocateNode(givenKey);

    if (list->first == NULL)
    {
        list->first = node;
        list->last = node;
    }
    else
    {
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
    }
}

void insertLast(struct listHeader * list, int givenKey)
{
    NodeDL * node = allocateNode(givenKey);

    if (list->last == NULL)
    {
        list->first = node;
        list->last = node;
    }
    else
    {
        node->prev = list->last;
        list->last->next = node;
        list->last = node;
    }
}

void insertAfterKey(struct listHeader * list, int afterKey, int givenKey)
{
    NodeDL * current = list->first;

    while (current != NULL)
    {
        if (current->key == afterKey)
            break;

        current = current->next;
    }

    if (current != NULL)
    {
        NodeDL * node = allocateNode(givenKey);

        node->prev = current;
        node->next = current->next;

        if (current->next != NULL)
            current->next->prev = node;

        current->next = node;

        if (list->last == current)
            list->last = node;
    }
}

NodeDL * searchNode(struct listHeader * list, int givenKey)
{
    NodeDL * current = list->first;

    while (current != NULL)
    {

        if (current->key == givenKey)
            break;

        current = current->next;
    }

    return current;
}

void deleteFirst(struct listHeader * list)
{
    NodeDL * toDelete;

    if (list->first != NULL)
    {
        toDelete = list->first;
        list->first = list->first->next;

        free(toDelete);

        if (list->first == NULL)
            list->last = NULL;
        else
            list->first->prev = NULL;
    }
}

void deleteLast(struct listHeader * list)
{
    NodeDL * toDelete = list->last;

    if (toDelete != NULL)
    {
        toDelete = list->last;
        list->last = list->last->prev;

        if (list->last == NULL)
            list->first = NULL;
        else
            list->last->next = NULL;
    }

    free(toDelete);
}

void deleteKey(struct listHeader * list, int givenKey)
{
    NodeDL * toDelete = searchNode(list, givenKey);

    if (toDelete->prev != NULL)
        toDelete->prev->next = toDelete->next;
    else
        list->first = toDelete->next;

    if (toDelete->next != NULL)
        toDelete->next->prev = toDelete->prev;
    else
        list->last = toDelete->prev;

    free(toDelete);
}

void printForward(struct listHeader * list)
{
    if (list->first == NULL)
    {
        printf("\n");
        return;
    }

    printf("%d ", list->first->key);

    list->first = list->first->next;

    printForward(list);
}

void printBackward(struct listHeader * list)
{
    if (list->last == NULL)
    {
        printf("\n");
        return;
    }

    printf("%d ", list->last->key);

    list->last = list->last->prev;

    printBackward(list);
}

void testsTheInsertion(struct listHeader * list)
{
    insertFirst(list, 8);
    insertFirst(list, 9);

    insertLast(list, 7);
    insertLast(list, 6);

    insertAfterKey(list, 7, 5);
}

void testsTheDeletion(struct listHeader * list)
{
    deleteFirst(list);

    deleteLast(list);

    deleteKey(list, 7);
}

void testsPrint(struct listHeader * list)
{
    printForward(list);
    printBackward(list);
}

int main()
{
    struct listHeader list = {NULL, NULL};

    testsTheInsertion(&list);
    testsTheDeletion(&list);

    testsPrint(&list);

    return 0;
}
