#include "calculator.h"

Calculator::Calculator()
{
    decimalShift = -1;
    currentResult = 0;
    currentOperand = 0;
    currentOperation = '+';
}

void Calculator::setNextOperand(const QString &operand)
{
    bool lessThanZero = false;
    for (int i = 0; i < operand.length(); i++)
        if (operand.at(i) == '.')
            decimalShift++;
        else if (operand.at(i) == '-')
            lessThanZero = true;
        else
        {
            currentOperand = 10 * currentOperand + operand.at(i).digitValue();
            if (decimalShift > -1)
                decimalShift++;
        }

    while (decimalShift > 0)
    {
        currentOperand /= 10;
        decimalShift--;
    }

    if (decimalShift > -1)
        decimalShift--;

    if (lessThanZero)
        currentOperand = -currentOperand;

    updateResult();
    currentOperand = 0;
}

void Calculator::setOperation(char operation)
{
    currentOperation = operation;
}

double Calculator::getResult() const
{
    return currentResult;
}

void Calculator::updateResult()
{
    switch (currentOperation)
    {
        case '+':
            currentResult += (double) currentOperand;
            break;

        case '-':
            currentResult -= (double) currentOperand;
            break;

        case '*':
            currentResult *= (double) currentOperand;
            break;

        case '/':
            currentResult /= (double) currentOperand;
            break;

        default:
            break;
    }
}
