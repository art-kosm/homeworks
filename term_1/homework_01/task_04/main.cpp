#include <iostream>

using namespace std;

int main()
{
    const int numberOfSums = 28;
    int sums[numberOfSums];
    for (int i = 0; i < numberOfSums; i++)
        sums[i] = 0;

    for (int i = 0; i < 1000; i++) {
        int sum = i % 10 + i / 100 + i / 10 % 10;
        sums[sum]++;
    }

    int result = 0;
    for (int i = 0; i < numberOfSums; i++)
        result += sums[i] * sums[i];

    cout << "Result is " << result << "\n";

    return 0;
}

