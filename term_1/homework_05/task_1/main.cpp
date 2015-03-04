#include <iostream>
#include <fstream>

using namespace std;

bool contains(char array[], char value)
{
    bool contains = false;

    for (int i = 0; array[i] != '\0'; i++)
        if (array[i] == value)
        {
            contains = true;
            break;
        }

    return contains;
}

void fixAndShowResult(int sizeOfString, int realSize, char strings[][512])
{
    for (int i = 0; i < realSize; i++)
    {
        char word[sizeOfString];
        for (int j = 0; j < sizeOfString; j++)
            word[j] = '\0';
        int end = 0;
        for (int j = 0; j == 0 || strings[i][j - 1] != '\0'; j++)
        {
            if (strings[i][j] == ' ' || strings[i][j] == '\0')
            {
                for (int k = 0; k < end; k++)
                {
                    cout << word[k];
                    word[k] = '\0';
                }
                cout << ' ';
                end = 0;
            }
            else if (!contains(word, strings[i][j]))
            {
                word[end] = strings[i][j];
                end++;
            }
        }
        cout << "\n";
    }
}

int main()
{
    const int maxNumberOfStrings = 16;
    const int maxLength = 512;
    char strings[maxNumberOfStrings][maxLength];

    char path[maxLength];
    cout << "Enter the file path: ";
    cin.getline(path, maxLength);
    ifstream in(path);

    if (in == nullptr)
    {
        cout << "No such file found.";
        return 0;
    }

    int numberOfStrings = 0;

    while (!in.eof())
    {
        in.getline(strings[numberOfStrings], maxLength);
        numberOfStrings++;
    }

    in.close();

    fixAndShowResult(maxLength, numberOfStrings, strings);

    return 0;
}
