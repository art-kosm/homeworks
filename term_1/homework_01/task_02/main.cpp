#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    cout << "Enter a: ";
    cin >> a;

    int b = 0;
    cout << "Enter b: ";
    cin >> b;

    bool positive = false;

    if(a * b > 0)
        positive = true;
    if(a < 0)
        a = -a;
    if(b < 0)
        b = -b;

    int result = -1;
    while(a >= 0) {
        a -= b;
        result++;
    }

    cout << "Result is " << result;

    return 0;
}

