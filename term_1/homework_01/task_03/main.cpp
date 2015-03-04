#include <iostream>

using namespace std;

void reverse(int array[], int left, int right) {
    for(int i = 0; i < (right - left) / 2; i++)
        swap(array[left + i], array[right - i - 1]);
    return;
}

int main()
{
    int m = 0;
    cout << "Enter m: ";
    cin >> m;

    int n = 0;
    cout << "Enter n: ";
    cin >> n;

    const int size = 65535;
    int array[size];
    cout << "Enter " << m + n << " numbers: \n";
    for(int i = 0; i < m + n; i++)
        cin >> array[i];

    reverse(array, 0, m);
    reverse(array, m, m + n);
    reverse(array, 0, m + n);

    cout << "Result: \n";
    for(int i = 0; i < m + n; i++)
        cout << array[i] << "\n";

    return 0;    
}
