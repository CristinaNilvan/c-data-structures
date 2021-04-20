#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

Node * createNode(int key)
{
    Node * node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->next = NULL;

    return node;
}

void initializeTable(Node ** hashTable)
{
    for(int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;
}

int hashFunction(int key)
{
    if (key < 0)
        key = -key;

    return key % TABLE_SIZE;
}

void insertElement(Node * hashTable[TABLE_SIZE], int key)
{
    int position = hashFunction(key);

    if (hashTable[position] == NULL)
        hashTable[position] = createNode(key);
    else
    {
        Node * node = createNode(key);
        node->next = hashTable[position];
        hashTable[position] = node;
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

void deleteElement(Node * hashTable[TABLE_SIZE], int key)
{
    int position = hashFunction(key);

    Node * toDelete = hashTable[position];
    Node * previousNode = NULL;

    getToDeleteAndHisPrevious(key, &toDelete, &previousNode);

    if (toDelete == NULL)
        return;

    if (toDelete == hashTable[position])
    {
        hashTable[position] = hashTable[position]->next;

        free(toDelete);
    }
    else
    {
        previousNode->next = toDelete->next;

        free(toDelete);
    }
}

void showAll(Node * hashTable[TABLE_SIZE])
{
    for(int position = 0; position < TABLE_SIZE; position++)
    {
        printf(" %d :", position);

        if(hashTable[position] != NULL)
        {
            Node * node;
            node = hashTable[position];
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
