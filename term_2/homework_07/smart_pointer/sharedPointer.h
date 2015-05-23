#pragma once

#include "linkedList.h"

template <typename T>
class SharedPointer
{
public:
    SharedPointer() {}

    SharedPointer(T *newObject) : object(newObject)
    {
        objectsList->add(object);
    }

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
        return new SharedPointer(&*pointer);
    }

    T* operator->() const
    {
        return object;
    }

    T& operator*() const
    {
        return *object;
    }

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
