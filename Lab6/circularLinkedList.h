#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_STR 100

typedef struct NodeCircularList
{
    int data;
    struct NodeCircularList *next;
    struct NodeCircularList *prev;
} NodeCircularList;

typedef struct CircularList
{
    NodeCircularList *head;
    NodeCircularList *current;
    int size;
} CircularList;

CircularList *createCircularList();
void dispCircularList(CircularList *circularList);
void pushCircularList(int data, CircularList *circularList);
void popCircularList(CircularList *circularList);
void cleanCircularList(CircularList *circularList);
void deletCircularList(int n, CircularList *circularList);
void printMenuCircularList();
void WriteDataInFileCircularList(char *string, CircularList *circularList);
void removeFileCircularList(const char *string);
void searchByIndexCircularList(int n, CircularList *circularList);
void searchByValueCircularList(int data, CircularList *circularList);
void insertElementCircularList(int n, int element, CircularList *circularList);

#endif