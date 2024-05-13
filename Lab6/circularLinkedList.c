#include "circularLinkedList.h"

void dispCircularList(CircularList *circularList)
{
    if (circularList->head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    NodeCircularList *ptr = circularList->head;
    printf("\n[head] =>");
    do
    {
        printf(" %d =>", ptr->data);
        ptr = ptr->next;
    } while (ptr != circularList->head);

    printf(" [head]\n");
}

void pushCircularList(int data, CircularList *circularList)
{
    NodeCircularList *link = (NodeCircularList *)malloc(sizeof(NodeCircularList));
    if (link == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    link->data = data;
    link->prev = circularList->current;

    if (circularList->head == NULL)
    {
        circularList->head = link;
        link->next = circularList->head;
    }
    else
    {
        circularList->current->next = link;
        link->next = circularList->head;
    }
    circularList->head->prev = link;
    circularList->current = link;
    circularList->size++;
}

void popCircularList(CircularList *circularList)
{
    if (circularList->head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (circularList->head->next == circularList->head)
    {
        free(circularList->head);
        circularList->head = NULL;
        circularList->current = NULL;
    }
    else
    {
        NodeCircularList *temp = circularList->current;
        circularList->current = circularList->current->prev;
        circularList->current->next = circularList->head;
        circularList->head->prev = circularList->current;
        free(temp);
    }
    circularList->size--;

    if (circularList->size == 0)
    {
        circularList->head = NULL;
        circularList->current = NULL;
    }
}

void cleanCircularList(CircularList *circularList)
{
    while (circularList->head != NULL)
    {
        popCircularList(circularList);
    }

    free(circularList->head);
    free(circularList->current);
}

void deletCircularList(int n, CircularList *circularList)
{
    if (n <= 0 || n > circularList->size)
    {
        printf("Invalid index of element to remove\n");
        return;
    }

    NodeCircularList *toRemove;
    if (n == 1)
    {
        popCircularList(circularList);
        return;
    }

    NodeCircularList *temp = circularList->head;
    for (size_t i = 0; i < n - 1; i++)
    {
        temp = temp->next;
    }

    if (temp->next == circularList->head)
    {
        circularList->head = circularList->head->next;
        circularList->head->prev = temp->prev;
    }

    toRemove = temp;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(toRemove);
    circularList->size--;

    if (circularList->size == 0)
    {
        circularList->head = NULL;
        circularList->current = NULL;
    }
}

void printMenuCircularList()
{
    printf("\n");
    printf("=========================================\n");
    printf("|     Circular Linked List Operations    |\n");
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

void WriteDataInFileCircularList(char *string, CircularList *circularList)
{
    FILE *ptr_w;

    ptr_w = fopen(string, "w");
    if (ptr_w == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    NodeCircularList *temp = circularList->head;
    do
    {
        fprintf(ptr_w, "%d\n", temp->data);
        temp = temp->next;
    } while (temp != circularList->head);

    fclose(ptr_w);
}

void removeFileCircularList(const char *string)
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

void searchByIndexCircularList(int n, CircularList *circularList)
{
    if (n <= 0 || n > circularList->size)
    {
        printf("Invalid index\n");
        return;
    }
    NodeCircularList *temp = circularList->head;
    for (size_t i = 0; i < n - 1; i++)
    {
        temp = temp->next;
    }
    printf("Node: %d Content: %d\n", n, temp->data);
}

void searchByValueCircularList(int data, CircularList *circularList)
{
    NodeCircularList *temp = circularList->head;
    int n = 1;
    if (temp != NULL)
    {
        do
        {
            if (temp->data == data)
            {
                printf("Node: %d  Value: %d\n", n, temp->data);
                return;
            }
            temp = temp->next;
            n++;
        } while (temp != circularList->head);
    }

    printf("Value %d doesn't exist in the list\n", data);
}

void insertElementCircularList(int n, int element, CircularList *circularList)
{
    NodeCircularList *newnode, *curNode;
    int i;

    if (circularList->head == NULL)
    {
        printf("List is empty");
    }
    if (n == 1)
    {
        pushCircularList(element, circularList);
        return;
    }
    else
    {
        newnode = (NodeCircularList *)malloc(sizeof(NodeCircularList));
        newnode->data = element;
        curNode = circularList->head;
        while (--n > 1)
        {
            curNode = curNode->next;
        }
        newnode->next = curNode->next;
        curNode->next = newnode;
    }
}

CircularList *createCircularList()
{
    CircularList *circularList;
    circularList->current = NULL;
    circularList->head = NULL;
    circularList->size = 0;
    return circularList;
}