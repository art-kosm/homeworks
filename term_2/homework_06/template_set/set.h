#pragma once

template <typename T>
class Set
{
public:
    Set(int capacity = 3);
    ~Set();

    /**
     * @brief Value adder
     *
     * Does nothing if the value is already presented
     *
     * @param value
     */

    void add(T value);

    /**
     * @brief Value remover
     *
     * Finds the value, removes it and moves the rest of the contents array
     * Does nothing if the value is not found
     *
     * @param value
     */

    void remove(T value);

    bool contains(T value) const;

    /**
     * @brief Sets intersecter
     *
     * For each element in set1 searches for the same element in set2
     *
     * @param set1
     * @param set2
     * @return intersection of sets
     */

    static Set<T> *intersect(Set<T> *set1, Set<T> *set2);

    /**
     * @brief Sets uniter
     *
     * Simply adds elements from both sets to the new one
     *
     * @param set1
     * @param set2
     * @return union of sets
     */

    static Set<T> *unite(Set<T> *set1, Set<T> *set2);

private:
    T *contents;

    int capacity;
    int elementsNumber;

    /**
     * @brief Set extender
     *
     * Copies elements from contents array to the new one
     */

    void extend();
};



template <typename T>
Set<T>::Set(int capacity)
{
    this->capacity = capacity;

    elementsNumber = 0;
    contents = new T[capacity];
}

template <typename T>
Set<T>::~Set()
{
    delete [] contents;
}

template <typename T>
void Set<T>::add(T value)
{
    if (!contains(value))
    {
        contents[elementsNumber] = value;
        elementsNumber++;
    }

    if (elementsNumber == capacity)
        extend();
}

template <typename T>
void Set<T>::remove(T value)
{
    for (int i = 0; i < elementsNumber; i++)
        if (contents[i] == value)
        {
            elementsNumber--;
            for (int j = i; j < elementsNumber; j++)
                contents[j] = contents[j + 1];
            break;
        }
}

template <typename T>
bool Set<T>::contains(T value) const
{
    for (int i = 0; i < elementsNumber; i++)
        if (contents[i] == value)
            return true;

    return false;
}

template <typename T>
Set<T> *Set<T>::intersect(Set<T> *set1, Set<T> *set2)
{
    Set<T> *intersected = new Set<T>;

    for (int i = 0; i < set1->elementsNumber; i++)
        for (int j = 0; j < set2->elementsNumber; j++)
            if (set1->contents[i] == set2->contents[j])
                intersected->add(set1->contents[i]);

    return intersected;
}

template <typename T>
Set<T> *Set<T>::unite(Set<T> *set1, Set<T> *set2)
{
    Set<T> *united = new Set<T>;

    for (int i = 0; i < set1->elementsNumber; i++)
        united->add(set1->contents[i]);
    for (int i = 0; i < set2->elementsNumber; i++)
        united->add(set2->contents[i]);

    return united;
}

template <typename T>
void Set<T>::extend()
{
    int newCapacity = capacity * 3 / 2 + 1;
    T *newContents = new T[newCapacity];
    for (int i = 0; i < elementsNumber; i++)
        newContents[i] = contents[i];
    delete [] contents;
    contents = newContents;
}
