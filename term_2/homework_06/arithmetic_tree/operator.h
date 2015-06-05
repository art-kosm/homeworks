#pragma once

class Operator
{
public:
    virtual ~Operator() {}

    /**
     * @brief Current Operator realisation value getter
     *
     * @return '+', '-', '*' or '/'
     */

    char get() const;

    /**
     * @brief Operator value printer
     *
     * Prints the value to the console with std::cout
     */

    void print() const;

    virtual int calculate(int, int) const = 0;

protected:

    /**
     * @brief value
     *
     * Can be used in child classes
     */

    char value;
};
