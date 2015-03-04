#pragma once

struct BinaryExpressionTree;

BinaryExpressionTree *makeTreeFromFile(char *path);
void printPreorder(BinaryExpressionTree *tree);
int compute(BinaryExpressionTree *tree);
void deleteTree(BinaryExpressionTree *tree);
