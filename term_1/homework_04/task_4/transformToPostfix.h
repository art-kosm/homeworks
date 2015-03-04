#pragma once

void addToString(char string[], int position, char value);
bool isOperator(char token);
int getPriority(char token);
void transformToPostfix(char input[], char output[]);
