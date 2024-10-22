#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Queue {
    struct Stack* stack1;
    struct Stack* stack2;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack* stack, int data) {
    struct Node* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = createStack();
    queue->stack2 = createStack();
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    push(queue->stack1, data);
}

int dequeue(struct Queue* queue) {
    if (queue->stack2->top == NULL) {
        while (queue->stack1->top != NULL) {
            int data = pop(queue->stack1);
            push(queue->stack2, data);
        }
    }
    return pop(queue->stack2);
}

int peek(struct Queue* queue) {
    if (queue->stack2->top == NULL) {
        while (queue->stack1->top != NULL) {
            int data = pop(queue->stack1);
            push(queue->stack2, data);
        }
    }
    if (queue->stack2->top != NULL) {
        return queue->stack2->top->data;
    }
    return -1;
}

void display(struct Queue* queue) {
    struct Stack* tempStack = createStack();
    while (queue->stack2->top != NULL) {
        int data = pop(queue->stack2);
        printf("%d ", data);
        push(tempStack, data);
    }
    while (tempStack->top != NULL) {
        push(queue->stack2, pop(tempStack));
    }
    while (queue->stack1->top != NULL) {
        int data = pop(queue->stack1);
        printf("%d ", data);
        push(tempStack, data);
    }
    while (tempStack->top != NULL) {
        push(queue->stack1, pop(tempStack));
    }
    printf("\n");
    free(tempStack);
}

int main() {
    struct Queue* queue = createQueue();
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                data = dequeue(queue);
                if (data != -1) {
                    printf("Dequeued: %d\n", data);
                }
                break;
            case 3:
                data = peek(queue);
                if (data != -1) {
                    printf("Front element: %d\n", data);
                } else {
                    printf("Queue is empty\n");
                }
                break;
            case 4:
                printf("Queue: ");
                display(queue);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
