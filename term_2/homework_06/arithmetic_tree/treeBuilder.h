#pragma once

#include <fstream>
#include "tree.h"

class TreeBuilder
{
public:
    Tree *buildTree(char *path);

private:
    Tree *readTree(std::ifstream &in, char operation);
    void setOperator(Tree *readTree, char operation);
    void setOperands(Tree *readTree, std::ifstream &in);
    bool isDigit(char c) const;
    bool isOperator(char c) const;
    int number(char c) const;
};
