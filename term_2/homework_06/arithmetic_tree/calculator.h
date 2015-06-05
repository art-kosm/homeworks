#pragma once

#include "tree.h"

class Calculator
{
public:
    Calculator();
    ~Calculator();

    /**
     * @brief Tree builder
     *
     * Uses a TreeBuilder
     *
     * @param path of the file containing the tree representation
     */

    void buildTreeFromFile(char *path);

    void printTree() const;

    /**
     * @brief The tree value printer
     *
     * Calculates the tree value first
     */

    void printValue() const;

private:
    Tree *tree;
};
