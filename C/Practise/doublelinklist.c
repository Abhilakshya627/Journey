#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    struct list *prev;
    int data;
    struct list *next;
} dl;

dl *createNode(int x) {
    dl *newNode = (dl*)malloc(sizeof(dl));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeg(dl **head, int x) {
    dl *newNode = createNode(x);
    if (*head == NULL)
        *head = newNode;
    else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(dl **head, int x) {
    dl *newNode = createNode(x);
    if (*head == NULL)
        *head = newNode;
    else {
        dl *p = *head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
        newNode->prev = p;
    }
}

void display(dl **head) {
    if (*head == NULL)
        printf("List Empty\n");
    else {
        dl *p = *head;
        printf("Displaying List: ");
        while (p != NULL) {
            printf("%d->", p->data);
            p = p->next;
        }
        printf("NULL\n");
    }
}

void insertAtPos(dl **head, int x, int k) {
    if (k <= 0) {
        printf("Invalid Position!!!\n");
        return;
    }
    if (*head == NULL && k != 1) {
        printf("Invalid Position!!!\n");
        return;
    }
    
    // Special case for inserting at the beginning
    if (k == 1) {
        insertAtBeg(head, x);
        return;
    }

    dl *p = *head;
    int pos = 1;
    
    // Traverse to the (k-1)th position
    while (pos < k - 1 && p != NULL) {
        p = p->next;
        pos++;
    }

    if (p == NULL || p->next == NULL && pos < k - 1) {
        printf("Invalid Position\n");
        return;
    }

    dl *newNode = createNode(x);

    newNode->next = p->next;
    newNode->prev = p;
    
    if (p->next != NULL)
        p->next->prev = newNode;
    
    p->next = newNode;
}

void freelist(dl **head) {
    dl *p = *head;
    dl *temp = NULL;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
}

void delFirst(dl **head){
    if(*head == NULL){
        printf("List Empty\n");
        return;
    }
    dl *temp = *head;
    *head = (*head)->next;
    if(*head != NULL)
        (*head)->prev = NULL;
    free(temp);
}

void delLast(dl **head){
    if(*head == NULL){
        printf("List Empty\n");
        return;
    }
    dl *p = *head;
    while(p->next != NULL)
        p = p->next;
    if(p->prev != NULL)
        p->prev->next = NULL;
    free(p);
}

int main() {
    dl *p = NULL;
    int ch, x, k;
    while (1) {
        printf("1.Insert at Beginning\t2.Insert at End\t3.Display\t4.Insert at Position\n5.Delete First Node\t6.Delete Last Node\t7.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: 
                printf("Enter node value: ");
                scanf("%d", &x);
                insertAtBeg(&p, x);
                break;
            case 2:
                printf("Enter node value: ");
                scanf("%d", &x);
                insertAtEnd(&p, x);
                break;
            case 3: 
                display(&p); 
                break;
            case 4:
                printf("Enter node value: ");
                scanf("%d", &x);
                printf("Enter position: ");
                scanf("%d", &k);
                insertAtPos(&p, x, k);
                break;
            case 5: delFirst(&p);break;
            case 6: delLast(&p);break;
            case 7:
                freelist(&p);
                exit(0);
                break;
            default: 
                printf("Invalid Choice!!!\n");
        } 
    }
    return 0;
}