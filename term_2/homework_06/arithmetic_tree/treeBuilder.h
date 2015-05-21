#pragma once

#include <fstream>
#include "tree.h"

class TreeBuilder
{
public:

    /**
     * @brief Tree builder
     *
     * @param path of the file containing the tree representation
     */

    Tree *buildTree(char *path);

private:

    /**
     * @brief Next tree reader
     *
     * Is called when the operand happened to be a tree
     *
     * @param in stream from the file
     * @param operation
     * @return Full next tree
     */

    Tree *readTree(std::ifstream &in, char operation);
    void setOperator(Tree *tree, char operation);
    void setOperands(Tree *tree, std::ifstream &in);

    bool isDigit(char c) const;
    bool isOperator(char c) const;

    /**
     * @brief number
     *
     * Transforms a digit in char format into a number
     * Is supposed to be used on characters from '0' to '9'
     *
     * @param c
     * @return int
     */

    int number(char c) const;
};
