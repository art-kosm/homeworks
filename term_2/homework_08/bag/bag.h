#pragma once

#include "tree.h"

/**
 * @brief The Bag class
 *
 * Based on AVL tree with nodes containing a times counter
 */

class Bag
{
public:
    Bag();
    ~Bag();
    void add(int value);
    void remove(int value);
    bool contains(int value) const;

private:
    Tree *tree;
};
