#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    const int size = 20;
    int array[size];
    for (int i = 0; i < size; i++)
        array[i] = rand() % 20 - 18;
    cout << "Array:\n";
    for (int i = 0; i < size; i++)
        cout << array[i] << "\n";

    int minimum = array[0];
    for (int i = 0; i < size; i++)
        if (array[i] < minimum)
            minimum = array[i];
    if (minimum < 0)
        for (int i = 0; i < size; i++)
            array[i] -= minimum;
    else
        minimum = 0;

    int numbers[size - minimum];
    for (int i = 0; i < size - minimum; i++)
        numbers[i] = 0;
    for (int i = 0; i < size; i++)
        numbers[array[i] - 1]++;
    int result = 0;
    for (int i = size - minimum - 1; i >= 0; i--)
        if (numbers[i] > 1)
        {
            result = i + 1;
            break;
        }

    result += minimum;

    cout << "Result is " << result << "\n";

    return 0;
}

