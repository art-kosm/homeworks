#include <cstdio>
#include "stack.h"
#include "linkedliststack.h"
#include "recursivestack.h"
#include "calculator.h"

int main()
{
    Stack *list = new LinkedListStack();
    list->push('a');
    list->push('b');
    list->push('c');
    printf("Popping element: %c\n", list->pop());
    printf("Peek element: %c\n", list->peek());
    list->print();
    printf("Empty? %s", list->isEmpty() ? "true\n" : "false\n");

    delete list;

    Stack *stack = new RecursiveStack();
    stack->push('a');
    stack->push('b');
    stack->push('c');
    printf("Popping element: %c\n", stack->pop());
    printf("Peek element: %c\n", stack->peek());
    printf("Stack contents:\n");
    stack->print();
    printf("Empty? %s", stack->isEmpty() ? "true\n" : "false\n");

    delete stack;

    printf("\nEnter an expression: ");
    char *expression = getStringFromStandardInput();
    calculateExpression(expression);

    delete [] expression;

    return 0;
}
