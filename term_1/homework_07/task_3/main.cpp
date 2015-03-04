#include <iostream>
#include <fstream>
#include "string.h"
#include "linkedList.h"
#include "hashtable.h"

using namespace std;

char *extend(char *&array, int length, int maxLength)
{
    char *newArray = new char[maxLength];
    for (int i = 0; i < length; i++)
        newArray[i] = array[i];
    delete [] array;

    return newArray;
}

char *getStringFromStandartInput()
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

String **getTextFromInputFile(int &wordsNumber)
{
    char *path = getStringFromStandartInput();
    ifstream in(path);
    delete [] path;
    if (in == nullptr)
        return nullptr;

    int currentCharacters = 0;
    int maxWordLength = 0;
    while (!in.eof())
    {
        char c = '\0';
        in >> noskipws >> c;
        if (c != ' ' && c != '\n')
            currentCharacters++;
        else
        {
            if (currentCharacters > maxWordLength)
                maxWordLength = currentCharacters;
            currentCharacters = 0;
            wordsNumber++;
        }
    }
    wordsNumber++;
    in.clear();
    in.seekg(0, ios::beg);

    String **text = new String*[wordsNumber];
    char word[maxWordLength + 1];
    int currentCharacter = 0;
    int currentWord = 0;
    while (!in.eof())
    {
        char c = '\0';
        in >> noskipws >> c;
        if (c != ' ' && c != '\n')
        {
            word[currentCharacter] = c;
            currentCharacter++;
        }
        else
        {
            word[currentCharacter] = '\0';
            currentCharacter = 0;
            text[currentWord] = createString(word);
            currentWord++;
        }
    }
    word[currentCharacter] = '\0';
    text[currentWord] = createString(word);

    return text;
}

int main()
{
    int wordsNumber = 0;
    cout << "Enter the file path: ";
    String **text = getTextFromInputFile(wordsNumber);
    if (text == nullptr)
    {
        cout << "No file found\n";
        return 0;
    }

    Hashtable *hashtable = createHashtable();
    for (int i = 0; i < wordsNumber; i++)
    {
        addValue(hashtable, text[i]);
        if (loadFactor(hashtable) > 1)
        {
            Hashtable *newHashtable = extendHashtable(hashtable);
            deleteHashtable(hashtable);
            hashtable = newHashtable;
        }
    }
    printHashtableWithTimes(hashtable);
    cout << "\nload factor: " << loadFactor(hashtable) << "\n";
    cout << "average list length: " << averageListLength(hashtable) << "\n";
    cout << "max list length: " << maxListLength(hashtable) << ", values:\n";
    printMaxListLengthValues(hashtable);
    cout << "\ntotal word number: " << getElementsNumber(hashtable) << "\n";
    cout << "empty positions: " << emptyPositions(hashtable) << "\n";

    for (int i = 0; i < wordsNumber; i++)
        deleteString(text[i]);
    delete [] text;
    deleteHashtable(hashtable);

    return 0;
}
