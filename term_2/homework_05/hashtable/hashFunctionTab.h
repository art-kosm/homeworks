#pragma once

#include <QWidget>
#include "hashtable.h"

class HashFunctionTab : public QWidget
{
    Q_OBJECT

public:
    explicit HashFunctionTab(Hashtable *hashtable, QWidget *parent = 0);

signals:

    /**
     * @brief hashFunctionSet signal
     *
     * Emits every time after some hash function is set
     */

    void hashFunctionSet() const;

private slots:

    /**
     * @brief hashSimpleToggled slot
     *
     * Sets a simple hash function
     */

    void hashSimpleToggled();

    /**
     * @brief hashRSToggled slot
     *
     * Sets RS hash function
     */

    void hashRSToggled();

    /**
     * @brief hashLYToggled slot
     *
     * Sets LY hash function
     */

    void hashLYToggled();

private:
    Hashtable *hashtable;
};
