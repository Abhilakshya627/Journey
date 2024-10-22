// Without fucntion
#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
    int val;
    struct List *next;
} sl;

sl *createNode(int data)
{
    sl *newNode;
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

void insert(sl **head, int data)
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

void sum(sl **l1, sl **l2, sl **sum){
    int c=0,s=0;
    sl **l=sum;
    while(l1!=NULL && l2!=NULL && c!=0){
        s=((l1!=NULL)?(*l1)->val:0)+((l2!=NULL)?(*l2)->val:0)+c;
        c=s/10;
        s=s%10;
        insert(l,s);
        l=&((*l)->next);
    }
    return l;
}

void printList(sl *head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void main()
{
    sl *l1 = NULL, *l2 = NULL, *result = NULL;
    int n1,n2;
    printf("Enter first number : ");
    scanf("%d",&n1);
    printf("Enter second number : ");
    scanf("%d",&n2);
    while(n1>0){
        insert(&l1,n1%10);
        n1=n1/10;
    }
    while(n2>0){
        insert(&l2,n2%10);
        n2=n2/10;
    }
    sum(&l1,&l2,&result);
    printf("List 1 : ");
    printList(l1);
    printf("List 2 : ");
    printList(l2);
    printf("Result List : ");
    printList(result);
}