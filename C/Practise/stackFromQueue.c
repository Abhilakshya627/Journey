#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

typedef struct {
    Queue q1, q2;
} Stack;

void initStack(Stack *s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

void push(Stack *s, int value) {
    enqueue(&s->q1, value);
}

int pop(Stack *s) {
    if (isEmpty(&s->q1)) {
        printf("Stack is empty\n");
        return -1;
    }
    while (s->q1.front != s->q1.rear) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    int value = dequeue(&s->q1);
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
    return value;
}

int peek(Stack *s) {
    if (isEmpty(&s->q1)) {
        printf("Stack is empty\n");
        return -1;
    }
    while (s->q1.front != s->q1.rear) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    int value = s->q1.front->data;
    enqueue(&s->q2, dequeue(&s->q1));
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
    return value;
}

void display(Stack *s) {
    if (isEmpty(&s->q1)) {
        printf("Stack is empty\n");
        return;
    }
    Queue tempQueue;
    initQueue(&tempQueue);
    while (!isEmpty(&s->q1)) {
        int value = dequeue(&s->q1);
        printf("%d ", value);
        enqueue(&tempQueue, value);
    }
    while (!isEmpty(&tempQueue)) {
        enqueue(&s->q1, dequeue(&tempQueue));
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped: %d\n", value);
                }
                break;
            case 3:
                value = peek(&s);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                display(&s);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}