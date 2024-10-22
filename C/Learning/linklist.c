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
void del(sl **);
void display(sl *);
void delKLast(sl **,int);
void delKFirst(sl **,int);
void stacklist();
void stackpush(sl **,int);
int stackpop(sl **);
void stackdisplay(sl *);
void queue();
void enqueue(sl **,int);
int dequeue(sl **);

int main()
{
    sl *p = NULL, *l = NULL, *r = NULL, *temp = NULL;
    int c = 1, ch, x, pos,k;
    while (c)
    {
        printf("\n1.Insert at beginning\t2.Insert at end\t3.Insert at specific position\t4.Display\t5.Delete first node\t6.Delete last node\n7.Delete kth node from last\t8.Delete kth node from beginning\t9.Stack using link list\t10.Queue\t11.Exit\nEnter Choice : ");
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
            if(l==NULL)
            l=r;
            break;
        case 3:
            printf("Enter data to be inserted at specific position : ");
            scanf("%d", &x);
            printf("Enter position : ");
            scanf("%d", &pos);
            insertAtPosition(&p, x, pos);
            break;
        case 4:
            display(l);
            break;
        case 5:
            del(&l);
            break;
        case 6:
            del(&r);
            break;
        case 7:
            printf("Enter value of k : ");
            scanf("%d",&k);
            delKLast(&l,k);
            break;
        case 8:
            printf("Enter value of k : ");
            scanf("%d",&k);
            delKFirst(&l,k);
            break;
        case 9: 
            stacklist();
            break;
        case 10:
            queue();
            break;
        case 11:
            c = 0;
            break;
        default:
            printf("Invalid choice\n");
        }
    }

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

void del(sl** head){
  if(*head==NULL)
  printf("List Empty\n");
  else{
    sl *temp=*head;
    (*head)=(*head)->next;
    free(temp);
  }
}

void display(sl *p){
    printf("Displaying the linked list: ");
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void delKLast(sl **head, int k) {
    if (*head == NULL || k <= 0) return; 
    sl *p1 = *head;
    sl *p2 = NULL;
    for (int i = 0; i < k; i++) {
        if (p1 == NULL) {
            return;
        }
        p1 = p1->next;
    }
    if (p1 == NULL) {
        sl *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    p2 = *head;
    while (p1->next != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }
    sl *temp = p2->next;
    p2->next = p2->next->next;
    free(temp);
}

void delKFirst(sl **head, int k) {
    if (*head == NULL || k <= 0) return;
    sl *temp = *head;
    sl *prev = NULL;
    for (int i = 1; i < k; i++) {
        if (temp == NULL) {
            return; 
        }
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        *head = (*head)->next;
    } 
    else {
        prev->next = temp->next;
    }
    free(temp);
}

void stackpush(sl **top, int data) {
    sl *newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

int stackpop(sl **top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1; // or any other error indicator
    }
    sl *temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

void stackdisplay(sl *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    sl *current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void stacklist(){
  sl *l=NULL,*top=NULL;
  int ch=1,x;
  do{
    printf("1.Push\t2.Pop\t3.Display\t4.Exit\nEnter choice : ");
    scanf("%d",&ch);
    switch(ch){
    case 1:
        printf("Enter value to be pushed : ");
        scanf("%d",&x);
        stackpush(&top,x);
        if(l==NULL)
        l=top;
        break;
    case 2:
        if(l==NULL)
        printf("List Empty\n");
        else
        printf("Popped element : %d\n",stackpop(l));
        break;
    case 3:
        stackdisplay(l);
        break;
    case 4:
        ch=0;
        break;
    default :
    printf("Invalid Choice\n");
    }
  }while(ch);
}

void enqueue(sl **rear,int x){
    sl *newNode = createNode(x);
    rear=newNode;
}

int dequeue(sl **front){
    if(*front==NULL)
    printf("List Empty\n");
    else{
        sl *temp = *front;
         
    }
}