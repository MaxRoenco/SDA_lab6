#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_STR 100

typedef struct StackElem
{
    char *string;
    int length;
    struct StackElem *prev;
} StackElem;

typedef struct Stack
{
    StackElem *tp;
    int number;
} Stack;

void dispStack(Stack s);

void pushStack(Stack *s, char *string);

char *popStack(Stack *s);

void deletStack(Stack *s, int n);

void searchByIndexStack(Stack *s, int n);

void searchByValueStack(Stack *s, char *string);

void insertElementStack(Stack *s, int n, char *string);

void WriteDataInFileStack(Stack *s, char *string);

void removeFileStack(const char *string);

void InitialiseStack(Stack *s);

void printMenuStack();

int mainStack();

#endif