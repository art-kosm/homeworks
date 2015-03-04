#include "lexer.h"

enum State
{
    initial,
    startedWithDigit,
    startedWithDot,
    afterDot,
    afterExp,
    afterExpSign,
    afterExpDigit,
    finish,
    fail
};


bool isDigit(char character)
{
    return character >= '0' && character <= '9';
}

State move(State state, char c)
{
    switch (state)
    {
        case initial:
            if (c == ' ' || c == '\t')
                return initial;
            else if (isDigit(c))
                return startedWithDigit;
            else if (c == '.')
                return startedWithDot;
            else
                return fail;

        case startedWithDigit:
            if (isDigit(c))
                return startedWithDigit;
            else if (c == '.')
                return afterDot;
            else if (c == 'e' || c == 'E')
                return afterExp;
            else
                return finish;

        case startedWithDot:
            if (isDigit(c))
                return afterDot;
            else
                return fail;

        case afterDot:
            if (isDigit(c))
                return afterDot;
            else if (c == 'e' || c == 'E')
                return afterExp;
            else
                return finish;

        case afterExp:
            if (c == '+' || c == '-')
                return afterExpSign;
            else if (isDigit(c))
                return afterExpDigit;
            else
                return fail;

        case afterExpSign:
            if (isDigit(c))
                return afterExpDigit;
            else
                return fail;

        case afterExpDigit:
            if (isDigit(c))
                return afterExpDigit;
            else
                return finish;

        default:
            return fail;
    }
}

bool parseNumber(char *expression, int &position)
{
    position--;
    State state = initial;
    char c = expression[position];
    bool finished = false;
    while (state != finish && state != fail)
    {
        state = move(state, c);
        position++;
        c = expression[position];
        if (state == finish)
            finished = true;
    }
    position--;

    return finished;
}
