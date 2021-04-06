#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

typedef struct cell
{
    int key;
    int status;
} Cell;

enum {FREE, OCCUPIED};

void printTable(Cell * hashTable, int size)
{
    printf("\n\n The hash table is : \n");

    for (int i = 0; i < size; i++)
    {
        if(hashTable[i].status == OCCUPIED)
            printf("Table[%d] = %d \n", i, hashTable[i].key);
        else
            printf("Table[%d] = -- \n", i);
    }
}

void insertKey(int value, Cell * hashTable, int size, int (*hashFunction)(int k, int m, int i))
{
    for (int i = 0; i < size; i++)
    {
        int position = hashFunction(value, size, i);

        if (hashTable[position].status == FREE)
        {
            hashTable[position].key = value;
            hashTable[position].status = OCCUPIED;
            return;
        }
    }
}

int searchKey(int value, Cell * hashTable, int size, int (*hashFunction)(int k, int m, int i))
{
    for (int i = 0; i < size; i++)
    {
        int position = hashFunction(value, size, i);

        if (hashTable[position].status == FREE)
            return -1;
        else
            if (hashTable[position].key == value)
                return position;
    }
    return -1;
}

int hashFunctionOne(int k, int m)
{
    if (k < 0)
        k = -k;

    return k % m;
}

int hashFunctionTwo(int k)
{
    return 5 - (k % 5);
}

int linearProbing(int k, int m, int i)
{
    return (hashFunctionOne(k, m) + i) % m;
}

int quadraticProbing(int k, int m, int i)
{
    return (hashFunctionOne(k,m) + i + i*i) % m;
}

int doubleHashing(int k, int m, int i)
{
    return (hashFunctionOne(k,m) + i * hashFunctionTwo(k)) % m;
}

void setTableFree(Cell * hashTable, int size)
{
    for (int i = 0; i < size; i++)
        hashTable[i].status = FREE;
}

void testsInsertion(Cell * hashTable, int size, int (*hashFunction)(int k, int m, int i))
{
    setTableFree(hashTable, size);

    int values[] = {19, 36, 5, 21, 4, 26, 14, 17};

    for (int i = 0; i < sizeof(values) / sizeof(int); i++)
        insertKey(values[i], hashTable, size, hashFunction);

    printTable(hashTable, size);
}

void testsSearch(Cell * hashTable, int size, int (*hashFunction)(int k, int m, int i))
{
    setTableFree(hashTable, size);

    int values[] = {19, 36, 5, 21, 4, 26, 14, 17};

    for (int i = 0; i < sizeof(values) / sizeof(int); i++)
        insertKey(values[i], hashTable, size, hashFunction);

    printf("\n");

    for (int i = 0; i < sizeof(values) / sizeof(int); i++)
    {
        int position = searchKey(values[i], hashTable, size, linearProbing);

        if (position != -1)
            printf("Key %d has the position %d. \n", values[i], position);
    }
}

int main()
{
    Cell * hashTable = (Cell*) malloc(SIZE * sizeof(Cell));

    testsInsertion(hashTable, SIZE, linearProbing);
    testsInsertion(hashTable, SIZE, quadraticProbing);
    testsInsertion(hashTable, SIZE, doubleHashing);

    testsSearch(hashTable, SIZE, linearProbing);

    free(hashTable);
    return 0;
}

