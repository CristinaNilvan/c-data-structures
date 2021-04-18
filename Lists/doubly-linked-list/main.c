#include <stdio.h>
#include "doubly_linked_list.h"

void testsTheInsertion(struct listHeader * list)
{
    insertFirst(list, 8);
    insertFirst(list, 9);

    insertLast(list, 7);
    insertLast(list, 6);

    insertAfterKey(list, 7, 5);
}

void testsTheDeletion(struct listHeader * list)
{
    deleteFirst(list);

    deleteLast(list);

    deleteKey(list, 7);
}

void testsPrint(struct listHeader * list)
{
    printForward(list);
    printBackward(list);
}

int main()
{
    struct listHeader list = {NULL, NULL};

    testsTheInsertion(&list);
    testsTheDeletion(&list);

    testsPrint(&list);

    return 0;
}
