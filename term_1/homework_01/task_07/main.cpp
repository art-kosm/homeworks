#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cout << "Enter your number!" << '\n';
    cin >> n;

    const int size = 262144;

    int prime[size];

    for (int i = 0; i < size; i++)
        prime[i] = i;

    for (int i = 2; i < size; i++)                  //решето Эратосфена
        if (prime[i] != 0)
            for (int j = i * 2; j < size; j += i)
                prime[j] = 0;

    for (int i = 2; i <= n; i++)
        if (prime[i] != 0)
            cout << prime[i] << '\n';

    return 0;
}
