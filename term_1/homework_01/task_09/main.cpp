#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    cout << "Enter a: ";
    cin >> a;
    int n = 0;
    cout << "Enter n: ";
    cin >> n;

    int result = 1;

    for (int i = 0; i < n; i++)
        result *= a;

    cout << "a^n = " << result;

    return 0;
}

