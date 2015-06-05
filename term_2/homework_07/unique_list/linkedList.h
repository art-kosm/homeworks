#pragma once

#include <QString>

struct ListElement
{
    QString value;
    ListElement *next;
};

class LinkedList
{
public:
    explicit LinkedList();
    virtual ~LinkedList();

    /**
     * @brief Value adder
     *
     * Adds a new element with the specified value to the tail of the list
     *
     * @param value
     * @return "true" if the value has already existed, "false" otherwise
     */

    bool add(const QString&);

    /**
     * @brief Value remover
     *
     * Removes each element with the specified value
     *
     * @param value
     * @return "true" if the value existed, "false" otherwise
     */

    bool remove(const QString&);
    bool contains(const QString&) const;
    int length() const; /// Number of useful elements
    QString at(int) const;

protected:
    ListElement *head;
    ListElement *find(const QString&) const;
    void deleteNextElement(ListElement*);
};
