#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Function to check if a character is an operator
int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 1;
    return 0;
}

// Function to check if a character is an operand
int isOperand(char c) {
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
        return 1;
    return 0;
}

// Function to get the precedence of an operator
int getPrecedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char **infix, char **postfix) {
    int i, j;
    char *stack = (char *)malloc(MAX * sizeof(char));
    int top = -1;

    *postfix = (char *)malloc((strlen(*infix) + 1) * sizeof(char));

    for (i = 0, j = 0; (*infix)[i] != '\0'; i++) {      
        if (isOperand((*infix)[i])) {
            (*postfix)[j++] = (*infix)[i];
        } else if ((*infix)[i] == '(') {
            stack[++top] = (*infix)[i];
        } else if ((*infix)[i] == ')') {
            while (stack[top] != '(') {
                (*postfix)[j++] = stack[top--];
            }
            top--;
        } else if (isOperator((*infix)[i])) {
            while (top >= 0 && stack[top] != '(' && getPrecedence((*infix)[i]) <= getPrecedence(stack[top])) {
                (*postfix)[j++] = stack[top--];
            }
            stack[++top] = (*infix)[i];
        }
    }

    while (top >= 0) {
        (*postfix)[j++] = stack[top--];
    }

    (*postfix)[j] = '\0';

    free(stack);
}

int main() {
    char *infix = (char *)malloc(MAX * sizeof(char));
    char *postfix = NULL;

    printf("Enter an infix expression: ");
    gets(infix);

    infixToPostfix(&infix, &postfix);

    printf("Postfix expression: %s\n", postfix);

    free(infix);
    free(postfix);

    return 0;
}