#ifndef DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H

typedef struct nodeType
{
    int key;
    struct nodeType * next;
    struct nodeType * prev;

} Node;

struct listHeader
{
    Node * first;
    Node * last;
};

Node * createNode(int key);
Node * searchNode(struct listHeader * list, int givenKey);

void setExtremesToNode(struct listHeader * list, Node * node);
void addKeyToFirstPartOfList(struct listHeader * list, Node * node);
void insertFirst(struct listHeader * list, int givenKey);
void addKeyToLastPartOfList(struct listHeader * list, Node * node);
void insertLast(struct listHeader * list, int givenKey);
void insertAfterKey(struct listHeader * list, int afterKey, int givenKey);

void deleteFirst(struct listHeader * list);
void deleteLast(struct listHeader * list);
void deleteKey(struct listHeader * list, int givenKey);

void printForward(struct listHeader * list);
void printBackward(struct listHeader * list);

#endif //DOUBLY_LINKED_LIST_DOUBLY_LINKED_LIST_H
