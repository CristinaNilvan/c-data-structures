#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

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
    Cell * hashTable = (Cell*) malloc(TABLE_SIZE * sizeof(Cell));

    testsInsertion(hashTable, TABLE_SIZE, linearProbing);
    testsInsertion(hashTable, TABLE_SIZE, quadraticProbing);
    testsInsertion(hashTable, TABLE_SIZE, doubleHashing);

    testsSearch(hashTable, TABLE_SIZE, linearProbing);

    free(hashTable);
    return 0;
}

