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
        switch (input[i])
        {
            case '+':
                stack->push(stack->pop() + stack->pop());
                break;

            case '-':
            {
                int sub = stack->pop();
                int min = stack->pop();
                stack->push(min - sub);
            } break;

            case '*':
                stack->push(stack->pop() * stack->pop());
                break;

            case '/':
            {
                int down = stack->pop();
                int up = stack->pop();
                stack->push(up / down);
            } break;

            case ' ':
                continue;

            default:
                stack->push(convertToNumber(input[i]));
                break;
        }
    }

    int result = stack->pop();

    delete stack;

    return result;
}