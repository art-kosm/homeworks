#include "stack.h"

struct StackElement
{
    int startValue;
    int endValue;
    int distance;
    StackElement *next;
};

struct Stack
{
    StackElement *top;
};

StackElement *createStackElement(int startValue,  int endValue, int distance, StackElement *next)
{
    StackElement *newStackElement = new StackElement;
    newStackElement->next = next;
    newStackElement->startValue = startValue;
    newStackElement->endValue = endValue;
    newStackElement->distance = distance;

    return newStackElement;
}


Stack *createStack()
{
    Stack *newStack = new Stack;
    newStack->top = createStackElement(0, 0, 0, nullptr);

    return newStack;
}


void push(Stack *stack, int startValue, int endValue, int distance)
{
    StackElement *newElement = createStackElement(startValue, endValue, distance, stack->top->next);
    stack->top->next = newElement;
}


void pop(Stack *stack)
{
    StackElement *element = stack->top->next;
    stack->top->next = stack->top->next->next;

    delete element;
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

int getTopStartValue(Stack *stack)
{
    return stack->top->next->startValue;
}

int getTopEndValue(Stack *stack)
{
    return stack->top->next->endValue;
}

int getTopDistance(Stack *stack)
{
    return stack->top->next->distance;
}
