#pragma once

struct BinarySearchTree;

BinarySearchTree *createTree();
BinarySearchTree *createTree(int value);
bool contains(BinarySearchTree *tree, int value);
int root(BinarySearchTree *tree);
void addValue(BinarySearchTree *tree, int value);
void removeValue(BinarySearchTree *tree, int value);
void printPreorder(BinarySearchTree *tree);
void printAscending(BinarySearchTree *tree);
void printDescending(BinarySearchTree *tree);
void printPostorder(BinarySearchTree *tree);
void deleteTree(BinarySearchTree *tree);
