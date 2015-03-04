#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    cout << "Enter 2 strings! \n";
    const int size = 255;
    char s[size];
    cin >> s;
    char s1[size];
    cin >> s1;

    int sLength = strlen(s);
    int s1Length = strlen(s1);

    int result = 0;

    for (int i = 0; i < sLength - s1Length + 1; i++) {
        bool isSubstring = true;
        for (int j = 0; j < s1Length; j++)
            if (s[i + j] != s1[j]) {
                isSubstring = false;
                break;
            }
        if (isSubstring)
            result++;
    }

    cout << "Result is " << result;

    return 0;
}

