#pragma once

#include "operand.h"
#include "operator.h"

class Tree : public Operand
{
public:
    Tree();
    ~Tree();
    void setOperation(Operator *operation);
    void setLeftOperand(Operand *operand);
    void setRightOperand(Operand *operand);
    int calculate() const;
    void print() const;

private:
   Operator *operation;
   Operand *leftOperand;
   Operand *rightOperand;
};
