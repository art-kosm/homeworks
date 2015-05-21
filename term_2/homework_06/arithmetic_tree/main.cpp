#include <iostream>
#include "calculator.h"
#include "operatorTest.h"
#include "numberTest.h"
#include "operandTest.h"
#include "treeTest.h"
#include "treeBuilderTest.h"

char *extend(char *&array, int length, int maxLength)
{
    char *newArray = new char[maxLength];
    for (int i = 0; i < length; i++)
        newArray[i] = array[i];

    delete [] array;

    return newArray;
}

char *getStringFromStandardInput()
{
    int size = 10;
    int length = 0;
    char *string = new char[size];

    while (true)
    {
        scanf("%c", &string[length]);
        length++;
        if (string[length - 1] == '\n')
        {
            string[length - 1] = '\0';
            break;
        }
        if (length == size)
        {
            size = size * 3 / 2 + 1;
            string = extend(string, length, size);
        }
    }

    return string;
}

void runTests()
{
    OperatorTest testOperator;
    QTest::qExec(&testOperator);
    std::cout << std::endl;

    NumberTest testNumber;
    QTest::qExec(&testNumber);
    std::cout << std::endl;

    OperandTest testOperand;
    QTest::qExec(&testOperand);
    std::cout << std::endl;

    TreeTest testTree;
    QTest::qExec(&testTree);
    std::cout << std::endl;

    TreeBuilderTest testBuilder;
    QTest::qExec(&testBuilder);
    std::cout << std::endl;
}

void processTree()
{
    std::cout << "Enter the file path: ";
    char *path = getStringFromStandardInput();

    Calculator *calculator = new Calculator();
    calculator->buildTreeFromFile(path);

    delete path;

    calculator->printTree();
    std::cout << std::endl;

    calculator->printValue();
    std::cout << std::endl;

    delete calculator;
}

int main()
{
    runTests();
    processTree();

    return 0;
}
