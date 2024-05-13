#ifndef SIMPLELINKEDLIST_H
#define SIMPLELINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_STR 100

typedef struct NodeSimpleList
{
    int data;
    struct NodeSimpleList *next;
} NodeSimpleList;

typedef struct SimpleList
{
    NodeSimpleList *head;
    NodeSimpleList *current;
    int size;
} SimpleList;

SimpleList *createSimpleList();
void dispSimpleList(SimpleList *simpleList);
void popSimpleList(SimpleList *simpleList);
void cleanSimpleList(SimpleList *simpleList);
void deletSimpleList(int n, SimpleList *simpleList);
void printMenuSimpleList();
void WriteDataInFileSimpleList(char *string, SimpleList *simpleList);
void removeFileSimpleList(const char *string);
void searchByIndexSimpleList(int n, SimpleList *simpleList);
void searchByValueSimpleList(int data, SimpleList *simpleList);
void insertElementSimpleList(int n, int element, SimpleList *simpleList);
void pushSimpleList(int data, SimpleList *simpleList);

#endif