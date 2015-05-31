#pragma once

#include "hashFunction.h"

class HashRS : public HashFunction
{
public:

    /**
     * @brief RS hash function
     *
     * A simple hash function from Robert Sedgwicks Algorithms in C book.
     * Multiplies current value by base 63689, adds the next symbol value,
     * takes modulo and then multiplies base by 378551.
     *
     * @param value
     * @param modulo
     * @return unsigned int hash
     */

    unsigned int calculateHash(const QString &value, int modulo);
};
