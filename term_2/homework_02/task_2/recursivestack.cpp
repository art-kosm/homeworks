#include <cstdio>
#include "stack.h"
#include "recursiveStack.h"

RecursiveStack::RecursiveStack()
{
    value = 0;
    stack = nullptr;
}

RecursiveStack::~RecursiveStack()
{
    if (!isEmpty())
        delete stack;
}

void RecursiveStack::push(int value)
{
    RecursiveStack *newStack = new RecursiveStack();
    newStack->value = this->value;
    newStack->stack = stack;
    this->value = value;

    stack = newStack;
}

char RecursiveStack::pop()
{
    int result = value;

    if (!isEmpty())
    {
        value = stack->value;

        RecursiveStack *newStack = stack->stack;    //saving the pointer to the stack
        stack->stack = nullptr;                     //clearing the pointer (we don't want the stack die D:)
        delete stack;
        stack = newStack;                           //changing the general pointer
    }

    return result;
}

char RecursiveStack::peek() const
{
    return value;
}

void RecursiveStack::print() const
{
    if (!isEmpty())
    {
        printf("%c\n", value);
        stack->print();
    }
}

bool RecursiveStack::isEmpty() const
{
    return stack == nullptr;
}
