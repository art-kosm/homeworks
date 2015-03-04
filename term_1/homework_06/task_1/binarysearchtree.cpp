#include <stdio.h>
#include "binarysearchtree.h"

struct Node
{
    int value;
    Node *leftChild;
    Node *rightChild;
};

struct BinarySearchTree
{
    Node *root;
};

enum NodeType
{
    isLeaf,
    hasOnlyLeftChild,
    hasOnlyRightChild,
    hasBothChildren
};

NodeType nodeType(Node *node)
{
    if (node->leftChild == nullptr && node->rightChild == nullptr)
        return isLeaf;
    if (node->leftChild != nullptr && node->rightChild == nullptr)
        return hasOnlyLeftChild;
    if (node->leftChild == nullptr && node->rightChild != nullptr)
        return hasOnlyRightChild;
    return hasBothChildren;
}

Node *addNode(int value)
{
    Node *node = new Node;
    node->value = value;
    node->leftChild = nullptr;
    node->rightChild = nullptr;

    return node;
}

BinarySearchTree *createTree()
{
    BinarySearchTree *tree = new BinarySearchTree;
    tree->root = nullptr;

    return tree;
}

BinarySearchTree *createTree(int value)
{
    BinarySearchTree *tree = new BinarySearchTree;
    tree->root = addNode(value);

    return tree;
}

Node *findLastNode(BinarySearchTree *tree, int value)
{
    Node *current = tree->root;
    while (true)
        if (value < current->value && current->leftChild != nullptr)
            current = current->leftChild;
        else if (value > current->value && current->rightChild != nullptr)
            current = current->rightChild;
        else
            break;

    return current;
}

bool contains(BinarySearchTree *tree, int value)
{
    if (tree->root == nullptr)
        return false;
    Node *node = findLastNode(tree, value);
    return value == node->value;
}

int root(BinarySearchTree *tree)
{
    return tree->root->value;
}

void addValue(BinarySearchTree *tree, int value)
{
    if (tree->root != nullptr)
    {
        Node *node = findLastNode(tree, value);
        if (value != node->value)
        {
            if (value < node->value)
                node->leftChild = addNode(value);
            else
                node->rightChild = addNode(value);
        }
    }
    else
        tree->root = addNode(value);
}

void removeLeaf(BinarySearchTree *tree, Node *node, Node *parent, int value)
{
    if (parent != nullptr)
    {
        if (parent->value > value)
            parent->leftChild = nullptr;
        else
            parent->rightChild = nullptr;
    }
    else
        tree->root = nullptr;
    delete node;
}

void removeHavingOnlyLeftChild(BinarySearchTree *tree, Node *node, Node *parent, int value)
{
    if (parent != nullptr)
    {
        if (parent->value > value)
            parent->leftChild = node->leftChild;
        else
            parent->rightChild = node->leftChild;
    }
    else
        tree->root = node->leftChild;
    delete node;
}

void removeHavingOnlyRightChild(BinarySearchTree *tree, Node *node, Node *parent, int value)
{
    if (parent != nullptr)
    {
        if (parent->value > value)
            parent->leftChild = node->rightChild;
        else
            parent->rightChild = node->rightChild;
    }
    else
        tree->root = node->rightChild;
    delete node;
}

void removeHavingBothChildren(BinarySearchTree *tree, Node *node)
{
    Node *leftmost = node->rightChild;
    while (leftmost->leftChild != nullptr)
        leftmost = leftmost->leftChild;
    int leftmostValue = leftmost->value;
    removeValue(tree, leftmost->value);
    node->value = leftmostValue;
}

void removeValue(BinarySearchTree *tree, int value)
{
    if (contains(tree, value))
    {
        Node *node = tree->root;
        Node *parent = nullptr;
        while (true)
            if (value < node->value && node->leftChild != nullptr)
            {
                parent = node;
                node = node->leftChild;
            }
            else if (value > node->value && node->rightChild != nullptr)
            {
                parent = node;
                node = node->rightChild;
            }
            else
                break;

        if (node->value == value)
        {
            switch (nodeType(node))
            {
                case isLeaf:
                    removeLeaf(tree, node, parent, value);
                    break;

                case hasOnlyLeftChild:
                    removeHavingOnlyLeftChild(tree, node, parent, value);
                    break;

                case hasOnlyRightChild:
                    removeHavingOnlyRightChild(tree, node, parent, value);
                    break;

                case hasBothChildren:
                    removeHavingBothChildren(tree, node);
                    break;
            }
        }
    }
}

void printPreorder(Node *node)
{
    if (node != nullptr)
    {
        printf(" (%d", node->value);
        printPreorder(node->leftChild);
        printPreorder(node->rightChild);
        printf(")");
    }
    else
        printf(" null");
}

void printPreorder(BinarySearchTree *tree)
{
    printPreorder(tree->root);
}

void printAscending(Node *node)
{
    if (node != nullptr)
    {
        printAscending(node->leftChild);
        printf("%d ", node->value);
        printAscending(node->rightChild);
    }
}

void printAscending(BinarySearchTree *tree)
{
    printAscending(tree->root);
}

void printDescending(Node *node)
{
    if (node != nullptr)
    {
        printDescending(node->rightChild);
        printf("%d ", node->value);
        printDescending(node->leftChild);
    }
}

void printDescending(BinarySearchTree *tree)
{
    printDescending(tree->root);
}

void printPostorder(Node *node)
{
    if (node != nullptr)
    {
        printPostorder(node->leftChild);
        printPostorder(node->rightChild);
        printf("%d ", node->value);
    }
}

void printPostorder(BinarySearchTree *tree)
{
    printPostorder(tree->root);
}

void deleteTree(BinarySearchTree *tree)
{
    while (tree->root != nullptr)
        removeValue(tree, tree->root->value);
    delete tree;
}
