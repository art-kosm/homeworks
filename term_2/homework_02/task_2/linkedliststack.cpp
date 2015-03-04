#include <cstdio>
#include "stack.h"
#include "linkedliststack.h"

struct LinkedListStack::StackElement
{
    int value;
    StackElement *next;
};

LinkedListStack::LinkedListStack()
{
    top = createStackElement(0, nullptr);
}

LinkedListStack::~LinkedListStack()
{
    while (!isEmpty())
        pop();

    delete top;
}

LinkedListStack::StackElement *LinkedListStack::createStackElement(int value, StackElement *next)
{
    StackElement *newStackElement = new StackElement;
    newStackElement->next = next;
    newStackElement->value = value;

    return newStackElement;
}

void LinkedListStack::push(int value)
{
    top->next = createStackElement(value, top->next);
}

char LinkedListStack::pop()
{
    if (!isEmpty())
    {
        int result = top->next->value;
        StackElement *element = top->next;
        top->next = top->next->next;
        delete element;

        return result;
    }

    return '\0';
}

char LinkedListStack::peek()
{
    if (!isEmpty())
        return top->next->value;

    return '\0';
}

void LinkedListStack::print()
{
    StackElement *current = top->next;

    while (current != nullptr)
    {
        printf("%c\n", current->value);
        current = current->next;
    }
}

bool LinkedListStack::isEmpty()
{
    return top->next == nullptr;
}
