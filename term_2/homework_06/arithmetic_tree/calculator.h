#pragma once

#include "tree.h"

class Calculator
{
public:
    Calculator();
    ~Calculator();
    void makeTreeFromFile(char *path);
    void printTree() const;
    void printValue() const;

private:
    Tree *tree;
};
