#pragma once

struct StackElement;
struct Stack;

Stack *createStack();
void push(Stack *stack, int startValue, int endValue, int distance);
void pop(Stack *stack);
void deleteStack(Stack *stack);
bool isEmpty(Stack *stack);
int getTopStartValue(Stack *stack);
int getTopEndValue(Stack *stack);
int getTopDistance(Stack *stack);
