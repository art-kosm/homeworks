#pragma once

struct StackElement;
struct Stack;

Stack *createStack();
void push(Stack *stack, double value);
double pop(Stack *stack);
void deleteStack(Stack *stack);
bool isEmpty(Stack *stack);
double getTopValue(Stack *stack);

