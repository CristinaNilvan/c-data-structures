#include <stdio.h>
#include <stdlib.h>
#define M 10

typedef struct node
{
    int key;
    struct node *next;
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
    while (*toDelete != NULL)
    {
        if ((*toDelete)->key == key)
            break;

        *previousNode = *toDelete;
        *toDelete = (*toDelete)->next;
    }
}

void deleteElement(Node * hTable[M], int key, Node ** nextElement)
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

        *nextElement = hTable[position];

        free(toDelete);
    }
    else
    {
        previousNode->next = toDelete->next;

        *nextElement = previousNode->next;

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

void harmonicMean(float * sum, float * product, int number)
{
    *sum += number;
    *product *= number;
}

int isPalindrome(int number)
{
    int auxiliary = number;
    int reversedNumber = 0;

    while (auxiliary > 0)
    {
        reversedNumber = reversedNumber * 10 + auxiliary % 10;
        auxiliary /= 10;
    }

    return (reversedNumber == number);
}

float harmonicMeanOfPalindromes(Node * hTable[M])
{
    int numberOfPalindromes = 0;
    float sum = 0, product = 1;

    for (int i = 0; i < M; ++i)
    {
        Node * currentNode = hTable[i];

        if (currentNode != NULL)
        {
            while (currentNode != NULL)
            {
                if (isPalindrome(currentNode->key) == 1)
                {
                    numberOfPalindromes += 1;
                    harmonicMean(&sum, &product, currentNode->key);
                }

                currentNode = currentNode->next;
            }
        }
    }

    return (numberOfPalindromes * product) / sum;
}

void deletePalindromes(Node * hTable[M])
{
    for (int i = 0; i < M; ++i)
    {
        Node * currentNode = hTable[i];

        if (currentNode != NULL)
        {
            while (currentNode != NULL)
            {
                if (isPalindrome(currentNode->key) == 1)
                {
                    Node * nextNode;
                    deleteElement(hTable, currentNode->key, &nextNode);

                    currentNode = nextNode;
                }
                else
                    currentNode = currentNode->next;
            }
        }
    }
}

void testsInsertion(Node * hTable[M])
{
    int values[] = {9, 11, 13, 19, 22, 20, 23, 7, 2, 1};

    for(int i = 0; i < sizeof(values) / sizeof(int); i++)
        insertElement(hTable, values[i]);

    showAll(hTable);
}

void testsHarmonicMean(Node * hTable[M])
{
    float harmonicMean = harmonicMeanOfPalindromes(hTable);

    printf("The harmonic mean of palindromes is %f. \n\n", harmonicMean);
}

void testsDeletionOfPalindromes(Node * hTable[M])
{
    deletePalindromes(hTable);

    showAll(hTable);
}

int main()
{
    Node * hTable[M];
    initializeTable(hTable);

    testsInsertion(hTable);

    testsHarmonicMean(hTable);

    testsDeletionOfPalindromes(hTable);

    return 0;
}


