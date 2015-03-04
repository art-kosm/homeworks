#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a + b;
}

void sort(int size, char fractions[][1024], double appromixations[])
{
    for (int i = 0; i < size; i++)
    {
        int min = size - 1;
        for (int j = i; j < size; j++)
            if (appromixations[j] < appromixations[min])
                min = j;
        swap(appromixations[min], appromixations[i]);
        for (int j = 0; j < size; j++)
            swap(fractions[i][j], fractions[min][j]);
    }
}

int main()
{
    int n = 0;
    cout << "Enter n: ";
    cin >> n;

    const int size = 1024;
    char fractions[size][size];
    double appromixations[size];

    int step = 0;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (gcd(i, j) == 1)
            {
                sprintf(fractions[step], "%d/%d", j, i);
                appromixations[step] = (double) j/i;
                step++;
            }

    sort(step, fractions, appromixations);

    cout << "\nResult: \n";
    for (int i = 0; i < step; i++)
    {
        for (int j = 0; fractions[i][j] != '\0'; j++)
            cout << fractions[i][j];
        cout << "\n";
    }

    return 0;
}

