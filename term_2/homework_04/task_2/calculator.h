#pragma once

#include <QString>

class Calculator
{
public:

    /**
     * @brief Calculates the expression constituted of arguments and operand
     *
     * @param firstArgument
     * @param secondArgument
     * @param operation
     *
     * @return double resulting value
     */

    double calculate(int firstArgument, int secondArgument, const QString &operation) const;

private:

    /**
     * @brief Raises base to the specified power
     *
     * @param base
     * @param power
     *
     * @return double base ^ power value
     */

    double exponentiate(int base, int power) const;
};
