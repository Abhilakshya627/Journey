#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int val;
    struct List *next;
} sl;

sl *createNode(int data) {
    sl *newNode = (sl *)malloc(sizeof(sl));
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

void insert(sl **head, int data) {
    sl *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        sl *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

sl* sum(sl* l1, sl* l2) {
    sl dummy;  // A dummy node to simplify code
    sl *current = &dummy;  // Current node starts at dummy
    dummy.next = NULL;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry) {
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;
        int s = val1 + val2 + carry;
        
        carry = s / 10;
        
        current->next = (sl*)malloc(sizeof(sl));
        current = current->next;
        current->val = s % 10;
        current->next = NULL;
        
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    
    return dummy.next;
}

void printList(sl *head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    sl *l1 = NULL, *l2 = NULL, *result = NULL;
    int n1, n2;

    printf("Enter first number: ");
    scanf("%d", &n1);
    printf("Enter second number: ");
    scanf("%d", &n2);

    // Create linked list for first number
    while (n1 > 0) {
        insert(&l1, n1 % 10);  // Insert digits in reverse order
        n1 = n1 / 10;
    }

    // Create linked list for second number
    while (n2 > 0) {
        insert(&l2, n2 % 10);  // Insert digits in reverse order
        n2 = n2 / 10;
    }

    // Sum the two linked lists
   result=sum(l1,l2);

    // Print the result
    printf("List 1: ");
    printList(l1);
    printf("List 2: ");
    printList(l2);
    printf("Result List: ");
    printList(result);

    return 0;
}
