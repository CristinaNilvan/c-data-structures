#include <stdio.h>
#include "hash_table.h"

void setTableFree(Cell * hashTable, int size)
{
    for (int i = 0; i < size; i++)
        hashTable[i].status = FREE;
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