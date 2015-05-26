#pragma once

#include <QString>

/**
 * @brief An advanced calculator
 */

class Calculator
{
public:

    /**
     * @brief Calculator constructor
     *
     * Initializes calculator parameters with default values
     */

    Calculator();

    /**
     * @brief Next operand setter
     *
     * @param QString operand any rational number
     */

    void setNextOperand(const QString &operand);

    /**
     * @brief Performing operation setter
     *
     * @param operation '+', '-', '*' or '/'
     */

    void setOperation(char operation);

    /**
     * @brief Calculations result getter
     *
     * @return Current result of calculations
     */

    double getResult() const;

private:
    int decimalShift;
    double currentResult;
    double currentOperand;
    char currentOperation;

    /**
     * @brief Current result updater
     */

    void updateResult();
};
