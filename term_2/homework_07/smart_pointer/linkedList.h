#pragma once

template <typename T>
class LinkedList
{
public:

    /**
     * @brief LinkedList constructor
     *
     * Creates a list of T pointers
     * Creates the guard element to make processing easier
     */

    LinkedList()
    {
        ListElement *guard = new ListElement;

        guard->value = nullptr;
        guard->count = 0;
        guard->next = nullptr;

        head = guard;
    }

    ~LinkedList()
    {
        ListElement *current = head;

        while (current->next != nullptr)
            deleteNextElement(current);

        delete head;
    }

    /**
     * @brief Value adder
     *
     * Adds only currently non-existing value
     *
     * @param value T pointer to be added
     */

    void add(T *value)
    {
        ListElement *element = find(value);

        if (element->next != nullptr)   //found (element->next->value == value)
            element->next->count++;
        else                            //not found
        {
            ListElement *newElement = new ListElement;

            newElement->value = value;
            newElement->count = 1;
            newElement->next = nullptr;

            element->next = newElement;
        }
    }

    /**
     * @brief Value remover
     *
     * Deletes the element if it's counter is 1, decreases counter if it is
     * greater then 1, does nothing otherwise
     *
     * @param value T pointer to be removed
     */

    void remove(T *value)
    {
        ListElement *current = head;

        while (current != nullptr && current->next != nullptr)
            if (current->next->value == value)
            {
                if (current->next->count == 1)
                    deleteNextElement(current);
                else
                    current->next->count--;

                break;
            }
            else
                current = current->next;
    }

    int count(T *value) const
    {
        ListElement *element = find(value);
        if (element->next != nullptr)
            return element->next->count;

        return 0;
    }

    int length() const
    {
        int length = 0;

        ListElement *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
            length++;
        }

        return length;
    }

private:
    struct ListElement
    {
        T *value;
        int count; ///number of pointers to the object
        ListElement *next;
    };

    ListElement *head;

    /**
     * @brief Element finder
     *
     * @param value T pointer to be found
     * @return ListElement with this value
     */

    ListElement *find(T *value) const
    {
        ListElement *current = head;
        while (current->next != nullptr && value != current->next->value)
            current = current->next;

        return current;
    }

    /**
     * @brief Element remover
     *
     * @param current The previous to the element which is to be removed
     */

    void deleteNextElement(ListElement *current)
    {
        ListElement *element = current->next;
        current->next = current->next->next;

        delete element->value;
        delete element;
    }
};
