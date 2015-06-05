#include "bag.h"

Bag::Bag()
{
    tree = new Tree();
}

Bag::~Bag()
{
    delete tree;
}

void Bag::add(int value)
{
    tree->add(value);
}

void Bag::remove(int value)
{
    tree->remove(value);
}

bool Bag::contains(int value) const
{
    return tree->contains(value);
}
