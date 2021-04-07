#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 7
#define NUMBER_OF_ELEMENTS 10

typedef struct node
{
    char word[30];
    struct node *next;
} Node;

Node * createNode(char * word)
{
    Node * node = (Node *)malloc(sizeof(Node));
    strcpy(node->word, word);
    node->next = NULL;

    return node;
}

void initializeTable(Node ** hTable)
{
    for(int i = 0; i < TABLE_SIZE; i++)
        hTable[i] = NULL;
}

int hashCode(char * word, int numberOfElements)
{
    int sumOfAsciiCodes = 0;

    for (int i = 0; i < strlen(word); i++)
        sumOfAsciiCodes += word[i];

    return (sumOfAsciiCodes / strlen(word)) % numberOfElements;
}

int hashFunction(char * word, int numberOfElements)
{
    return (hashCode(word, numberOfElements) % TABLE_SIZE);
}

void insertElement(Node * hTable[TABLE_SIZE], char * word, int numberOfElements)
{
    int position = hashFunction(word, numberOfElements);

    if (hTable[position] == NULL)
        hTable[position] = createNode(word);
    else
    {
        Node * node = createNode(word);
        node->next = hTable[position];
        hTable[position] = node;
    }
}

void getToDeleteAndHisPrevious(char * word, Node ** toDelete, Node ** previousNode)
{
    while ((*toDelete) != NULL)
    {
        if (strcmp((*toDelete)->word, word) == 0)
            break;

        *previousNode = *toDelete;
        *toDelete = (*toDelete)->next;
    }
}

void deleteElement(Node * hTable[TABLE_SIZE], char * word, int numberOfElements)
{
    int position = hashFunction(word, numberOfElements);

    Node * toDelete = hTable[position];
    Node * previousNode = NULL;

    getToDeleteAndHisPrevious(word, &toDelete, &previousNode);

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

void showAll(Node * hTable[TABLE_SIZE])
{
    for(int position = 0; position < TABLE_SIZE; position++)
    {
        printf(" %d :", position);

        if(hTable[position] != NULL)
        {
            Node * node;
            node = hTable[position];
            while (node != NULL)
            {
                printf(" %s ", node->word);
                node = node->next;
            }
        }
        printf("\n");
    }
    printf("\n");
}

void testsInsertion(Node ** hTable)
{
    char valuesToInsert[][30] = {"simply", "text ", "point", "normal", "random", "sites", "model", "galley", "data", "from"};

    for(int i = 0; i < NUMBER_OF_ELEMENTS; i++)
        insertElement(hTable, valuesToInsert[i], NUMBER_OF_ELEMENTS);

    showAll(hTable);
}

void testsDeletion(Node ** hTable)
{
    char valuesToDelete[][30] = {"simply", "point", "random", "model"};
    int numberOfElementsToDelete = 4;

    for(int i = 0; i < numberOfElementsToDelete; i++)
        deleteElement(hTable, valuesToDelete[i], NUMBER_OF_ELEMENTS);

    showAll(hTable);
}

int main()
{
    Node * hTable[TABLE_SIZE];
    initializeTable(hTable);

    testsInsertion(hTable);
    testsDeletion(hTable);

    return 0;
}