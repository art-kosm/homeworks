#pragma once
typedef int dataType;

class Sorter
{
public:
    virtual ~Sorter() {}
    virtual void sort(dataType *array, int size) = 0;

protected:
    void swap(dataType &first, dataType &second);
};
