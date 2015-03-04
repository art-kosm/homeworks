#include <stdio.h>
#include <fstream>
#include "binaryexpressiontree.h"

struct Node
{
    char value;
    Node *leftChild;
    Node *rightChild;
    Node *parent;
};

struct BinaryExpressionTree
{
    Node *root;
};

bool isDigit(char character)
{
    return character >= '0' && character <= '9';
}

bool isOperator(char character)
{
    return  character == '+' || character == '-' || character == '*' || character == '/';
}

Node *addNode(int value, Node *parent)
{
    Node *node = new Node;
    node->value = value;
    node->leftChild = nullptr;
    node->rightChild = nullptr;
    node->parent = parent;

    return node;
}

BinaryExpressionTree *createTree(int value)
{
    BinaryExpressionTree *tree = new BinaryExpressionTree;
    tree->root = addNode(value, nullptr);

    return tree;
}

void addRightChild(Node *node, char c)
{
    node->rightChild = addNode(c, node);
}

void addLeftChild(Node *node, char c)
{
    node->leftChild = addNode(c, node);
}

bool isRightChild(Node *node)
{
    return node == node->parent->rightChild;
}

BinaryExpressionTree *makeTreeFromFile(char *path)
{
    std::ifstream in(path);
    if (in == nullptr)
        return nullptr;

    char previous = '\0';
    while (!in.eof() && !isOperator(previous) && !isDigit(previous))
        in >> previous;
    BinaryExpressionTree *tree = createTree(previous);
    Node *node = tree->root;

    char current = '\0';
    while (!in.eof() && !isOperator(current) && !isDigit(current))
        in >> current;
    addLeftChild(node, current);
    node = node->leftChild;

    char next = '\0';

    while (true)
    {
        while (!in.eof() && !isDigit(next) && !isOperator(next))
            in >> next;

        if (in.eof())
            break;

        if (isDigit(previous) && isDigit(current))
        {
            while (isRightChild(node))
                node = node->parent;
            node = node->parent;
            addRightChild(node, next);
            node = node->rightChild;
        }
        else if (isOperator(previous) && isDigit(current))
        {
            node = node->parent;
            addRightChild(node, next);
            node = node->rightChild;
        }
        else if (isOperator(current))
        {
            addLeftChild(node, next);
            node = node->leftChild;
        }

        previous = current;
        current = next;
        in >> next;
    }

    return tree;
}

int convertToNumber(char character)
{
    int difference = '1' - 1;

    return character - difference;
}

void printPreorder(Node *node)
{
    if (node != nullptr)
    {
        if (node->parent != nullptr)
            printf(" ");
        if (node->leftChild != nullptr)
            printf("(");
        if (isDigit(node->value))
            printf("%d", convertToNumber(node->value));
        else
            printf("%c", node->value);
        printPreorder(node->leftChild);
        printPreorder(node->rightChild);
        if (node->leftChild != nullptr)
            printf(")");
    }
}

void printPreorder(BinaryExpressionTree *tree)
{
    printPreorder(tree->root);
}

void removeLeaf(BinaryExpressionTree *tree, Node *node)
{
    if (node != tree->root)
    {
        if (isRightChild(node))
            node->parent->rightChild = nullptr;
        else
            node->parent->leftChild = nullptr;
    }
    else
        tree->root = nullptr;

    delete node;
}

int compute(Node *node)
{
    if (node != nullptr)
    {
        int left = compute(node->leftChild);
        int right = compute(node->rightChild);
        switch (node->value)
        {
            case '+':
                return left + right;

            case '-':
                return left - right;

            case '*':
                return left * right;

            case '/':
                return left / right;

            default:
                return convertToNumber(node->value);
        }
    }

    return 0;
}

int compute(BinaryExpressionTree *tree)
{
    return compute(tree->root);
}

void deleteTree(BinaryExpressionTree *tree)
{
    while (tree->root != nullptr)
    {
        Node *node = tree->root;
        while (node->leftChild != nullptr || node->rightChild != nullptr)
            if (node->leftChild != nullptr)
                node = node->leftChild;
            else
                node = node->rightChild;
        removeLeaf(tree, node);
    }

    delete tree;
}
