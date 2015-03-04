#include <iostream>

using namespace std;

int fibIterative(int n) {
    int result = 1;
    int prev = 1;
    int prevprev = 1;

    for (int i = 2; i < n; i++) {
        result = prev + prevprev;
        prevprev = prev;
        prev = result;
    }

    return result;
}

int fibRecursive(int n) {
    if (n == 1 || n == 2)
        return 1;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int main()
{
    int n = 0;
    cout << "Enter your number: ";
    cin >> n;

    cout << "Iterative result is " << fibIterative(n) << '\n';
    cout << "Recursive result is " << fibRecursive(n);

    return 0;
}

