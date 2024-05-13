#include "simpleLinkedList.h"

void dispSimpleList(SimpleList *simpleList)
{
    NodeSimpleList *ptr = simpleList->head;

    printf("\n[head] =>");
    while (ptr != NULL)
    {
        printf(" %d =>", ptr->data);
        ptr = ptr->next;
    }

    printf(" [null]\n");
}

void pushSimpleList(int data, SimpleList *simpleList)
{
    NodeSimpleList *link = (NodeSimpleList *)malloc(sizeof(NodeSimpleList));
    if (link == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    link->data = data;
    link->next = NULL;

    if (simpleList->head == NULL)
    {
        simpleList->head = link;
        simpleList->current = simpleList->head;
    }
    else
    {
        simpleList->current->next = link;
        simpleList->current = link;
    }
    simpleList->size++;
}

void popSimpleList(SimpleList *simpleList)
{
    if (simpleList->head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (simpleList->head->next == NULL)
    {
        free(simpleList->head);
        simpleList->head = NULL;
        simpleList->current = NULL;
        simpleList->size = 0;
        return;
    }

    NodeSimpleList *temp = simpleList->head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    simpleList->current = temp;
    simpleList->size--;
}

void cleanSimpleList(SimpleList *simpleList)
{
    while (simpleList->head != NULL)
    {
        popSimpleList(simpleList);
    }

    free(simpleList->head);
    free(simpleList->current);
}

void deletSimpleList(int n, SimpleList *simpleList)
{
    if (n <= 0 || n > simpleList->size)
    {
        printf("Invalid index of element to remove\n");
        return;
    }

    NodeSimpleList *toRemove;
    if (n == 1)
    {
        popSimpleList(simpleList);
        return;
    }

    NodeSimpleList *temp = simpleList->head;
    for (size_t i = 0; i < n - 2; i++)
    {
        temp = temp->next;
    }
    toRemove = temp->next;
    temp->next = temp->next->next;

    free(toRemove);
    simpleList->size--;

    if (simpleList->size == 0)
    {
        simpleList->head = NULL;
        simpleList->current = NULL;
    }
}

void printMenuSimpleList()
{
    printf("\n");
    printf("=========================================\n");
    printf("|      Simple Linked List Operations     |\n");
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

void WriteDataInFileSimpleList(char *string, SimpleList *simpleList)
{
    FILE *ptr_w;

    ptr_w = fopen(string, "w");
    if (ptr_w == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    NodeSimpleList *temp = simpleList->head;
    while (temp != NULL)
    {
        fprintf(ptr_w, "%d\n", temp->data);
        temp = temp->next;
    }

    fclose(ptr_w);
}

void removeFileSimpleList(const char *string)
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

void searchByIndexSimpleList(int n, SimpleList *simpleList)
{
    if (n <= 0 || n > simpleList->size)
    {
        printf("Invalid index\n");
        return;
    }
    NodeSimpleList *temp = simpleList->head;
    for (size_t i = 0; i < n - 1; i++)
    {
        temp = temp->next;
    }
    printf("Node: %d Content: %d\n", n, temp->data);
}

void searchByValueSimpleList(int data, SimpleList *simpleList)
{
    NodeSimpleList *temp = simpleList->head;
    int n = 1;
    while (temp != NULL && temp->data != data)
    {
        temp = temp->next;
        n++;
    }
    if (temp == NULL)
    {
        printf("Value %d doesn't exist in the list\n", data);
    }
    else
    {
        printf("Node: %d  Value: %d\n", n, temp->data);
    }
}

void insertElementSimpleList(int n, int element, SimpleList *simpleList)
{
    if (n < 1 || n > simpleList->size + 1)
    {
        printf("Invalid position\n");
        return;
    }

    NodeSimpleList *newElem = (NodeSimpleList *)malloc(sizeof(NodeSimpleList));
    if (newElem == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newElem->data = element;
    newElem->next = NULL;

    if (n == 1)
    {
        newElem->next = simpleList->head;
        simpleList->head = newElem;
        if (simpleList->size == 0)
            simpleList->current = simpleList->head;
    }
    else
    {
        NodeSimpleList *temp = simpleList->head;
        for (size_t i = 1; i < n - 1; i++)
        {
            temp = temp->next;
        }
        newElem->next = temp->next;
        temp->next = newElem;
        if (n == simpleList->size + 1)
            simpleList->current = newElem;
    }

    simpleList->size++;
}

SimpleList *createSimpleList()
{
    SimpleList *simpleList;
    simpleList->current = NULL;
    simpleList->head = NULL;
    simpleList->size = 0;
    return simpleList;
}
