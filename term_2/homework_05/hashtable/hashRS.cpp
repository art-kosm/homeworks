#include "hashRS.h"

unsigned int HashRS::calculateHash(const QString &value, int modulo)
{
    unsigned int base = 63689 % modulo; //prime
    const unsigned int multiplier = 378551 % modulo; //prime

    int last = value.length() - 1;
    unsigned int sum = value.at(last).toLatin1() % modulo;

    while (last > 0)
    {
        last--;
        sum = (base * sum + value.at(last).toLatin1()) % modulo;
        base *= multiplier % modulo;
    }

    return sum;
}
