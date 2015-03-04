#include <stdio.h>

using namespace std;

int main()
{
    double value = 0;
    printf("Enter the number: ");
    scanf("%lf", &value);

    char *bytes = (char*) &value;
    int bits[sizeof(double) * 8];
    int counter = 0;
    for (int i = 7; i >= 0; i--)
    {
        int bit = 0b10000000;
        for (int j = 0; j < 8; j++)
        {
            bits[counter] = (bytes[i] & bit) ? 1 : 0;
            counter++;
            bit = bit >> 1;
        }
    }
    printf((bits[0] == 0) ? "+" : "-");    

    double mantissa = 1;
    double power = 0.5;
    for (int i = 12; i < 64; i++)
    {
        mantissa += bits[i] * power;
        power /= 2;
    }
    printf("%.52g", mantissa);

    int exponent = -1023;
    power = 1;
    for (int i = 11; i > 0; i--)
    {
        exponent += bits[i] * power;
        power *= 2;
    }
    printf("*2^(%d)", exponent);

    return 0;
}

