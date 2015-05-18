#pragma once

class LinkedList
{
public:

    /**
     * @brief LinkedList constructor
     *
     * Creates the guard element to make processing easier
     */

    LinkedList();

    ~LinkedList();

    /**
     * @brief LinkedList insert function
     *
     * @param value A value to be inserted
     */

    void insert(int value);

    /**
     * @brief LinkedList value remover
     *
     * @param value A value to be removed
     */

    void remove(int value);

    /**
     * @brief LinkedList printer
     *
     * Displays the list on the console
     */

    void print() const;

    /**
     * @brief LinkedList length getter
     *
     * @return An integer, equal to the list's length
     */

    int getLength() const;

private:
    struct ListElement;
    ListElement *head;

    /**
     * @brief LinkedList element remover
     *
     * @param current The previous to the element which is to be removed
     */

    void removeAfter(ListElement *current);
};
