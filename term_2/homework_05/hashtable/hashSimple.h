#pragma once

#include "hashFunction.h"

class HashSimple : public HashFunction
{
public:

    /**
     * @brief A simple hash function
     *
     * Multiplies current value by base 8191, adds the next symbol value
     * and takes modulo.
     *
     * @param value
     * @param modulo
     * @return unsigned int hash
     */

    unsigned int calculateHash(const QString &value, int modulo) const;
};
