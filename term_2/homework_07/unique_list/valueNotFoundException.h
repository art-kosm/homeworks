#pragma once

#include <QString>

class ValueNotFoundException
{
public:
    ValueNotFoundException(const QString &msg = "") : mData(msg) {}
    QString data() const
    {
        return mData;
    }

private:
    QString mData;
};
