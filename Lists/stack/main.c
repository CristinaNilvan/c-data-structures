#include "stack.h"

void testsPush(Node ** stack)
{
    push(stack, 3);
    printList(*stack);

    push(stack, 4);
    printList(*stack);

    push(stack, 7);
    printList(*stack);
}

void testsPop(Node ** stack)
{
    pop(stack);
    printList(*stack);
}

int main()
{
    Node * stack;

    initializeList(&stack);

    testsPush(&stack);
    testsPop(&stack);

    return 0;
}
