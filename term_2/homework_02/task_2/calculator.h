#pragma once

class Calculator
{
public:
    Calculator();
    ~Calculator();
    void calculateExpression() const;

private:
    char *getStringFromStandardInput();
    char *extend(char *&array, int length, int maxLength);
    bool bracketsAreCorrect(char *string) const;

    char *input;
};