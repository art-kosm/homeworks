#include <iostream>

using namespace std;

int main()
{
    int base = 0;
    cout << "Enter the base: ";
    cin >> base;

    int power = 0;
    cout << "Enter the power: ";
    cin >> power;

    int binaryPower[65536];
    int length = 0;
    for (; power > 0; length++) {
        binaryPower[length] = power % 2;
        power /= 2;
    }

    int result = base;
    for (int i = 1; i < length; i++) {
        result *= result;
        if (binaryPower[length - i - 1] == 1)
            result *= base;
    }

    cout << "Result is " << result;

    return 0;
}

