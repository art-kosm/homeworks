#include "computePostfix.h"
#include "stack.h"

double convertToNumber(char character)
{
    int difference = '1' - 1;
    return (double) character - difference;
}

double computePostfix(char input[])
{
    Stack *stack = createStack();

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '+')
            push(stack, pop(stack) + pop(stack));
        else if (input[i] == '-')
            push(stack, -(pop(stack) - pop(stack)));
        else if (input[i] == '*')
            push(stack, pop(stack) * pop(stack));
        else if (input[i] == '/')
            push(stack, 1/(pop(stack) / pop(stack)));
        else if (input[i] == ' ')
            continue;
        else
            push(stack, convertToNumber(input[i]));
    }

    double result = pop(stack);
    deleteStack(stack);

    return result;
}
