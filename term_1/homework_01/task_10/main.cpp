#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    const int size = 256;
    char string[size];
    cout << "Enter your string: ";
    cin >> string;

    int stringLength = strlen(string);

    bool isPalindrome = true;
    for (int i = 0; i < stringLength / 2; i++) {
        if (string[i] != string[stringLength - i - 1]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
        cout << "It is a palindrome.";
    else
        cout << "It is not a palindrome.";

    return 0;
}

