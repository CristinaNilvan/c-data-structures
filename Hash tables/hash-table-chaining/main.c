#include "hash_table.h"

void testsInsertion(Node ** hashTable)
{
    int values[] = {36, 18, 6, 43, 72, 10, 5, 15};

    for(int i = 0; i < sizeof(values) / sizeof(int); i++)
        insertElement(hashTable, values[i]);

    showAll(hashTable);
}

void testsDeletion(Node ** hashTable)
{
    int toDeleteValues[] = {43, 36, 10, 61, -5};

    for(int i = 0; i < sizeof(toDeleteValues) / sizeof(int); i++)
        deleteElement(hashTable, toDeleteValues[i]);

    showAll(hashTable);
}

int main()
{
    Node * hashTable[TABLE_SIZE];
    initializeTable(hashTable);

    testsInsertion(hashTable);
    testsDeletion(hashTable);

    return 0;
}

