#include "hashSimple.h"

unsigned int HashSimple::calculateHash(const QString &value, int modulo) const
{
    const unsigned int base = 8191 % modulo; //prime

    int last = value.length() - 1;
    unsigned int sum = value.at(last).toLatin1() % modulo;

    while (last > 0)
    {
        last--;
        sum = (base * sum + value.at(last).toLatin1()) % modulo;
    }

    return sum;
}
