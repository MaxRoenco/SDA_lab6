#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_STR 100

typedef struct NodeDoubleLink
{
    int data;
    struct NodeDoubleLink *next;
    struct NodeDoubleLink *prev;
} NodeDoubleLink;

typedef struct DoubleLink
{
    NodeDoubleLink *head;
    NodeDoubleLink *current;
    int size;
} DoubleLink;

DoubleLink *createDoubleList();
void dispDoubleList(DoubleLink *doubleList);
void pushDoubleList(int data, DoubleLink *doubleList);
void popDoubleList(DoubleLink *doubleList);
void cleanDoubleList(DoubleLink *doubleList);
void deletDoubleList(int n, DoubleLink *doubleList);
void printMenuDoubleList();
void WriteDataInFileDoubleList(char *string, DoubleLink *doubleList);
void removeFileDoubleList(const char *string);
void searchByIndexDoubleList(int n, DoubleLink *doubleList);
void searchByValueDoubleList(int data, DoubleLink *doubleList);
void insertElementDoubleList(int n, int element, DoubleLink *doubleList);

#endif