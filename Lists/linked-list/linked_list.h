#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

typedef struct nodeType
{
    int key;
    struct nodeType * next;
} Node;

Node * createNode(int key);
Node * searchNode(Node * first, int givenKey);

void insertFirst(Node ** first, Node ** last, int givenKey);
void insertLast(Node ** first, Node ** last, int givenKey);
void insertAfterKey(Node ** first, Node ** last, int afterKey, int givenKey);

void deleteFirst(Node ** first, Node ** last);
void getLastTwoElementsAddress(Node ** last, Node ** toDelete, Node ** previousNode);
void setLastElement(Node ** last, Node * previousNode);
void setNodeToDelete(Node ** first, Node ** last, const Node * toDelete, Node * previousNode);
void deleteLast(Node ** first, Node ** last);
void deleteGivenKey(Node ** first, Node ** last, int givenKey);

void printList(Node * node);

#endif //LINKED_LIST_LINKED_LIST_H
