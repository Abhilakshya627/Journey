#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
} sl;

sl *createNode(int);
void insertAtBeginning(sl **, int);
void insertAtEnd(sl **, int);
void insertAtPosition(sl **, int, int);

int main()
{
    sl *p = NULL, *temp = NULL, *l = NULL, *r = NULL;
    int c = 1, ch, x, pos;
    while (c)
    {
        printf("\n1.Insert at beginning\t2.Insert at end\t3.Insert at specific position\t4.Exit\nEnter Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data to be inserted at beginning: ");
            scanf("%d", &x);
            insertAtBeginning(&p, x);
            l = p;
            break;
        case 2:
            printf("Enter data to be inserted at end: ");
            scanf("%d", &x);
            insertAtEnd(&p, x);
            r = p;
            break;
        case 3:
            printf("Enter data to be inserted at specific position : ");
            scanf("%d", &x);
            printf("Enter position : ");
            scanf("%d", &pos);
            insertAtPosition(&p, x, pos);
            break;
        case 4:
            c = 0;
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    printf("Displaying the linked list: ");
    p = l;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    p = l;
    while (p != NULL)
    {
        temp = p;
        p = p->next;
        free(temp);
    }

    return 0;
}

sl *createNode(int x)
{
    sl *newNode = (sl *)malloc(sizeof(sl));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(sl **head, int data)
{
    sl *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(sl **head, int data)
{
    sl *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        sl *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertAtPosition(sl **head, int data, int position)
{
    sl *newNode = createNode(data);
    if (position == 0)
    {
        insertAtBeginning(head, data);
    }
    else
    {
        sl *current = *head;
        int i = 0;
        for (i = 0; i < position - 1; i++)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
}