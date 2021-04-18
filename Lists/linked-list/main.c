#include <stdio.h>
#include "linked_list.h"

void testsTheInsertion(Node ** first, Node ** last)
{
    insertFirst(first, last, 4);
    insertFirst(first, last, 1);

    insertLast(first, last, 3);
    insertLast(first, last, 8);

    insertAfterKey(first, last, 4, 22);
    insertAfterKey(first, last, 3, 25);
}

void testsTheSearch(Node * first)
{
    if (searchNode(first, 2) != NULL)
        printf("The key was found. \n");
    else
        printf("The key was not found. \n");

    if (searchNode(first, 3) != NULL)
        printf("The key was found. \n");
    else
        printf("The key was not found. \n");
}

void testsTheDeletion(Node ** first, Node ** last)
{
    deleteFirst(first, last);

    deleteLast(first, last);

    deleteGivenKey(first, last, 22);
}

int main()
{
    Node * first = NULL;
    Node * last = NULL;

    testsTheInsertion(&first, &last);
    testsTheSearch(first);

    printList(first);

    testsTheDeletion(&first, &last);

    printList(first);

    return 0;
}
