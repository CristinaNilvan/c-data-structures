#ifndef HASH_TABLE_CHAINING_HASH_TABLE_H
#define HASH_TABLE_CHAINING_HASH_TABLE_H

#define TABLE_SIZE 7

typedef struct node
{
    int key;
    struct node * next;
} Node;

Node * createNode(int key);
void initializeTable(Node ** hashTable);

int hashFunction(int key);

void insertElement(Node * hashTable[TABLE_SIZE], int key);
void getToDeleteAndHisPrevious(int key, Node ** toDelete, Node ** previousNode);
void deleteElement(Node * hashTable[TABLE_SIZE], int key);

void showAll(Node * hashTable[TABLE_SIZE]);

#endif //HASH_TABLE_CHAINING_HASH_TABLE_H
