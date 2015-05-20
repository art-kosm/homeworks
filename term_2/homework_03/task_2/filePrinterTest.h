#pragma once

#include <iostream>
#include <fstream>
#include <QObject>
#include <QtTest/QtTest>
#include "filePrinter.h"

class FilePrinterTest : public QObject
{
    Q_OBJECT

public:
    explicit FilePrinterTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        printer = new FilePrinter();
    }

    void cleanup()
    {
        delete printer;

        for (int i = 0; i < size; i++)
            delete [] array[i];
        delete [] array;

        for (int i = 0; i < size; i++)
            delete [] fileText[i];
        delete [] fileText;
    }

    void testOneElement()
    {
        size = 1;
        int values[size] = {-10};
        array = initializeArray(size, values);

        std::cout << "Enter any correct path: ";
        char *string = getStringFromStandardInput();
        int length = 1;
        for (int i = 0; string[i] != '\0'; i++)
            length++;

        char path[length];
        for (int i = 0; i < length; i++)
            path[i] = string[i];

        delete [] string;

        printer->printArray(array, size, path);

        fileText = getTextFromInputFile(path);

        QVERIFY(QString(fileText[0]) == "element 1: -10");
    }

    void testMultipleElements()
    {
        size = 3;
        int values[size * size] = {-3, 14, 15, 92, 6, -535, 8, 9, 79};
        array = initializeArray(size, values);

        std::cout << "Enter any correct path: ";
        char *string = getStringFromStandardInput();
        int length = 1;
        for (int i = 0; string[i] != '\0'; i++)
            length++;

        char path[length];
        for (int i = 0; i < length; i++)
            path[i] = string[i];

        delete [] string;

        printer->printArray(array, size, path);

        fileText = getTextFromInputFile(path);

        QVERIFY(QString(fileText[0]) == "element 1: 6" &&
                QString(fileText[1]) == "element 2: 9" &&
                QString(fileText[2]) == "element 3: 79" &&
                QString(fileText[3]) == "element 4: -535" &&
                QString(fileText[4]) == "element 5: 15" &&
                QString(fileText[5]) == "element 6: 14" &&
                QString(fileText[6]) == "element 7: -3" &&
                QString(fileText[7]) == "element 8: 92" &&
                QString(fileText[8]) == "element 9: 8");
    }

private:
    FilePrinter *printer;
    int size;
    int **array;
    char **fileText;

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

    char *extend(char *&array, int length, int maxLength)
    {
        char *newArray = new char[maxLength];
        for (int i = 0; i < length; i++)
            newArray[i] = array[i];

        delete [] array;

        return newArray;
    }

    int **initializeArray(int size, int *values)
    {
        int **array = new int*[size];
        for(int i = 0; i < size; i++)
            array[i] = new int[size];

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                array[i][j] = values[size * i + j];
            }
        }

        return array;
    }

    char **getTextFromInputFile(char *path)
    {
        std::ifstream in(path);

        int stringsNumber = 0;
        int charactersNumber = 0;
        int currentCharacters = 0;

        while (!in.eof())
        {
            char c = '\0';
            in >> std::noskipws >> c;
            if (c != '\n' && c != '\0')
                currentCharacters++;
            else
            {
                if (currentCharacters > charactersNumber)
                    charactersNumber = currentCharacters;
                currentCharacters = 0;
                stringsNumber++;
            }
        }
        stringsNumber++;
        in.clear();
        in.seekg(0, std::ios::beg);

        char **text = new char*[stringsNumber];
        for (int i = 0; i < stringsNumber; i++)
        {
            text[i] = new char[charactersNumber + 1]; // +1 from '\n' or '\0'
            in.getline(text[i], charactersNumber + 1);
        }

        in.close();

        return text;
    }
};
