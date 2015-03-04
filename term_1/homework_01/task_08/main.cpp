#include <iostream>

using namespace std;

int facIterative(int n) {
    int result = 1;
    while (n > 0) {
        result *= n;
        n--;
    }
    return result;
}

int facRecursive(int n) {
    if (n > 1)
        return n * facRecursive(n - 1);
    else
        return 1;
}

int main()
{
    int n = 0;
    cout << "Enter your number plis " << '\n';
    cin >> n;

    cout << "Iterative result is " << facIterative(n) << '\n';
    cout << "Recursive result is " << facRecursive(n) << '\n';

    return 0;
}
