#include <iostream>

using namespace std;

bool bracketsAreCorrect(char string[])
{
    int balance = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '(')
            balance++;
        else if (string[i] == ')')
            balance--;
        if (balance < 0)
            break;
    }

    if (balance != 0)
        return false;
    return true;
}

int main()
{
    cout << "Enter your string! \n";
    char string[1024];
    cin >> string;

    if (bracketsAreCorrect(string))
        cout << "SUCCESS";
    else
        cout << "ERROR";

    return 0;
}

