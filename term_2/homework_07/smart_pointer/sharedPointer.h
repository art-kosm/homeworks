#pragma once

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

    SharedPointer(T *newObject = nullptr) :
        object(newObject),
        counter(new int(1))
    {}

    /**
     * @brief SharedPointer copy constructor
     *
     * Increments the object count
     *
     * @param pointer
     */

    SharedPointer(const SharedPointer &pointer)
    {
        setObjectPointer(pointer);
    }

    ~SharedPointer()
    {
        decreaseCounter();
    }

    SharedPointer& operator=(const SharedPointer &pointer)
    {
        decreaseCounter();
        setObjectPointer(pointer);

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
        return *counter;
    }

    void setObjectPointer(const SharedPointer &pointer)
    {
        object = pointer.object;
        counter = pointer.counter;

        (*counter)++;
    }

    void decreaseCounter()
    {
        (*counter)--;

        if (*counter == 0)
        {
            delete object;
            delete counter;
        }
    }

private:
    T *object;
    int *counter;
};
