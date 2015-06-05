#pragma once

#include <QString>

class HashFunction
{
public:
    virtual ~HashFunction() {}
    virtual unsigned int calculateHash(const QString &value, int modulo) const = 0;
};
