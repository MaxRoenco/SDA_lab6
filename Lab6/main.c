#include "stack.h"
#include "queue.h"
#include "simpleLinkedList.h"
#include "doubleLinkedList.h"
#include "circularLinkedList.h"

void printMenuMain()
{
    printf("\n");
    printf("=========================================\n");
    printf("|               Operations               |\n");
    printf("=========================================\n");
    printf("| 1. Stack                               |\n");
    printf("| 2. Queue                               |\n");
    printf("| 3. Simple Linked List                  |\n");
    printf("| 4. Double Linked List                  |\n");
    printf("| 5. Circular Linked List                |\n");
    printf("| 6. Exit                                |\n");
    printf("=========================================\n");
}

int main()
{
    int k;
    int choice;
    int n;
    char buffer[BUFFER_STR];
    int element;
    CircularList *circularList = createCircularList();
    DoubleLink *doubleList = createDoubleList();
    SimpleList *simpleList = createSimpleList();
    Queue *queue = createQueue();
    Stack s;
    do
    {
        printMenuMain();
        scanf("%d", &k);
        switch (k)
        {
        case 1:
            InitialiseStack(&s);
            do
            {
                printMenuStack();
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("Input string which you want to add: ");
                    getchar();
                    fgets(buffer, BUFFER_STR, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    pushStack(&s, buffer);
                    printf("'%s' pushed onto the stack.\n", buffer);
                    break;
                case 2:
                    if (s.tp == NULL)
                    {
                        printf("Stack is empty.\n");
                    }
                    else
                    {
                        printf("Popped element: %s\n", popStack(&s));
                    }
                    break;
                case 3:
                    dispStack(s);
                    break;
                case 4:
                    printf("Input element which you want to remove: ");
                    scanf("%d", &n);
                    deletStack(&s, n);
                    break;
                case 5:
                    printf("Input index of element which you want to search: ");
                    scanf("%d", &n);
                    searchByIndexStack(&s, n);
                    break;
                case 6:
                    printf("Input value of element which you want to search: ");
                    getchar();
                    fgets(buffer, BUFFER_STR, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    searchByValueStack(&s, buffer);
                    break;
                case 7:
                    printf("Input index of element which you want to insert: ");
                    scanf("%d", &n);
                    printf("Input value of element which you want to insert: ");
                    getchar();
                    fgets(buffer, BUFFER_STR, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    insertElementStack(&s, n, buffer);
                    break;
                case 8:
                    printf("Input path to file: ");
                    getchar();
                    fgets(buffer, BUFFER_STR, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    WriteDataInFileStack(&s, buffer);
                    break;
                case 9:
                    printf("Input file which you want to delete: ");
                    getchar();
                    fgets(buffer, BUFFER_STR, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    removeFileStack(buffer);
                    break;
                case 10:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Invalid choice. Please enter a number between 1 and 8.\n");
                }
            } while (choice != 10);
            break;
        case 2:
            do
            {
                printMenuQueue();
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("Input string which you want to add: ");
                    getchar();
                    fgets(buffer, BUFFER_STR, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    pushQueue(queue, buffer);
                    printf("'%s' pushed onto the stack.\n", buffer);
                    break;
                case 2:
                    if (queue->head == NULL)
                    {
                        printf("Stack is empty.\n");
                    }
                    else
                    {
                        printf("Popped element: %s\n", queue->head->string);
                        popQueue(queue);
                    }
                    break;
                case 3:
                    dispQueue(queue);
                    break;
                case 4:
                    printf("Input element which you want to remove: ");
                    scanf("%d", &n);
                    deletQueue(queue, n);
                    break;
                case 5:
                    printf("Input index of element which you want to search: ");
                    scanf("%d", &n);
                    searchByIndexQueue(queue, n);
                    break;
                case 6:
                    printf("Input value of element which you want to search: ");
                    getchar();
                    fgets(buffer, BUFFER_STR, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    searchByValueQueue(queue, buffer);
                    break;
                case 7:
                    printf("Input index of element which you want to insert: ");
                    scanf("%d", &n);
                    printf("Input value of element which you want to insert: ");
                    getchar();
                    fgets(buffer, BUFFER_STR, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    insertElementQueue(queue, n, buffer);
                    break;
                case 8:
                    printf("Input path to file: ");
                    getchar();
                    fgets(buffer, BUFFER_STR, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    WriteDataInFileQueue(queue, buffer);
                    break;
                case 9:
                    printf("Input file which you want to delete: ");
                    getchar();
                    fgets(buffer, BUFFER_STR, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    removeFileQueue(buffer);
                    break;
                case 10:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Invalid choice. Please enter a number between 1 and 8.\n");
                }
            } while (choice != 10);
            break;
        case 3:
            do
            {
                printMenuSimpleList();
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("Input number which you want to add: ");
                    scanf("%d", &n);
                    pushSimpleList(n, simpleList);
                    printf("'%d' pushed onto the linked list.\n", n);
                    break;
                case 2:
                    if (simpleList->head == NULL)
                    {
                        printf("Stack is empty.\n");
                    }
                    else
                    {
                        printf("Popped element: %d\n", simpleList->current->data);
                        popSimpleList(simpleList);
                    }
                    break;
                case 3:
                    dispSimpleList(simpleList);
                    break;
                case 4:
                    printf("Input element which you want to remove: ");
                    scanf("%d", &n);
                    deletSimpleList(n, simpleList);
                    break;
                case 5:
                    printf("Input index of element which you want to search: ");
                    scanf("%d", &n);
                    searchByIndexSimpleList(n, simpleList);
                    break;
                case 6:
                    printf("Input value of element which you want to search: ");
                    scanf("%d", &n);
                    searchByValueSimpleList(n, simpleList);
                    break;
                case 7:
                    printf("Input index of element which you want to insert: ");
                    scanf("%d", &n);
                    printf("Input value of element which you want to insert: ");
                    scanf("%d", &element);
                    insertElementSimpleList(n, element, simpleList);
                    break;
                case 8:
                    printf("Input path to file: ");
                    getchar();
                    fgets(buffer, BUFFER_STR, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    WriteDataInFileSimpleList(buffer, simpleList);
                    break;
                case 9:
                    printf("Input file which you want to delete: ");
                    getchar();
                    fgets(buffer, BUFFER_STR, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    removeFileSimpleList(buffer);
                    break;
                case 10:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Invalid choice. Please enter a number between 1 and 8.\n");
                }
            } while (choice != 10);
            break;
        case 4:
            do
            {
                printMenuDoubleList();
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("Input number which you want to add: ");
                    scanf("%d", &n);
                    pushDoubleList(n, doubleList);
                    printf("'%d' pushed onto the linked list.\n", n);
                    break;
                case 2:
                    if (doubleList->head == NULL)
                    {
                        printf("Stack is empty.\n");
                    }
                    else
                    {
                        printf("Popped element: %d\n", doubleList->current->data);
                        popDoubleList(doubleList);
                    }
                    break;
                case 3:
                    dispDoubleList(doubleList);
                    break;
                case 4:
                    printf("Input element which you want to remove: ");
                    scanf("%d", &n);
                    deletDoubleList(n, doubleList);
                    break;
                case 5:
                    printf("Input index of element which you want to search: ");
                    scanf("%d", &n);
                    searchByIndexDoubleList(n, doubleList);
                    break;
                case 6:
                    printf("Input value of element which you want to search: ");
                    scanf("%d", &n);
                    searchByValueDoubleList(n, doubleList);
                    break;
                case 7:
                    printf("Input index of element which you want to insert: ");
                    scanf("%d", &n);
                    printf("Input value of element which you want to insert: ");
                    scanf("%d", &element);
                    insertElementDoubleList(n, element, doubleList);
                    break;
                case 8:
                    printf("Input path to file: ");
                    getchar();
                    fgets(buffer, BUFFER_STR, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    WriteDataInFileDoubleList(buffer, doubleList);
                    break;
                case 9:
                    printf("Input file which you want to delete: ");
                    getchar();
                    fgets(buffer, BUFFER_STR, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    removeFileDoubleList(buffer);
                    break;
                case 10:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Invalid choice. Please enter a number between 1 and 8.\n");
                }
            } while (choice != 10);
            break;
        case 5:
            do
            {
                printMenuCircularList();
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("Input number which you want to add: ");
                    scanf("%d", &n);
                    pushCircularList(n, circularList);
                    printf("'%d' pushed onto the linked list.\n", n);
                    break;
                case 2:
                    if (circularList->head == NULL)
                    {
                        printf("Circular list is empty.\n");
                    }
                    else
                    {
                        printf("Popped element: %d\n", circularList->current->data);
                        popCircularList(circularList);
                    }
                    break;
                case 3:
                    dispCircularList(circularList);
                    break;
                case 4:
                    printf("Input element which you want to remove: ");
                    scanf("%d", &n);
                    deletCircularList(n, circularList);
                    break;
                case 5:
                    printf("Input index of element which you want to search: ");
                    scanf("%d", &n);
                    searchByIndexCircularList(n, circularList);
                    break;
                case 6:
                    printf("Input value of element which you want to search: ");
                    scanf("%d", &n);
                    searchByValueCircularList(n, circularList);
                    break;
                case 7:
                    printf("Input index of element which you want to insert: ");
                    scanf("%d", &n);
                    printf("Input value of element which you want to insert: ");
                    scanf("%d", &element);
                    insertElementCircularList(n, element, circularList);
                    break;
                case 8:
                    printf("Input path to file: ");
                    getchar();
                    fgets(buffer, BUFFER_STR, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    WriteDataInFileCircularList(buffer, circularList);
                    break;
                case 9:
                    printf("Input file which you want to delete: ");
                    getchar();
                    fgets(buffer, BUFFER_STR, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    removeFileCircularList(buffer);
                    break;
                case 10:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Invalid choice. Please enter a number between 1 and 8.\n");
                }
            } while (choice != 10);
            break;
        default:
            printf("Invalid value");
            break;
        }
    } while (k != 6);
}