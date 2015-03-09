#include <cstdio>
#include "stack.h"
#include "linkedliststack.h"
#include "recursivestack.h"
#include "calculator.h"

void linkedListStackTest()
{
    printf("Linked list stack:\n");
    Stack *list = new LinkedListStack();
    list->push('a');
    list->push('b');
    list->push('c');
    printf("Popping element: %c\n", list->pop());
    printf("Peek element: %c\n", list->peek());
    list->print();
    printf("Empty? %s", list->isEmpty() ? "true\n" : "false\n");

    delete list;
}

void recursiveStackTest()
{
    printf("\nRecursive stack:\n");
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
}

void useCalculator()
{
    printf("\nEnter an expression: ");
    Calculator *calculator = new Calculator();
    calculator->calculateExpression();

    delete calculator;
}

int main()
{
    linkedListStackTest();
    recursiveStackTest();

    useCalculator();

    return 0;
}
