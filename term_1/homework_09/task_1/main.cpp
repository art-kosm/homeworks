#include <iostream>
#include <fstream>

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

bool contains(char **text, char *string, int length)
{
    for (int i = 0; i < length; i++)
    {
        bool match = false;
        for (int j = 0; text[i][j] != '\0' || string[j] != '\0'; j++)
        {
            match = text[i][j] == string[j];
            if (!match)
                break;
        }
        if (match || (text[i][0] == '\0' && string[0] == '\0'))
            return true;
    }

    return false;
}

void delete2DArray(char **array, int size)
{
    for(int i = 0; i < size; i++)
        delete [] array[i];
    delete [] array;
}

char **getTextFromInputFile(int &stringsNumber, int &charactersNumber)
{
    char *path = getStringFromStandartInput();
    ifstream in(path);
    delete [] path;
    if (in == nullptr)
        return nullptr;

    int currentCharacters = 0;

    while (!in.eof())
    {
        char c = '\0';
        in >> noskipws >> c;
        if (c != '\n')
            currentCharacters++;
        else
        {
            if (currentCharacters > charactersNumber)
                charactersNumber = currentCharacters;
            currentCharacters = 0;
            stringsNumber++;
        }
    }
    stringsNumber++;
    in.clear();
    in.seekg(0, ios::beg);

    char **text = new char*[stringsNumber];
    for (int i = 0; i < stringsNumber; i++)
    {
        text[i] = new char[charactersNumber + 1]; // +1 from '\n'
        in.getline(text[i], charactersNumber + 1);
    }

    in.close();

    return text;
}

int main()
{
    int stringsNumber1 = 0;
    int charactersNumber1 = 0;
    cout << "Enter the first file path: ";
    char **text1 = getTextFromInputFile(stringsNumber1, charactersNumber1);
    if (text1 == nullptr)
    {
        cout << "No file found\n";
        return 0;
    }

    int stringsNumber2 = 0;
    int charactersNumber2 = 0;
    cout << "Enter the second file path: ";
    char **text2 = getTextFromInputFile(stringsNumber2, charactersNumber2);
    if (text2 == nullptr)
    {
        cout << "No file found\n";
        return 0;
    }

    cout << "Enter the output file path: ";
    char *path3 = getStringFromStandartInput();
    ofstream out(path3);

    for (int i = 0; i < stringsNumber1; i++)
        if (contains(text2, text1[i], stringsNumber2))
        {
            out << text1[i];
            if (i != stringsNumber1 - 1)
                out << "\n";
        }

    cout << "Selection completed\n";
    out.close();

    delete2DArray(text1, stringsNumber1);
    delete2DArray(text2, stringsNumber2);

    return 0;
}
