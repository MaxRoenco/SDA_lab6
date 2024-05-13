#include "doubleLinkedList.h"

void dispDoubleList(DoubleLink *doubleList)
{

    NodeDoubleLink *ptr = doubleList->head;

    printf("\n[head] =>");
    while (ptr != NULL)
    {
        printf(" %d =>", ptr->data);
        ptr = ptr->next;
    }

    printf(" [null]\n");
}

void pushDoubleList(int data, DoubleLink *doubleList)
{
    NodeDoubleLink *link = (NodeDoubleLink *)malloc(sizeof(NodeDoubleLink));
    if (link == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    link->data = data;
    link->next = NULL;
    link->prev = doubleList->current;

    if (doubleList->head == NULL)
    {
        doubleList->head = link;
        doubleList->current = doubleList->head;
    }
    else
    {
        doubleList->current->next = link;
        doubleList->current = link;
    }
    doubleList->size++;
}

void popDoubleList(DoubleLink *doubleList)
{
    if (doubleList->head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (doubleList->head->next == NULL)
    {
        free(doubleList->head);
        doubleList->head = NULL;
        doubleList->current = NULL;
        doubleList->size = 0;
        return;
    }

    NodeDoubleLink *temp = doubleList->current;
    doubleList->current = doubleList->current->prev;
    doubleList->current->next = NULL;
    free(temp);
    doubleList->size--;

    if (doubleList->size == 0)
    {
        doubleList->head = NULL;
        doubleList->current = NULL;
    }
}

void cleanDoubleList(DoubleLink *doubleList)
{
    while (doubleList->head != NULL)
    {
        popDoubleList(doubleList);
    }

    free(doubleList->head);
    free(doubleList->current);
}

void deletDoubleList(int n, DoubleLink *doubleList)
{
    if (n <= 0 || n > doubleList->size)
    {
        printf("Invalid index of element to remove\n");
        return;
    }

    NodeDoubleLink *toRemove;
    if (n == 1)
    {
        popDoubleList(doubleList);
        return;
    }

    NodeDoubleLink *temp = doubleList->head;
    for (size_t i = 0; i < n - 2; i++)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("Invalid index of element to remove\n");
        return;
    }

    toRemove = temp->next;
    temp->next = temp->next->next;

    free(toRemove);
    doubleList->size--;

    if (doubleList->size == 0)
    {
        doubleList->head = NULL;
        doubleList->current = NULL;
    }
}

void printMenuDoubleList()
{
    printf("\n");
    printf("=========================================\n");
    printf("|     Double Linked List Operations      |\n");
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

void WriteDataInFileDoubleList(char *string, DoubleLink *doubleList)
{
    FILE *ptr_w;

    ptr_w = fopen(string, "w");
    if (ptr_w == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    NodeDoubleLink *temp = doubleList->head;
    while (temp != NULL)
    {
        fprintf(ptr_w, "%d\n", temp->data);
        temp = temp->next;
    }

    fclose(ptr_w);
}

void removeFileDoubleList(const char *string)
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

void searchByIndexDoubleList(int n, DoubleLink *doubleList)
{
    if (n <= 0 || n > doubleList->size)
    {
        printf("Invalid index\n");
        return;
    }
    NodeDoubleLink *temp = doubleList->head;
    for (size_t i = 0; i < n - 1; i++)
    {
        temp = temp->next;
    }
    printf("Node: %d Content: %d\n", n, temp->data);
}

void searchByValueDoubleList(int data, DoubleLink *doubleList)
{
    NodeDoubleLink *temp = doubleList->head;
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

void insertElementDoubleList(int n, int element, DoubleLink *doubleList)
{
    if (n < 1 || n > doubleList->size + 1)
    {
        printf("Invalid position\n");
        return;
    }

    NodeDoubleLink *newElem = (NodeDoubleLink *)malloc(sizeof(NodeDoubleLink));
    if (newElem == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newElem->data = element;
    newElem->next = NULL;

    if (n == 1)
    {
        newElem->next = doubleList->head;
        doubleList->head = newElem;
        if (doubleList->size == 0)
            doubleList->current = doubleList->head;
    }
    else
    {
        NodeDoubleLink *temp = doubleList->head;
        for (size_t i = 1; i < n - 1; i++)
        {
            temp = temp->next;
        }
        newElem->next = temp->next;
        temp->next = newElem;
        if (n == doubleList->size + 1)
            doubleList->current = newElem;
    }

    doubleList->size++;
}

DoubleLink *createDoubleList()
{
    DoubleLink *doubleList;
    doubleList->current = NULL;
    doubleList->head = NULL;
    doubleList->size = 0;
}
