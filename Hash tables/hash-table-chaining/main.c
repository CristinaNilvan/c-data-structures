#include <stdio.h>
#include <stdlib.h>
#define M 7

typedef struct node
{
    int key;
    struct node * next;
} Node;

Node * createNode(int key)
{
    Node * node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->next = NULL;

    return node;
}

void initializeTable(Node ** hTable)
{
    for(int i = 0; i < M; i++)
        hTable[i] = NULL;
}

int hashFunction(int key)
{
    if (key < 0)
        key = -key;

    return key % M;
}

void insertElement(Node * hTable[M], int key)
{
    int position = hashFunction(key);

    if (hTable[position] == NULL)
        hTable[position] = createNode(key);
    else
    {
        Node * node = createNode(key);
        node->next = hTable[position];
        hTable[position] = node;
    }
}

void getToDeleteAndHisPrevious(int key, Node ** toDelete, Node ** previousNode)
{
    while ((*toDelete) != NULL)
    {
        if ((*toDelete)->key == key)
            break;

        *previousNode = *toDelete;
        *toDelete = (*toDelete)->next;
    }
}

void deleteElement(Node * hTable[M], int key)
{
    int position = hashFunction(key);

    Node * toDelete = hTable[position];
    Node * previousNode = NULL;

    getToDeleteAndHisPrevious(key, &toDelete, &previousNode);

    if (toDelete == NULL)
        return;

    if (toDelete == hTable[position])
    {
        hTable[position] = hTable[position]->next;

        free(toDelete);
    }
    else
    {
        previousNode->next = toDelete->next;

        free(toDelete);
    }
}

void showAll(Node * hTable[M])
{
    for(int position = 0; position < M; position++)
    {
        printf(" %d :", position);

        if(hTable[position] != NULL)
        {
            Node * node;
            node = hTable[position];
            while (node != NULL)
            {
                printf(" %d ", node->key);
                node = node->next;
            }
        }
        printf("\n");
    }
    printf("\n");
}

void testsInsertion(Node ** hTable)
{
    int values[] = {36, 18, 6, 43, 72, 10, 5, 15};

    for(int i = 0; i < sizeof(values) / sizeof(int); i++)
        insertElement(hTable, values[i]);

    showAll(hTable);
}

void testsDeletion(Node ** hTable)
{
    int toDeleteValues[] = {43, 36, 10, 61, -5};

    for(int i = 0; i < sizeof(toDeleteValues) / sizeof(int); i++)
        deleteElement(hTable, toDeleteValues[i]);

    showAll(hTable);
}

int main()
{
    Node * hTable[M];
    initializeTable(hTable);

    testsInsertion(hTable);
    testsDeletion(hTable);

    return 0;
}

