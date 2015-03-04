#include <stdio.h>
#include "avltree.h"

struct Node
{
    int value;
    int height;
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

int height(Node *node)
{
    return node ? node->height : 0;
}

int balanceFactor(Node *node)
{
   return height(node->rightChild) - height(node->leftChild);
}

void updateHeight(Node *node)
{
   int heightLeft = height(node->leftChild);
   int heightRight = height(node->rightChild);
   node->height = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
}

Node *rotateRight(Node *root)
{
   Node *pivot = root->leftChild;
   root->leftChild = pivot->rightChild;
   pivot->rightChild = root;
   updateHeight(root);
   updateHeight(pivot);

   return pivot;
}

Node *rotateLeft(Node *root)
{
   Node *pivot = root->rightChild;
   root->rightChild = pivot->leftChild;
   pivot->leftChild = root;
   updateHeight(root);
   updateHeight(pivot);

   return pivot;
}

Node *balance(Node *node)
{
    updateHeight(node);
    int factor = balanceFactor(node);

    if (factor == 2)
    {
        if (balanceFactor(node->rightChild) < 0)
            node->rightChild = rotateRight(node->rightChild);

        node = rotateLeft(node);
    }

    if (factor == -2)
    {
        if (balanceFactor(node->leftChild) > 0)
            node->leftChild = rotateLeft(node->leftChild);

        node = rotateRight(node);
    }

    return node;
}

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
    node->height = 1;
    node->leftChild = nullptr;
    node->rightChild = nullptr;

    return node;
}

Node *addNode(Node *node, int value)
{
    if (value < node->value && node->leftChild != nullptr)
        node->leftChild = addNode(node->leftChild, value);
    else if (value < node->value && node->leftChild == nullptr)
        node->leftChild = addNode(value);
    else if (value > node->value && node->rightChild != nullptr)
        node->rightChild = addNode(node->rightChild, value);
    else if (value > node->value && node->rightChild == nullptr)
        node->rightChild = addNode(value);

    return balance(node);
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
        tree->root = addNode(tree->root, value);
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

void removeNode(BinarySearchTree *tree, Node *node, Node *parent, Node *parentOfParent, int value)
{
    if (value < node->value)
        removeNode(tree, node->leftChild, node, parent, value);
    else if (value > node->value)
        removeNode(tree, node->rightChild, node, parent, value);
    else
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

    if (parent != nullptr)
    {
        if (parentOfParent != nullptr)
        {
            if (parent->value < parentOfParent->value)
                parentOfParent->leftChild = balance(parent);
            else
                parentOfParent->rightChild = balance(parent);
        }
        else
            tree->root = balance(parent);
    }
}

void removeValue(BinarySearchTree *tree, int value)
{
    if (contains(tree, value))
        removeNode(tree, tree->root, nullptr, nullptr, value);
}

void printPreorder(Node *node, bool isRoot)
{
    if (node != nullptr)
    {
        if (!isRoot)
            printf(" ");
        printf("(%d", node->value);
        printPreorder(node->leftChild, false);
        printPreorder(node->rightChild, false);
        printf(")");
    }
    else
        printf(" null");
}

void printPreorder(BinarySearchTree *tree)
{
    printPreorder(tree->root, true);
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
