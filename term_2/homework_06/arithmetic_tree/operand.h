#pragma once

class Operand
{
public:
    virtual ~Operand() {}

    /**
     * @brief Current operand value calculator
     *
     * @return The value of the number or the result of the tree calculations
     */

    virtual int calculate() const = 0;

    /**
     * @brief Current operand printer
     *
     * Prints the operand (the number or the full tree) to the console
     */

    virtual void print() const = 0;
};
