#pragma once

#include <iostream>
#include <fstream>
#include <QObject>
#include <QtTest/QtTest>
#include "treeBuilder.h"

class TreeBuilderTest : public QObject
{
    Q_OBJECT

public:
    explicit TreeBuilderTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        treeBuilder = new TreeBuilder;
    }

    void cleanup()
    {
        delete treeBuilder;
        delete tree;
    }

    void testSimpleTree()
    {
        std::cout << "Enter any valid file path: ";
        path = getStringFromStandardInput();

        std::ofstream out(path);
        out << "(/ 6 3)";
        out.close();

        tree = treeBuilder->buildTree(path);

        QVERIFY(tree->calculate() == 2);
    }

    void testComplexTree()
    {
        std::ofstream out(path);
        out << "(* (+ 1 2) (- 5 4))";
        out.close();

        tree = treeBuilder->buildTree(path);

        QVERIFY(tree->calculate() == 3);
    }

    void testVeryComplexTree()
    {
        std::ofstream out(path);

        out << "* (- (+ (/ 6 3) (+ 1 1)) 7) (/ 8 (- 7 3))";
        out.close();

        tree = treeBuilder->buildTree(path);
        delete path;

        QVERIFY(tree->calculate() == -6);
    }

private:
    TreeBuilder *treeBuilder;
    char *path;
    Tree *tree;

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
};
