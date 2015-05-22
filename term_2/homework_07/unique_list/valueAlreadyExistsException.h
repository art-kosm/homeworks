#pragma once

#include <QString>

class ValueAlreadyExistsException
{
public:
    ValueAlreadyExistsException(const QString &msg = "") : mData(msg) {}
    QString data() const
    {
        return mData;
    }

private:
    QString mData;
};
