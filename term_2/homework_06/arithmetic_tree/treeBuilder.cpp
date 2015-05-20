#include "treeBuilder.h"
#include "operatorAdd.h"
#include "operatorSub.h"
#include "operatorMul.h"
#include "operatorDiv.h"
#include "number.h"

Tree *TreeBuilder::buildTree(char *path)
{
    std::ifstream in(path);
    if (in == nullptr)
        return nullptr;

    char current = '\0';
    while (!isOperator(current))
        in >> current;

    return readTree(in, current);
}

Tree *TreeBuilder::readTree(std::ifstream &in, char operation)
{
    Tree *tree = new Tree();

    setOperator(tree, operation);
    setOperands(tree, in);

    return tree;
}

void TreeBuilder::setOperator(Tree *tree, char operation)
{
    switch (operation)
    {
        case '+':
            tree->setOperation(new OperatorAdd());
            break;

        case '-':
            tree->setOperation(new OperatorSub());
            break;

        case '*':
            tree->setOperation(new OperatorMul());
            break;

        case '/':
            tree->setOperation(new OperatorDiv());
            break;

        default:
            break;
    }
}

void TreeBuilder::setOperands(Tree *tree, std::ifstream &in)
{
    char current = '\0';

    while (!isDigit(current) && !isOperator(current))
        in >> current;

    if (isDigit(current))
        tree->setLeftOperand(new Number(number(current)));
    else
        tree->setLeftOperand(readTree(in, current));

    in >> current;

    while (!isDigit(current) && !isOperator(current))
        in >> current;

    if (isDigit(current))
        tree->setRightOperand(new Number(number(current)));
    else
        tree->setRightOperand(readTree(in, current));
}

bool TreeBuilder::isDigit(char c) const
{
    return c >= '0' && c <= '9';
}

bool TreeBuilder::isOperator(char c) const
{
    return  c == '+' || c == '-' || c == '*' || c == '/';
}

int TreeBuilder::number(char c) const
{
    return c - '0';
}

