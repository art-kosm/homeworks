#include "sorter.h"

void Sorter::swap(int &first, int &second)
{
    int memory = first;
    first = second;
    second = memory;
}
