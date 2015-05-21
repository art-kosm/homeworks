#include <iostream>
#include "calculator.h"
#include "treeBuilder.h"

Calculator::Calculator()
{
    tree = nullptr;
}

Calculator::~Calculator()
{
    delete tree;
}

void Calculator::buildTreeFromFile(char *path)
{
    TreeBuilder *builder = new TreeBuilder;
    tree = builder->buildTree(path);

    delete builder;
}

void Calculator::printTree() const
{
    if (tree != nullptr)
        tree->print();
}

void Calculator::printValue() const
{
    if (tree != nullptr)
        std::cout << "Result is " << tree->calculate();
}
