#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType
{
    int key;
    struct nodeType * next;
    struct nodeType * prev;

} Node;

struct listHeader
{
    Node * first;
    Node * last;
};

Node * createNode(int key)
{
    Node * node = (Node *)malloc(sizeof(Node));

    node->key = key;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void setExtremesToNode(struct listHeader * list, Node * node)
{
    list->first = node;
    list->last = node;
}

void addKeyToFirstPartOfList(struct listHeader * list, Node * node)
{
    node->next = list->first;
    list->first->prev = node;
    list->first = node;
}

void insertFirst(struct listHeader * list, int givenKey)
{
    Node * node = createNode(givenKey);

    list->first == NULL ? setExtremesToNode(list, node) : addKeyToFirstPartOfList(list, node);
}

void addKeyToLastPartOfList(struct listHeader * list, Node * node)
{
    node->prev = list->last;
    list->last->next = node;
    list->last = node;
}

void insertLast(struct listHeader * list, int givenKey)
{
    Node * node = createNode(givenKey);

    list->last == NULL ? setExtremesToNode(list, node) : addKeyToLastPartOfList(list, node);
}

Node * searchNode(struct listHeader * list, int givenKey)
{
    Node * current = list->first;

    while (current != NULL)
    {
        if (current->key == givenKey)
            break;

        current = current->next;
    }

    return current;
}

void insertAfterKey(struct listHeader * list, int afterKey, int givenKey)
{
    Node * current = searchNode(list, afterKey);

    if (current == NULL)
        return;

    Node * node = createNode(givenKey);

    node->prev = current;
    node->next = current->next;

    if (current->next != NULL)
        current->next->prev = node;

    current->next = node;

    if (list->last == current)
        list->last = node;
}

void deleteFirst(struct listHeader * list)
{
    Node * toDelete;

    if (list->first == NULL)
        return;

    toDelete = list->first;
    list->first = list->first->next;

    free(toDelete);

    (list->first == NULL) ? list->last = NULL : (list->first->prev = NULL);
}

void deleteLast(struct listHeader * list)
{
    Node * toDelete = list->last;

    if (toDelete == NULL)
        return;

    toDelete = list->last;
    list->last = list->last->prev;

    (list->last == NULL) ? list->first = NULL : (list->last->next = NULL);

    free(toDelete);
}

void deleteKey(struct listHeader * list, int givenKey)
{
    Node * toDelete = searchNode(list, givenKey);

    toDelete->prev != NULL ? toDelete->prev->next = toDelete->next : (list->first = toDelete->next);

    toDelete->next != NULL ? toDelete->next->prev = toDelete->prev : (list->last = toDelete->prev);

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
