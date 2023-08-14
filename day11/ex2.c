#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef struct {
    double data[MAX_STACK_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

void push(Stack* stack, double value) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = value;
    } else {
        printf("Error: Stack is full.\n");
        exit(1);
}
}

double pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    } else {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
}

double evaluateRPN(char* expression) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, (double)(expression[i] - '0'));
        } else if (expression[i] == '+' || expression[i] == '*' || expression[i] == '-') {
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);

            if (expression[i] == '+') {
                push(&stack, operand1 + operand2);
            } else if (expression[i] == '*') {
                push(&stack, operand1 * operand2);
            } else if (expression[i] == '-') {
                push(&stack, operand1 - operand2);
            }
        }
    }

    return pop(&stack);
}

int main() {
    char expression[100];
    fgets(expression, sizeof(expression), stdin);

    double result = evaluateRPN(expression);
    printf("%.2f\n", result);

    return 0;
}
