#include <iostream>
#include "tree.h"

Tree::Tree()
{
    operation = nullptr;
    leftOperand = nullptr;
    rightOperand = nullptr;
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
    if (operation != nullptr &&
        leftOperand != nullptr &&
        rightOperand != nullptr)
        switch (operation->get())
        {
            case '+':
                return leftOperand->calculate() + rightOperand->calculate();

            case '-':
                return leftOperand->calculate() - rightOperand->calculate();

            case '*':
                return leftOperand->calculate() * rightOperand->calculate();

            case '/':
                return leftOperand->calculate() / rightOperand->calculate();

            default:
                break;
        }

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
