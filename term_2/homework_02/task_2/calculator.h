#pragma once

class Calculator
{
public:
    Calculator();
    Calculator(char *expression);
    ~Calculator();
    int calculateExpression() const;

private:
    char *getStringFromStandardInput();
    char *extend(char *&array, int length, int maxLength);
    bool bracketsAreCorrect(char *string) const;

    char *input;
};
