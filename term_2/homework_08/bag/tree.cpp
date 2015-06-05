#include "tree.h"

struct Tree::Node
{
    int value;
    int height;
    int times;

    Node *leftChild;
    Node *rightChild;
};

Tree::Tree()
{
    root = nullptr;
}

Tree::~Tree()
{
    while (root != nullptr)
        remove(root->value);
}

void Tree::add(int value)
{
    if (root != nullptr)
        root = addNode(root, value);        //goes for searching...
    else
        root = addNode(value);
}

void Tree::remove(int value)
{
    remove(root, nullptr, nullptr, value);  //goes for searching..
}

bool Tree::contains(int value) const
{
    if (root == nullptr)
        return false;

    Node *node = findLastNode(value);

    return value == node->value;
}

Tree::Node *Tree::addNode(int value)
{
    Node *node = new Node;

    node->value = value;
    node->height = 1;
    node->times = 1;

    node->leftChild = nullptr;
    node->rightChild = nullptr;

    return node;
}

Tree::Node *Tree::addNode(Node *node, int value)
{
    if (value < node->value && node->leftChild != nullptr)
        node->leftChild = addNode(node->leftChild, value);

    else if (value < node->value && node->leftChild == nullptr)
        node->leftChild = addNode(value);

    else if (value > node->value && node->rightChild != nullptr)
        node->rightChild = addNode(node->rightChild, value);

    else if (value > node->value && node->rightChild == nullptr)
        node->rightChild = addNode(value);

    else
    {
        node->times++;
        return node;
    }

    return balance(node);
}

Tree::Node *Tree::findLastNode(int value) const
{
    Node *current = root;

    while (true)
        if (value < current->value && current->leftChild != nullptr)
            current = current->leftChild;
        else if (value > current->value && current->rightChild != nullptr)
            current = current->rightChild;
        else
            break;

    return current;
}

Tree::NodeType Tree::nodeType(Node *node) const
{
    if (node->leftChild == nullptr && node->rightChild == nullptr)
        return isLeaf;
    if (node->leftChild != nullptr && node->rightChild == nullptr)
        return hasOnlyLeftChild;
    if (node->leftChild == nullptr && node->rightChild != nullptr)
        return hasOnlyRightChild;

    return hasBothChildren;
}

void Tree::remove(Node *node, Node *parent, Node *parentOfParent, int value)
{
    if (node != nullptr)
    {
        if (value < node->value)
            remove(node->leftChild, node, parent, value);

        else if (value > node->value)
            remove(node->rightChild, node, parent, value);

        else if (node->times == 1)
            switch (nodeType(node))
            {
                case isLeaf:
                    removeLeaf(node, parent, value);
                    break;

                case hasOnlyLeftChild:
                    removeHavingOnlyLeftChild(node, parent, value);
                    break;

                case hasOnlyRightChild:
                    removeHavingOnlyRightChild(node, parent, value);
                    break;

                case hasBothChildren:
                    removeHavingBothChildren(node);
                    break;
            }

        else
        {
            node->times--;
            return;
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
                root = balance(parent);
        }
    }
}

void Tree::removeLeaf(Node *node, Node *parent, int value)
{
    if (parent != nullptr)
    {
        if (parent->value > value)
            parent->leftChild = nullptr;
        else
            parent->rightChild = nullptr;
    }
    else
        root = nullptr;

    delete node;
}

void Tree::removeHavingOnlyLeftChild(Node *node, Node *parent, int value)
{
    if (parent != nullptr)
    {
        if (parent->value > value)
            parent->leftChild = node->leftChild;
        else
            parent->rightChild = node->leftChild;
    }
    else
        root = node->leftChild;

    delete node;
}

void Tree::removeHavingOnlyRightChild(Node *node, Node *parent, int value)
{
    if (parent != nullptr)
    {
        if (parent->value > value)
            parent->leftChild = node->rightChild;
        else
            parent->rightChild = node->rightChild;
    }
    else
        root = node->rightChild;

    delete node;
}

void Tree::removeHavingBothChildren(Node *node)
{
    Node *leftmost = node->rightChild;
    while (leftmost->leftChild != nullptr)
        leftmost = leftmost->leftChild;

    int leftmostValue = leftmost->value;
    int leftmostTimes = leftmost->times;

    for (int i = 0; i < leftmostTimes; i++)
        remove(leftmost->value);

    node->value = leftmostValue;
    node->times = leftmostTimes;
}

int Tree::height(Node *node) const
{
    return node ? node->height : 0;
}

int Tree::balanceFactor(Node *node) const
{
   return height(node->rightChild) - height(node->leftChild);
}

Tree::Node *Tree::balance(Node *node)
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

Tree::Node *Tree::rotateRight(Node *node)
{
   Node *pivot = node->leftChild;

   node->leftChild = pivot->rightChild;
   pivot->rightChild = node;

   updateHeight(node);
   updateHeight(pivot);

   return pivot;
}

Tree::Node *Tree::rotateLeft(Node *node)
{
   Node *pivot = node->rightChild;

   node->rightChild = pivot->leftChild;
   pivot->leftChild = node;

   updateHeight(node);
   updateHeight(pivot);

   return pivot;
}

void Tree::updateHeight(Node *node)
{
   int heightLeft = height(node->leftChild);
   int heightRight = height(node->rightChild);

   node->height = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
}
