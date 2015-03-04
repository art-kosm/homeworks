#include "computePostfix.h"
#include "stack.h"
#include "linkedliststack.h"

double convertToNumber(char character)
{
    int difference = '0';
    return (double) character - difference;
}

double computePostfix(char *input)
{
    Stack *stack = new LinkedListStack();

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '+')
            stack->push(stack->pop() + stack->pop());
        else if (input[i] == '-')
        {
            int sub = stack->pop();
            int min = stack->pop();
            stack->push(min - sub);
        }
        else if (input[i] == '*')
            stack->push(stack->pop() * stack->pop());
        else if (input[i] == '/')
        {
            int down = stack->pop();
            int up = stack->pop();
            stack->push(up / down);
        }
        else if (input[i] == ' ')
            continue;
        else
            stack->push(convertToNumber(input[i]));
    }

    int result = stack->pop();

    delete stack;

    return result;
}
