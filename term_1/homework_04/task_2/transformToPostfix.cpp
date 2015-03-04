#include "transformToPostfix.h"
#include "stack.h"

void addToString(char string[], int position, char value)
{
    string[position] = value;
    string[position + 1] = ' ';
}

bool isOperator(char token)
{
    return token == '+' || token == '-' || token == '*' || token == '/';
}

int getPriority(char token)
{
    if (token == '+' || token == '-')
        return 0;
    return 1;
}

void transformToPostfix(char input[], char output[])
{
    Stack *stack = createStack();

    int counter = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isOperator(input[i]))
        {
            if (!isEmpty(stack))
            {
                char token = getTopValue(stack);
                while (!isEmpty(stack) && isOperator(token) && getPriority(token) >= getPriority(input[i]))
                {
                    addToString(output, counter, pop(stack));
                    counter += 2;
                    if (!isEmpty(stack))
                        token = getTopValue(stack);
                }
            }
            push(stack, input[i]);
        }

        else if (input[i] == '(')
            push(stack, input[i]);

        else if (input[i] == ')')
        {
            while (getTopValue(stack) != '(')
            {
                addToString(output, counter, pop(stack));
                counter += 2;
            }
            pop(stack);
        }

        else if (input[i] == ' ')
            continue;

        else
        {
            addToString(output, counter, input[i]);
            counter += 2;
        }
    }

    while (!isEmpty(stack))
    {
        addToString(output, counter, pop(stack));
        counter += 2;
    }

    output[counter] = '\0';

    deleteStack(stack);
}
