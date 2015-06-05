#pragma once

/**
 * @brief The Tree class
 *
 * An AVL tree with nodes containing a times counter
 */

class Tree
{
public:

    /**
     * @brief Tree constructor
     *
     * Assigns nullptr to root
     */

    Tree();

    /**
     * @brief Tree destructor
     *
     * Removes the root value until the bag is empty
     */

    ~Tree();

    /**
     * @brief Value adder
     *
     * Adds the value with addNode(Node*, int)
     * If the value is presented, just increments its times counter
     * After the value is added, balances the tree
     *
     * @param value
     */

    void add(int value);

    /**
     * @brief Value remover
     *
     * Removes the value with remove(Node*, Node*, Node*, int)
     * If the value is presented more than once, just decrements
     * its times counter
     *
     * @param value
     */

    void remove(int value);

    bool contains(int value) const;

private:
    struct Node;
    Node *addNode(int value);

    /**
     * @brief Node adder
     *
     * Recursively searches for the node which value is the closest
     * to the value needed, if the node is not presented, adds the node
     * with addNode(int), increases its counter otherwise
     *
     * @param node
     * @param value
     * @return The new node
     */

    Node *addNode(Node *node, int value);

    /**
     * @brief Node finder
     *
     * Recursively searches for the node which value is the closest
     * to the value needed
     *
     * @param value
     * @return The found node
     */

    Node *findLastNode(int value) const;

    Node *root;

    enum NodeType
    {
        isLeaf,
        hasOnlyLeftChild,
        hasOnlyRightChild,
        hasBothChildren
    };

    NodeType nodeType(Node *node) const;

    /**
     * @brief Value remover
     *
     * Recursively searches for the node which value is the closest
     * to the value needed, if the node with this value is presented
     * only once, checks its type and accurately removes the node,
     * if more than once -- decrements its times counter
     * After removing the node balances the tree
     *
     * @param node
     * @param parent
     * @param parentOfParent
     * @param value
     */

    void remove(Node *node, Node *parent, Node *parentOfParent, int value);

    void removeLeaf(Node *node, Node *parent, int value);
    void removeHavingOnlyLeftChild(Node *node, Node *parent, int value);
    void removeHavingOnlyRightChild(Node *node, Node *parent, int value);
    void removeHavingBothChildren(Node *node);

    int height(Node *node) const;
    int balanceFactor(Node *node) const;

    ///Standard AVL tree balance functions

    Node *balance(Node *node);
    Node *rotateRight(Node *node);
    Node *rotateLeft(Node *node);
    void updateHeight(Node *node);
};
