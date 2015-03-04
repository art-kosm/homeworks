#include "stack.h"

struct StackElement
{
    char value;
    StackElement *next;
};

struct Stack
{
    StackElement *top;
};

StackElement *createStackElement(int value, StackElement *next)
{
    StackElement *newStackElement = new StackElement;
    newStackElement->next = next;
    newStackElement->value = value;
    return newStackElement;
}


Stack *createStack()
{
    Stack *newStack = new Stack;
    newStack->top = createStackElement(0, nullptr);
    return newStack;
}


void push(Stack *stack, char value)
{
    StackElement *newElement = createStackElement(value, stack->top->next);
    stack->top->next = newElement;
}


char pop(Stack *stack)
{
    char result = stack->top->next->value;
    StackElement *element = stack->top->next;
    stack->top->next = stack->top->next->next;
    delete element;
    return result;
}

bool isEmpty(Stack *stack)
{
    return stack->top->next == nullptr;
}

void deleteStack(Stack *stack)
{
    while (!isEmpty(stack))
        pop(stack);
    delete stack->top;
    delete stack;
}

char getTopValue(Stack *stack)
{
    return stack->top->next->value;
}
