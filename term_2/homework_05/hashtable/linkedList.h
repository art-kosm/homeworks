#pragma once

#include <QString>

class LinkedList
{
public:

    /**
     * @brief LinkedList constructor
     *
     * Creates a list of QStrings
     * Creates the guard element to make processing easier
     */

    LinkedList();

    ~LinkedList();

    /**
     * @brief Value adder
     *
     * Adds only currently non-existing value
     *
     * @param value QString to be added
     * @return "true" if the value has already existed, "false" otherwise
     */

    bool add(const QString &value);

    /**
     * @brief Value remover
     *
     * Removes each element with the specified value (if it somehow
     * happened to appear in the list)
     *
     * @param value QString to be removed
     * @return "true" if the value has already existed, "false" otherwise
     */

    bool remove(const QString &value);

    /**
     * @brief Value inclusion in the list checker
     *
     * @param value to be checked
     * @return "true" if the list contains an element with this value,
     *         "false" otherwise
     */

    bool contains(const QString &value) const;

    /**
     * @brief LinkedList length getter
     *
     * @return An integer, equal to the list's length
     */

    int length() const;

    /**
     * @brief SortedSet element getter
     *
     * @param index of the position
     * @return value of the element at the certain position
     */

    QString at(int index) const;

private:
    struct ListElement;
    ListElement *head;

    /**
     * @brief Element finder
     *
     * @param QString value to be found
     * @return ListElement with this value
     */

    ListElement *find(const QString &value) const;

    /**
     * @brief Element remover
     *
     * @param current The previous to the element which is to be removed
     */

    void deleteNextElement(ListElement *current);
};
