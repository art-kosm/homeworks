#pragma once

#include "linkedList.h"
#include "hashFunction.h"

class Hashtable
{
public:

    /**
     * @brief Hashtable construcor
     *
     * Sets default values and hash function and creates lists array
     */

    Hashtable();

    ~Hashtable();

    /**
     * @brief Value adder
     *
     * Gets the hash of the value and adds it to the list which index is
     * the hash got. Does not add anything if the value is already presented,
     * adds the value and increases elementsNumber otherwise.
     * If the load factor of the table happens to exceed 1, extends the
     * hashtable.
     *
     * @param value
     */

    void add(const QString &value);

    /**
     * @brief Value remover
     *
     * Gets the hash of the value and removes it from the list which index is
     * the hash got. Does not add anything if the value has not been
     * presented, removes the value and decreases elementsNumber otherwise.
     *
     * @param value
     */

    void remove(const QString &value);

    /**
     * @brief Value inclusion in the hashtable checker
     *
     * @param value
     * @return "true" if the hashtable contains the value,
     *         "false" otherwise
     */

    bool contains(const QString &value) const;

    /**
     * @brief Elements number getter
     *
     * @return int elementsNumber
     */

    int getElementsNumber() const;

    /**
     * @brief Load factor getter
     *
     * @return double elementsNumber / size
     */

    double loadFactor() const;

    /**
     * @brief Conflicts counter
     *
     * @return Number of lists which length exceeds 1
     */

    int conflicts() const;

    /**
     * @brief Longest list length getter
     *
     * @return Length of the longest list presented in the hashtable
     */

    int maxListLength() const;

    /**
     * @brief Hash function setter
     *
     * Sets new hash function and rebuilds the table
     *
     * @param hashFunction
     */

    void setHashFunction(HashFunction *hashFunction);

private:
    int size;
    int elementsNumber;
    LinkedList **list;
    HashFunction *hashFunction;

    /**
     * @brief Hashtable rebuilder
     *
     * Creates a list with the new size, gets the new hash of each value and
     * adds this value to the new list, then changes current list and size
     * variables of the hashtable
     *
     * @param newSize
     */

    void rebuild(int newSize);

    /**
     * @brief Hashtable extender
     *
     * Rebuilds hashtable with size equal to current size * 3 / 2 + 1
     */

    void extend();
};
