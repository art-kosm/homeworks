#pragma once

struct StackElement;
struct Stack;

Stack *createStack();
void push(Stack *stack, char value);
char pop(Stack *stack);
void deleteStack(Stack *stack);
bool isEmpty(Stack *stack);
char getTopValue(Stack *stack);
bool contains(Stack *stack, char value);
