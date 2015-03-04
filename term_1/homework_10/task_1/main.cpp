#include <iostream>

using namespace std;

enum State
{
    initial,
    negative,
    startedWithDigit,
    startedWithDot,
    afterDot,
    afterExp,
    afterExpSign,
    afterExpDigit,
    finish,
    fail
};

char *extend(char *&array, int length, int maxLength)
{
    char *newArray = new char[maxLength];
    for (int i = 0; i < length; i++)
        newArray[i] = array[i];
    delete [] array;

    return newArray;
}

char *getStringFromStandardInput()
{
    int size = 10;
    int length = 0;
    char *string = new char[size];
    while (true)
    {
        scanf("%c", &string[length]);
        length++;
        if (string[length - 1] == '\n')
        {
            string[length - 1] = '\0';
            break;
        }
        if (length == size)
        {
            size = size * 3 / 2 + 1;
            string = extend(string, length, size);
        }
    }

    return string;
}

bool isDigit(char character)
{
    return character >= '0' && character <= '9';
}

State move(State state, char c)
{
    switch (state)
    {
        case initial:
            if (isDigit(c))
                return startedWithDigit;
            else if (c == '.')
                return startedWithDot;
            else if (c == '-')
                return negative;
            else
                return fail;

        case negative:
            if (isDigit(c))
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
            else if (c == '\0')
                return finish;
            else
                return fail;

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
            else if (c == '\0')
                return finish;
            else
                return fail;

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
            else if (c == '\0')
                return finish;
            else
                return fail;

        default:
            return fail;
    }
}

int main()
{
    cout << "Enter a number: ";
    char *number = getStringFromStandardInput();

    State state = initial;
    int position = 0;
    char c = number[position];
    while (c != '\0')
    {
        state = move(state, c);
        position++;
        c = number[position];
    }

    state = move(state, c);

    if (state == finish)
        cout << "This is a number\n";
    else
        cout << "This is not a number\n";

    delete [] number;

    return 0;
}

