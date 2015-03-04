#pragma once

struct String;

String *createString();
String *createString(char str[]);
String *clone(String *string);
String *concatenate(String *string1, String *string2);
bool equals(String *string1, String *string2);
int length(String *string);
bool isEmpty(String *string);
String *substring(String *string, int start, int end);
char *toCharArray(String *string);
void deleteString(String *string);
