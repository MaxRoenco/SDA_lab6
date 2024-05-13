#include "stack.h"

void dispStack(Stack s)
{
    printf("\nStack contents:\n");
    int i = 0;
    StackElem *temp = s.tp;
    while (temp != NULL)
    {
        printf("Node %d: %s\n", i + 1, temp->string);
        temp = temp->prev;
        i++;
    }
}

void pushStack(Stack *s, char *string)
{
    StackElem *e = (StackElem *)malloc(sizeof(StackElem));
    e->prev = s->tp;
    s->tp = e;
    s->tp->length = strlen(string);
    s->tp->string = (char *)malloc(sizeof(char) * s->tp->length);
    strcpy(s->tp->string, string);
    s->number++;
}

char *popStack(Stack *s)
{
    if (s->tp == NULL)
    {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    char *string = s->tp->string;
    StackElem *temp = s->tp;
    s->tp = s->tp->prev;
    free(temp);
    s->number--;
    return string;
}

void deletStack(Stack *s, int n)
{
    if (n <= 0 || n > s->number)
    {
        printf("Invalid number of elements to remove\n");
        return;
    }

    StackElem *toRemove;
    if (n == 1)
    {
        toRemove = s->tp;
        s->tp = s->tp->prev;
    }
    else
    {
        StackElem *temp = s->tp;
        for (size_t i = 0; i < n - 2; i++)
        {
            temp = temp->prev;
        }
        toRemove = temp->prev;
        temp->prev = temp->prev->prev;
    }

    free(toRemove->string);
    free(toRemove);
    s->number--;
}

void searchByIndexStack(Stack *s, int n)
{
    if (n <= 0 || n > s->number)
    {
        printf("Invalid number of elements to remove\n");
        return;
    }
    StackElem *temp = s->tp;
    for (size_t i = 0; i < n - 1; i++)
    {
        temp = temp->prev;
    }
    printf("Node: %d Content: %s", n, temp->string);
}

void searchByValueStack(Stack *s, char *string)
{
    StackElem *temp = s->tp;
    int n = 1;
    while (temp != NULL && strcmp(temp->string, string) != 0)
    {
        temp = temp->prev;
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

void insertElementStack(Stack *s, int n, char *string)
{
    StackElem *newElem = (StackElem *)malloc(sizeof(StackElem));
    StackElem *temp = s->tp;
    if (n == 1)
    {
        pushStack(s, string);
        return;
    }
    else
    {
        for (size_t i = 0; i < n - 2; i++)
        {
            temp = temp->prev;
        }
        newElem->prev = temp->prev;
        temp->prev = newElem;
        newElem->length = strlen(string);
        newElem->string = (char *)malloc(sizeof(char) * newElem->length + 1);
        strcpy(newElem->string, string);
        s->number++;
        return;
    }
}

void WriteDataInFileStack(Stack *s, char *string)
{
    FILE *ptr_w;

    ptr_w = fopen(string, "w");
    if (ptr_w == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    StackElem *temp = s->tp;
    while (temp != NULL)
    {
        fprintf(ptr_w, "%s\n", temp->string);
        temp = temp->prev;
    }

    fclose(ptr_w);
}

void removeFileStack(const char *string)
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

void InitialiseStack(Stack *s)
{
    s->tp = NULL;
    s->number = 0;
}

void printMenuStack()
{
    printf("\n");
    printf("=========================================\n");
    printf("|            Stack Operations            |\n");
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
