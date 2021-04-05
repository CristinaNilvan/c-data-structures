#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType
{
    int key;
    struct nodeType * next;
} Node;

Node * createNode(int key)
{
    Node * node = (Node *)malloc(sizeof(Node));

    node->key = key;
    node->next = NULL;

    return node;
}

void initializeLists(Node ** firstListOne, Node ** firstListTwo)
{
    *firstListOne = NULL;
    *firstListTwo = NULL;
}

void insertFirst(Node ** first, int givenKey)
{
    Node * node = createNode(givenKey);

    if (*first != NULL)
        node->next = *first;

    *first = node;
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

Node * mergeLists(Node ** firstListOne, Node ** firstListTwo)
{
    Node * firstMergedList = NULL;

    Node * current = *firstListOne;

    while (current != NULL)
    {
        if(searchNode(*firstListTwo, current->key) != NULL)
            insertFirst(&firstMergedList, current->key);

        current = current->next;
    }

    return firstMergedList;
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

void testsTheInsertion(const char * fileName, Node ** first)
{
    FILE * file = fopen(fileName, "r");
    if (!file)
        return;

    int key;

    while (fscanf(file, "%d ", &key) == 1)
        insertFirst(first, key);

    printList(*first);
    printf("\n");

    fclose(file);
}

void testsMerge(Node ** firstListOne, Node ** firstListTwo)
{
    Node * firstMergedList = mergeLists(firstListOne, firstListTwo);

    printList(firstMergedList);
}

int main()
{
    Node * firstListOne;
    Node * firstListTwo;

    initializeLists(&firstListOne, &firstListTwo);

    testsTheInsertion("FirstList.txt", &firstListOne);
    testsTheInsertion("SecondList.txt", &firstListTwo);

    testsMerge(&firstListOne, &firstListTwo);

    return 0;
}

