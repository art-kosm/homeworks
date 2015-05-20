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

    /**
     * @brief A simple static hash function
     *
     * Multiplies current value by base 8191, adds the next symbol value
     * and takes modulo.
     *
     * @param value
     * @param modulo
     * @return unsigned int hash
     */

    static unsigned int hashSimple(const QString &value, int modulo);

    /**
     * @brief RS static hash function
     *
     * A simple hash function from Robert Sedgwicks Algorithms in C book.
     * Multiplies current value by base 63689, adds the next symbol value,
     * takes modulo and then multiplies base by 378551.
     *
     * @param value
     * @param modulo
     * @return unsigned int hash
     */

    static unsigned int hashRS(const QString &value, int modulo);

    /**
     * @brief LY static hash function
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

    static unsigned int hashLY(const QString &value, int modulo);

    Hashtable *hashtable;
};
