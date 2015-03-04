#include "transformToPostfix.h"
#include "stack.h"
#include "linkedliststack.h"

void addToString(char *string, int position, char value)
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

char *transformToPostfix(char *input)
{
    Stack *stack = new LinkedListStack();
    int size = 0;
    while (input[size] != '\0')
        size++;

    char *output = new char[50 * size];  //for empty spaces

    int counter = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isOperator(input[i]))
        {
            if (!(stack->isEmpty()))
            {
                char token = stack->peek();
                while (!(stack->isEmpty()) && isOperator(token) && getPriority(token) >= getPriority(input[i]))
                {
                    addToString(output, counter, stack->pop());
                    counter += 2;
                    if (!(stack->isEmpty()))
                        token = stack->peek();
                }
            }
            stack->push(input[i]);
        }

        else if (input[i] == '(')
            stack->push(input[i]);

        else if (input[i] == ')')
        {
            while (stack->peek() != '(')
            {
                addToString(output, counter, stack->pop());
                counter += 2;
            }
            stack->pop();
        }

        else if (input[i] == ' ')
            continue;

        else
        {
            addToString(output, counter, input[i]);
            counter += 2;
        }
    }

    while (!(stack->isEmpty()))
    {
        addToString(output, counter, stack->pop());
        counter += 2;
    }

    output[counter] = '\0';

    delete stack;

    return output;
}
