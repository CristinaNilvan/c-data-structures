#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType
{
    int key;
    struct nodeType * next;
} Node;

void initializeLists(Node ** firstListOne, Node ** lastListOne, Node ** firstListTwo, Node ** lastListTwo)
{
    *firstListOne = NULL;
    *lastListOne = NULL;

    *firstListTwo = NULL;
    *lastListTwo = NULL;
}

Node * createNode(int key)
{
    Node * node = (Node *)malloc(sizeof(Node));

    node->key = key;
    node->next = NULL;

    return node;
}

void insertFirst(Node ** first, Node ** last, int givenKey)
{
    Node * node = createNode(givenKey);

    *first == NULL ? (*last = node) : (node->next = *first);

    *first = node;
}

void swapKeys(Node * currentNode, int temporaryKey)
{
    temporaryKey = currentNode->key;
    currentNode->key = currentNode->next->key;
    currentNode->next->key = temporaryKey;
}

void sortList(Node ** first, Node ** last)
{
    if (*first == NULL)
        return;

    Node * currentNode = *first;

    int swapped;
    int temporaryKey = 0;

    do
    {
        swapped = 0;
        currentNode = *first;

        while (currentNode->next != NULL)
        {
            if (currentNode->key > currentNode->next->key)
            {
                swapKeys(currentNode, temporaryKey);

                swapped = 1;
            }

            currentNode = currentNode->next;
        }

    } while (swapped);
}

void concatenateLists(Node ** lastListOne, Node ** firstListTwo, Node ** lastListTwo)
{
    (*lastListOne)->next = *firstListTwo;
    *lastListOne = *lastListTwo;

    *firstListTwo = NULL;
    *lastListTwo = NULL;
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

void testsTheInsertion(const char * fileName, Node ** first, Node ** last)
{
    FILE * file = fopen(fileName, "r");
    if (!file)
        return;

    int key;

    while (fscanf(file, "%d ", &key) == 1)
        insertFirst(first, last, key);

    printList(*first);
    printf("\n");

    fclose(file);
}

void testsSorting(Node ** first, Node ** last)
{
    sortList(first, last);

    printList(*first);
    printf("\n");
}

void testsConcatenation(Node ** firstListOne, Node ** lastListOne, Node ** firstListTwo, Node ** lastListTwo)
{
    concatenateLists(lastListOne, firstListTwo, lastListTwo);

    printList(*firstListOne);
    printList(*firstListTwo);
}

int main()
{
    Node * firstListOne;
    Node * lastListOne;
    Node * firstListTwo;
    Node * lastListTwo;

    initializeLists(&firstListOne, &lastListOne, &firstListTwo, &lastListTwo);

    testsTheInsertion("FirstList.txt", &firstListOne, &lastListOne);
    testsTheInsertion("SecondList.txt", &firstListTwo, &lastListTwo);

    testsSorting(&firstListOne, &lastListOne);
    testsSorting(&firstListTwo, &lastListTwo);

    testsConcatenation(&firstListOne, &lastListOne, &firstListTwo, &lastListTwo);

    return 0;
}

