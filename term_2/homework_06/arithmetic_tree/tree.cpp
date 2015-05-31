#include <iostream>
#include "tree.h"

Tree::Tree(Operator *operation, Operand *leftOperand, Operand *rightOperand)
{
    this->operation = operation;
    this->leftOperand = leftOperand;
    this->rightOperand = rightOperand;
}

Tree::~Tree()
{
    delete operation;
    delete leftOperand;
    delete rightOperand;
}

void Tree::setOperation(Operator *operation)
{
    this->operation = operation;
}

void Tree::setLeftOperand(Operand *operand)
{
    leftOperand = operand;
}

void Tree::setRightOperand(Operand *operand)
{
    rightOperand = operand;
}

int Tree::calculate() const
{
    return operation->calculate(leftOperand->calculate(), rightOperand->calculate());

    if (operation != nullptr && leftOperand != nullptr && rightOperand != nullptr)
        return operation->calculate(leftOperand->calculate(), rightOperand->calculate());

    return 0;
}

void Tree::print() const
{
    std::cout << "(";
    operation->print();
    std::cout << " ";
    leftOperand->print();
    std::cout << " ";
    rightOperand->print();
    std::cout << ")";
}
