#include "stack.h"

struct StackElement
{
    double value;
    StackElement *next;
};

struct Stack
{
    StackElement *top;
};

StackElement *createStackElement(double value, StackElement *next)
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


void push(Stack *stack, double value)
{
    StackElement *newElement = createStackElement(value, stack->top->next);
    stack->top->next = newElement;
}


double pop(Stack *stack)
{
    double result = stack->top->next->value;
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
