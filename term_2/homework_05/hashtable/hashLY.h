#pragma once

#include "hashFunction.h"

class HashLY : public HashFunction
{
public:

    /**
     * @brief LY hash function
     *
     * Congruential generator proposed by Leonid Yuriev. Multiplier constant
     * suggested by M.Lavaux & F.Janssens.
     * Multiplies current value by base 1664525, adds the next symbol value,
     * adds 1013904223 and takes modulo.
     *
     * @param value
     * @param modulo
     * @return unsigned int hash
     */

    unsigned int calculateHash(const QString &value, int modulo) const;
};
