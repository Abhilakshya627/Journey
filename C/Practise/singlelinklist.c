#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
} sl;

sl *createNode(int x)
{
    sl *newNode = (sl *)malloc(sizeof(sl));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeg(sl **head, int x)
{
    sl *newNode = createNode(x);
    if (*head == NULL)
        (*head) = newNode;
    else
    {
        newNode->next = (*head);
        *head = newNode;
    }
}

void insertAtEnd(sl **head, int x)
{
    sl *newNode = createNode(x);
    if (*head == NULL)
        (*head) = newNode;
    else
    {
        sl *p = (*head);
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newNode;
    }
}

void insertAtPos(sl **head, int x, int k)
{
    if (*head == NULL && k != 1)
        printf("Invalid Position !!! List Empty\n");
    else if (*head == NULL && k == 1)
    {
        sl *newNode = createNode(x);
        (*head) = newNode;
    }
    else
    {
        sl *newNode = createNode(x);
        sl *p = (*head);
        while ((k - 1) > 1 && p != NULL)
        {
            p = p->next;
            k--;
        }
        if (p == NULL)
        {
            printf("Invalid Position !!!\n");
        }
        else
        {
            newNode->next = p->next;
            p->next = newNode;
        }
    }
}

void display(sl *head)
{
    if (head == NULL)
        printf("List Empty!!!\n");
    else
    {
        printf("Displaying List : ");
        while (head != NULL)
        {
            printf("%d->", head->data);
            head = head->next;
        }
        printf("NULL\n");
    }
}

void delFirst(sl **head)
{
    if (*head == NULL)
        printf("List Empty!!!\n");
    else
    {
        sl *p = (*head);
        (*head) = (*head)->next;
        printf("Deleted Element : %d\n", p->data);
        free(p);
    }
}

void delLast(sl **head)
{
    if (*head == NULL)
        printf("List Empty!!!\n");
    else if ((*head)->next == NULL) // Handling the single element case
    {
        printf("Deleted Element : %d\n", (*head)->data);
        free(*head);
        *head = NULL;
    }
    else
    {
        sl *p = (*head);
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        printf("Deleted Element : %d\n", p->next->data);
        free(p->next);
        p->next = NULL;
    }
}

void delPos(sl **head, int k)
{
    if (*head == NULL)
        printf("List Empty!!!\n");
    else
    {
        if (k == 1)
            delFirst(head);
        else
        {
            sl *p = (*head);
            while (k > 2 && p != NULL)
            {
                p = p->next;
                k--;
            }
            if (p == NULL || p->next == NULL)
            {
                printf("Invalid Position !!!\n");
            }
            else
            {
                sl *temp = p->next;
                printf("Deleted Element : %d\n", temp->data);
                p->next = temp->next;
                free(temp);
            }
        }
    }
}

void freelist(sl **head)
{
    sl *p = (*head);
    while (p != NULL)
    {
        sl *temp = p;
        p = p->next;
        free(temp);
    }
    *head = NULL;
}

void stack()
{
    sl *stack = NULL;
    int a, ch;
    while (1)
    {
        printf("1. Push\t2. Pop\t3. Peek\t4.Display\t5. Exit\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &a);
            insertAtBeg(&stack, a);
            break;
        case 2:
            delFirst(&stack);
            break;
        case 3:
            (stack == NULL) ? printf("Stack Empty!!!\n") : printf("Top element  : %d\n", stack->data);
            break;
        case 4:
            display(stack);
            break;
        case 5:
            freelist(&stack);
            return;
        default:
            printf("Invalid Choice!!!\n");
            break;
        }
    }
}

void reverse(sl **head)
{
    sl *prev = NULL;
    sl *curr = (*head);
    sl *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    (*head) = prev;
}

sl* cloneList(sl *head)
{
    if (head == NULL) return NULL;
    sl *cloneHead = NULL;
    sl *cloneTail = NULL;
    sl *current = head;
    while (current != NULL)
    {
        sl *newNode = (sl*)malloc(sizeof(sl));
        newNode->data = current->data;
        newNode->next = NULL;
        if (cloneHead == NULL) {
            cloneHead = newNode;
            cloneTail = newNode;
        } else {
            cloneTail->next = newNode;
            cloneTail = newNode;
        }
        current = current->next;
    }
    return cloneHead;
}

int isPali(sl *head)
{
    if (head == NULL || head->next == NULL)
        return 1;
    sl *slow = head;
    sl *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    sl *secondHalfClone = cloneList(slow);
    reverse(&secondHalfClone);
    sl *firstHalf = head;
    sl *secondHalf = secondHalfClone;
    while (secondHalf != NULL)
    {
        if (firstHalf->data != secondHalf->data)
        {
            return 0;  
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return 1;  
}

void queue()
{
    sl *queue = NULL;
    int a, ch;
    while (1)
    {
        printf("1. Enqueue\t2. Dequeue\t3.Display\t4. Exit\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &a);
            insertAtEnd(&queue, a);
            break;
        case 2:
            delFirst(&queue);
            break;
        case 3:
            display(queue);
            break;
        case 4:
            freelist(&queue);
            return;
        default:
            printf("Invalid Choice!!!\n");
            break;
        }
    }
} 

int main()
{
    sl *head = NULL;
    int c, x, k;
    while (1)
    {
        printf("1.Insert at Beginning\t2.Insert at End\t3.Insert at Position\t4.Display\t5.Delete First Node\t6.Delete Last Node\n7.Delete kth Node\t8.Stack using list\t9.Reverse List\t10.Check List for Palindrome\t11.Queue using list\t12.Exit\nEnter choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &x);
            insertAtBeg(&head, x);
            break;
        case 2:
            printf("Enter data : ");
            scanf("%d", &x);
            insertAtEnd(&head, x);
            break;
        case 3:
            printf("Enter data : ");
            scanf("%d", &x);
            printf("Enter position : ");
            scanf("%d", &k);
            insertAtPos(&head, x, k);
            break;
        case 4:
            display(head);
            break;
        case 5:
            delFirst(&head);
            break;
        case 6:
            delLast(&head);
            break;
        case 7:
            printf("Enter position : ");
            scanf("%d", &k);
            delPos(&head, k);
            break;
        case 8:
            stack();
            break;
        case 9:
            reverse(&head);
            break;
        case 10:
            (isPali(head)) ? printf("The list is Palindrome\n") : printf("The list is not Palindrome\n");
            break;
        case 11:
            queue();
            break;
        case 12:
            freelist(&head);
            exit(0);
        default:
            printf("Enter a Valid Choice!!!\n");
        }
    }
}