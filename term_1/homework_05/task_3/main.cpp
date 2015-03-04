#include <iostream>
#include <fstream>

using namespace std;

void findAndShowComments(char file[], int realSize)
{
    bool insideSingleQuote = false;
    bool insideDoubleQuote = false;
    bool insideComment = false;

    for (int i = 0; i < realSize; i++)
    {
        if (file[i] == '\'' && file[i - 1] != '\\' && !insideComment && !insideDoubleQuote)
            insideSingleQuote = !insideSingleQuote;

        else if (file[i] == '\"' && !insideComment && !insideSingleQuote)
            insideDoubleQuote = !insideDoubleQuote;

        else if (file[i] == '/' && file[i + 1] == '*' && !insideDoubleQuote && !insideSingleQuote)
        {
            insideComment = true;
            i++;
        }

        else if (file[i] == '*' && file[i + 1] == '/')
            insideComment = false;

        else if (!insideComment && !insideDoubleQuote && !insideSingleQuote && file[i] == '/' && file[i + 1] == '/')
        {
            while (file[i] != '\n')
            {
                cout << file[i];
                i++;
            }
            cout << "\n";
        }
    }
}

int main()
{
    const int size = 65536;
    char file[size];

    char path[size];
    cout << "Enter the file path: ";
    cin.getline(path, size);
    ifstream in(path);

    if (in == nullptr)
        cout << "No such file found.";
    else
    {
        int realSize = 0;
        for (; !in.eof(); realSize++)
            file[realSize] = in.get();

        in.close();

        findAndShowComments(file, realSize);
    }

    return 0;
}

