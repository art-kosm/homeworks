#include <iostream>

using namespace std;

unsigned int getHash(char string[], int first, int last)
{
    const int primeBase = 8191;
    const int primeModulo = 9973;
    unsigned int sum = string[last];
    while (last > first)
    {        
        last--;
        sum = (primeBase * sum + string[last]) % primeModulo;
    }

    return sum;
}

unsigned int getNextHash(char string[], int first, int last, int hash)
{
    const int primeBase = 8191;
    const int baseReverse = 6755; // 6755 * 8191 = 1 (mod 9973)
    const int primeModulo = 9973;
    unsigned int power = 1;
    for (int i = 0; i < last - first; i++)
        power = (power * primeBase) % primeModulo;

    return ((hash - string[first]) * baseReverse + string[last + 1] * power) % primeModulo;
}

int getLength(char string[])
{
    int length = 0;
    while (string[length] != '\0')
        length++;

    return length;
}

bool match(char string[], char substring[], int position)
{
    bool match = false;
    for (int i = 0; substring[i] != '\0'; i++)
    {
        match = string[position + i] == substring[i];
        if (!match)
            break;
    }

    return match;
}

void findAndShowPositions(char string[], char substring[])
{
    int length = getLength(string);
    int subLength = getLength(substring);
    if (subLength > length)
    {
        cout << "Substring not found";
        return;
    }

    int *positions = new int[length - subLength + 1];
    int position = 0;
    int first = 0;
    int last = subLength - 1;
    int hash = getHash(string, first, last);
    int subHash = getHash(substring, first, last);
    while (last <= length)
    {
        if (first > 0)
            hash = getNextHash(string, first - 1, last - 1, hash);
        if (hash == subHash)
            if (match(string, substring, first))
            {
                positions[position] = first;
                position++;
            }
        first++;
        last++;
    }

    if (position == 0)
        cout << "Substring not found";
    else
    {
        cout << position << " matches found: ";
        for (int i = 0; i < position; i++)
        {
            cout << positions[i];
            if (i != position - 1)
                cout << ", ";
            else
                cout << "\n";
        }
    }

    delete [] positions;
}

int main()
{
    const int size = 65536;
    char str[size];
    cout << "Enter your string: ";
    cin.getline(str, size);
    char substr[size];
    cout << "Enter substring: ";
    cin.getline(substr, size);

    findAndShowPositions(str, substr);

    return 0;
}
