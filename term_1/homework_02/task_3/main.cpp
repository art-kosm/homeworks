#include <iostream>

using namespace std;

int sum(int array[], int last) {
    int result = 0;
    for (int i = 0; i < last; i++)
        result += array[i];
    return result;
}

void getAllRepresentations(int n) {
    int summands[n];
    for (int i = 0; i < n; i++) {
        summands[0] = i + 1;
        for (int j = 1; j < n - i; j++) {
            summands[j] = 1;
        }
        int step = 0;
        while (sum(summands, n - i - step) == n) {
            for (int j = 0; j < n - i - step; j++)
                cout << summands[j] << " ";
            for (int j = 1; j < n - i - step; j++)
                if (summands[j] < summands[0]) {
                    summands[j]++;
                    break;
                }
            cout << "\n";
            step++;
        }
    }
}

int main()
{
    int n = 0;
    cout << "Enter N: ";
    cin >> n;

    cout << "Result: \n";
    getAllRepresentations(n);

    return 0;
}

