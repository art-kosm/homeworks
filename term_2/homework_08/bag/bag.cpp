#include "bag.h"

struct Bag::Node
{
    int value;
    int height;
    int times;

    Node *leftChild;
    Node *rightChild;
};

Bag::Bag()
{
    root = nullptr;
}

Bag::~Bag()
{
    while (root != nullptr)
        remove(root->value);
}

void Bag::add(int value)
{
    if (root != nullptr)
        root = addNode(root, value);        //goes for searching...
    else
        root = addNode(value);
}

void Bag::remove(int value)
{
    remove(root, nullptr, nullptr, value);  //goes for searching..
}

bool Bag::contains(int value)
{
    if (root == nullptr)
        return false;

    Node *node = findLastNode(value);

    return value == node->value;
}

Bag::Node *Bag::addNode(int value)
{
    Node *node = new Node;

    node->value = value;
    node->height = 1;
    node->times = 1;

    node->leftChild = nullptr;
    node->rightChild = nullptr;

    return node;
}

Bag::Node *Bag::addNode(Node *node, int value)
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

Bag::Node *Bag::findLastNode(int value)
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

Bag::NodeType Bag::nodeType(Node *node)
{
    if (node->leftChild == nullptr && node->rightChild == nullptr)
        return isLeaf;
    if (node->leftChild != nullptr && node->rightChild == nullptr)
        return hasOnlyLeftChild;
    if (node->leftChild == nullptr && node->rightChild != nullptr)
        return hasOnlyRightChild;

    return hasBothChildren;
}

void Bag::remove(Node *node, Node *parent, Node *parentOfParent, int value)
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

void Bag::removeLeaf(Node *node, Node *parent, int value)
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

void Bag::removeHavingOnlyLeftChild(Node *node, Node *parent, int value)
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

void Bag::removeHavingOnlyRightChild(Node *node, Node *parent, int value)
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

void Bag::removeHavingBothChildren(Node *node)
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

int Bag::height(Node *node)
{
    return node ? node->height : 0;
}

int Bag::balanceFactor(Node *node)
{
   return height(node->rightChild) - height(node->leftChild);
}

Bag::Node *Bag::balance(Node *node)
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

Bag::Node *Bag::rotateRight(Node *node)
{
   Node *pivot = node->leftChild;

   node->leftChild = pivot->rightChild;
   pivot->rightChild = node;

   updateHeight(node);
   updateHeight(pivot);

   return pivot;
}

Bag::Node *Bag::rotateLeft(Node *node)
{
   Node *pivot = node->rightChild;

   node->rightChild = pivot->leftChild;
   pivot->leftChild = node;

   updateHeight(node);
   updateHeight(pivot);

   return pivot;
}

void Bag::updateHeight(Node *node)
{
   int heightLeft = height(node->leftChild);
   int heightRight = height(node->rightChild);

   node->height = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
}
