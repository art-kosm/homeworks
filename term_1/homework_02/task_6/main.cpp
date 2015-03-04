#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getSecretNumber()
{
    int numberOfDigits = 10;
    int digits[numberOfDigits];
    for (int i = 0; i < numberOfDigits; i++)
        digits[i] = i;
    int secretNumber = 0;
    int maxNumber = 10000;

    for (int k = 1; k < maxNumber; k *= 10)
    {
        int digit = 0;
        if (k != maxNumber / 10)
            digit = rand() % numberOfDigits;
        else
            digit = rand() % (numberOfDigits - 1) + 1;
        secretNumber += k * digits[digit];
        for (int i = digit; i < numberOfDigits - 1; i++)
            digits[i] = digits[i + 1];
        numberOfDigits--;
    }

    return secretNumber;
}

bool checkGuess(int guess, int secretNumber)
{
    if (guess != secretNumber)
    {
        int numberOfDigits = 4;
        int guessDigits[numberOfDigits];
        for (int i = 0; i < numberOfDigits; i++)
        {
            guessDigits[i] = guess % 10;
            guess /= 10;
        }
        int secretDigits[numberOfDigits];
        for (int i = 0; i < numberOfDigits; i++)
        {
            secretDigits[i] = secretNumber % 10;
            secretNumber /= 10;
        }

        int bulls = 0;
        for (int i = 0; i < numberOfDigits; i++)
            if (guessDigits[i] == secretDigits[i])
                bulls++;
        cout << "Number of bulls: " << bulls << "\n";

        int cows = 0;
        for (int i = 0; i < numberOfDigits; i++)
            for (int j = 0; j < numberOfDigits; j++)
                if (guessDigits[j] == secretDigits[i] && i != j)
                    cows++;
        cout << "Number of cows: " << cows << "\n";
    }
    else
        return true;

    return false;
}

int main()
{
    srand(time(0));
    cout << "Hi! \n";
    int secretNumber = getSecretNumber();
    while (true)
    {
        int guess = 0;
        cout << "\nGuess the number: ";
        cin >> guess;
        bool isWin = checkGuess(guess, secretNumber);
        if (isWin)
        {
            cout << "\nYe win!";
            break;
        }
    }

    return 0;
}
