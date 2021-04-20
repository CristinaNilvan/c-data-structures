#ifndef HASH_TABLE_OPEN_ADDRESSING_HASH_TABLE_H
#define HASH_TABLE_OPEN_ADDRESSING_HASH_TABLE_H

#define TABLE_SIZE 7

typedef struct cell
{
    int key;
    int status;
} Cell;

enum {FREE, OCCUPIED};

void setTableFree(Cell * hashTable, int size);

void insertKey(int value, Cell * hashTable, int size, int (*hashFunction)(int k, int m, int i));
int searchKey(int value, Cell * hashTable, int size, int (*hashFunction)(int k, int m, int i));

int hashFunctionOne(int k, int m);
int hashFunctionTwo(int k);

int linearProbing(int k, int m, int i);
int quadraticProbing(int k, int m, int i);
int doubleHashing(int k, int m, int i);

void printTable(Cell * hashTable, int size);

#endif //HASH_TABLE_OPEN_ADDRESSING_HASH_TABLE_H
