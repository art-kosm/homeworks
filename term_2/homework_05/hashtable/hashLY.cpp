#include "hashLY.h"

unsigned int HashLY::calculateHash(const QString &value, int modulo)
{
    const unsigned int base = 1664525 % modulo; //not prime . . .
    const unsigned int summand = 1013904223 % modulo; //prime

    int last = value.length() - 1;
    unsigned int sum = value.at(last).toLatin1() % modulo;

    while (last > 0)
    {
        last--;
        sum = (base * sum + value.at(last).toLatin1() + summand) % modulo;
    }

    return sum;
}
