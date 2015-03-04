#include "string.h"

struct String
{
    char *array;
};

String *createString()
{
    char string[] = "\0";

    return createString(string);
}

String *createString(char str[])
{
    int stringLength = 0;
    while (str[stringLength] != '\0')
        stringLength++;
    stringLength++;
    char *array = new char[stringLength];
    for (int i = 0; i < stringLength; i++)
        array[i] = str[i];
    String *string = new String;
    string->array = array;

    return string;
}

String *clone(String *string)
{
    return createString(string->array);
}

String *concatenate(String *string1, String *string2)
{
    int length1 = length(string1);
    int length2 = length(string2);
    char *string = new char[length1 + length2 - 1];
    for (int i = 0; i < length1 - 1; i++)
        string[i] = string1->array[i];
    for (int i = 0; i < length2; i++)
        string[i + length1 - 1] = string2->array[i];

    return createString(string);
}

bool equals(String *string1, String *string2)
{
    int length1 = length(string1);
    int length2 = length(string2);
    if (length1 != length2)
        return false;

    for (int i = 0; i < length1; i++)
        if (string1->array[i] != string2->array[i])
            return false;

    return true;
}

bool isEmpty(String *string)
{
    return length(string) == 1;
}

String *substring(String *string, int start, int end)
{
    int newLength = end - start + 2;
    char *newString = new char[newLength];
    for (int i = 0; i < newLength - 1; i++)
        newString[i] = string->array[i + start];
    newString[newLength - 1] = '\0';

    return createString(newString);
}

char *toCharArray(String *string)
{
    int stringLength = length(string);
    char *array = new char[stringLength];
    for (int i = 0; i < stringLength; i++)
        array[i] = string->array[i];

    return array;
}

int length(String *string)
{
    int stringLength = 0;
    while (string->array[stringLength] != '\0')
        stringLength++;
    stringLength++;

    return stringLength;
}

void deleteString(String *string)
{
    delete [] string->array;
    delete string;
}
