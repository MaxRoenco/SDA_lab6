#include "queue.h"

void dispQueue(Queue *queue)
{
    printf("\nStack contents:\n");
    int i = 0;
    NodeQueue *temp = queue->head;
    while (temp != NULL)
    {
        printf("Node %d: %s\n", i + 1, temp->string);
        temp = temp->next;
        i++;
    }
}

Queue *createQueue()
{
    Queue *queue = malloc(sizeof(Queue));

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

void pushQueue(Queue *queue, char *string)
{
    NodeQueue *newNode = (NodeQueue *)malloc(sizeof(NodeQueue));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->string = malloc(strlen(string) + 1);
    if (newNode->string == NULL)
    {
        printf("Memory allocation failed\n");
        free(newNode);
        return;
    }

    strcpy(newNode->string, string);
    newNode->next = NULL;

    if (queue->size == 0)
    {
        queue->head = newNode;
        queue->tail = newNode;
    }
    else
    {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }

    queue->size++;
}

void popQueue(Queue *queue)
{
    if (queue->size == 0)
    {
        printf("Queue is empty");
        return;
    }
    NodeQueue *temp = queue->head;
    queue->head = queue->head->next;
    free(temp->string);
    free(temp);
    queue->size--;
}

void cleanQueue(Queue *queue)
{
    while (queue->size > 0)
    {
        popQueue(queue);
    }

    free(queue);
}

void deletQueue(Queue *queue, int n)
{
    if (n <= 0 || n > queue->size)
    {
        printf("Invalid number of elements to remove\n");
        return;
    }

    NodeQueue *toRemove;
    if (n == 1)
    {
        toRemove = queue->head;
        queue->head = queue->head->next;
    }
    else
    {
        NodeQueue *temp = queue->head;
        for (size_t i = 0; i < n - 2; i++)
        {
            temp = temp->next;
        }
        toRemove = temp->next;
        temp->next = temp->next->next;
    }

    free(toRemove->string);
    free(toRemove);
    queue->size--;

    if (queue->size == 0)
    {
        queue->head = NULL;
        queue->tail = NULL;
    }
}

void searchByIndexQueue(Queue *queue, int n)
{
    if (n <= 0 || n > queue->size)
    {
        printf("Invalid number of elements to remove\n");
        return;
    }
    NodeQueue *temp = queue->head;
    for (size_t i = 0; i < n - 1; i++)
    {
        temp = temp->next;
    }
    printf("Node: %d Content: %s", n, temp->string);
}

void searchByValueQueue(Queue *queue, char *string)
{
    NodeQueue *temp = queue->head;
    int n = 1;
    while (temp != NULL && strcmp(temp->string, string) != 0)
    {
        temp = temp->next;
        n++;
    }
    if (temp == NULL)
    {
        printf("This value doesn't exist in our Stack\n");
    }
    else
    {
        printf("Node: %d  Value: %s\n", n, temp->string);
    }
}

void insertElementQueue(Queue *queue, int n, char *string)
{
    if (n < 1 || n > queue->size + 1)
    {
        printf("Invalid position\n");
        return;
    }

    NodeQueue *newElem = (NodeQueue *)malloc(sizeof(NodeQueue));
    if (newElem == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newElem->string = (char *)malloc((strlen(string) + 1) * sizeof(char));
    if (newElem->string == NULL)
    {
        printf("Memory allocation failed\n");
        free(newElem);
        return;
    }

    strcpy(newElem->string, string);
    newElem->length = strlen(string);
    newElem->next = NULL;

    if (n == 1)
    {
        newElem->next = queue->head;
        queue->head = newElem;
        if (queue->size == 0)
            queue->tail = newElem;
    }
    else
    {
        NodeQueue *temp = queue->head;
        for (size_t i = 1; i < n - 1; i++)
        {
            temp = temp->next;
        }
        newElem->next = temp->next;
        temp->next = newElem;
        if (n == queue->size + 1)
            queue->tail = newElem;
    }

    queue->size++;
}

void printMenuQueue()
{
    printf("\n");
    printf("=========================================\n");
    printf("|            Queue Operations            |\n");
    printf("=========================================\n");
    printf("| 1. Push                                |\n");
    printf("| 2. Pop                                 |\n");
    printf("| 3. Display Stack                       |\n");
    printf("| 4. Remove element                      |\n");
    printf("| 5. Search element by index             |\n");
    printf("| 6. Search element by value             |\n");
    printf("| 7. Insert Node                         |\n");
    printf("| 8. Write Data in File                  |\n");
    printf("| 9. Delete File                         |\n");
    printf("| 10. Quit                               |\n");
    printf("=========================================\n");
}

void WriteDataInFileQueue(Queue *queue, char *string)
{
    FILE *ptr_w;

    ptr_w = fopen(string, "w");
    if (ptr_w == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    NodeQueue *temp = queue->head;
    while (temp != NULL)
    {
        fprintf(ptr_w, "%s\n", temp->string);
        temp = temp->next;
    }

    fclose(ptr_w);
}

void removeFileQueue(const char *string)
{
    if (remove(string) == 0)
    {
        printf("File '%s' removed successfully.\n", string);
    }
    else
    {
        printf("Unable to remove file '%s'.\n", string);
    }
}
