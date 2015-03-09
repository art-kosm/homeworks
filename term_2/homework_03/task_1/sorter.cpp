#include "sorter.h"

void Sorter::swap(dataType &first, dataType &second)
{
    dataType memory = first;
    first = second;
    second = memory;
}
