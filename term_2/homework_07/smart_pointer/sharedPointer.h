#pragma once

#include "linkedList.h"

template <typename T>
class SharedPointer
{
public:
    SharedPointer() {}

    /**
     * @brief SharedPointer pointer construtor
     *
     * Adds the object to objectsList if it is not presented,
     * increments its pointer count otherwise
     *
     * @param newObject
     */

    SharedPointer(T *newObject) : object(newObject)
    {
        objectsList->add(object);
    }

    /**
     * @brief SharedPointer copy constructor
     *
     * Increments the object count
     *
     * @param pointer
     */

    SharedPointer(const SharedPointer &pointer) : object(&*pointer)
    {
        objectsList->add(object);
    }

    ~SharedPointer()
    {
        objectsList->remove(object);

        if (objectsList->length() == 0)
            delete objectsList;
    }

    SharedPointer& operator=(const SharedPointer &pointer)
    {
        delete this;
        this = new SharedPointer(&*pointer);

        return *this;
    }

    T* operator->() const
    {
        return object;
    }

    T& operator*() const
    {
        return *object;
    }

    /**
     * @brief Object pointer count getter
     *
     * @return the object pointer count
     */

    int count() const
    {
        return objectsList->count(object);
    }

private:
    T *object;
    static LinkedList<T> *objectsList;
};

template <typename T>
LinkedList<T> *SharedPointer<T>::objectsList = new LinkedList<T>();
