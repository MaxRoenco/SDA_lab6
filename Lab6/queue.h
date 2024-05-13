#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_STR 100

typedef struct NodeQueue
{
    char *string;
    int length;
    struct NodeQueue *next;
} NodeQueue;

typedef struct Queue
{
    NodeQueue *head;
    NodeQueue *tail;
    int size;
} Queue;

void dispQueue(Queue *queue);
Queue *createQueue();
void pushQueue(Queue *queue, char *string);
void popQueue(Queue *queue);
void cleanQueue(Queue *queue);
void deletQueue(Queue *queue, int n);
void searchByIndexQueue(Queue *queue, int n);
void searchByValueQueue(Queue *queue, char *string);
void printMenuQueue();
void WriteDataInFileQueue(Queue *queue, char *string);
void removeFileQueue(const char *string);
void insertElementQueue(Queue *queue, int n, char *string);

#endif