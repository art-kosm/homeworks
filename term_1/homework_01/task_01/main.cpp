#include <iostream>

using namespace std;

int main()
{
    int x = 0;
    cout << "Enter x: ";
    cin >> x;

    int y = x * x;

    int result = (y + x) * (y + 1) + 1;
    cout << "Result is " << result;

    return 0;
}
