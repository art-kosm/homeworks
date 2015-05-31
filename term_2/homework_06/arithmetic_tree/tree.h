#pragma once

#include "operand.h"
#include "operator.h"

class Tree : public Operand
{
public:
    Tree(Operator *operation = nullptr, Operand *leftOperand = nullptr, Operand *rightOperand = nullptr);
    ~Tree();
    void setOperation(Operator *operation);
    void setLeftOperand(Operand *operand);
    void setRightOperand(Operand *operand);

    ///Functions inherited from the base class

    int calculate() const;

    /**
     * @brief The tree printer
     *
     * Format is "(<operation> <left operand> <right operand>)"
     */

    void print() const;

private:
   Operator *operation;
   Operand *leftOperand;
   Operand *rightOperand;
};
