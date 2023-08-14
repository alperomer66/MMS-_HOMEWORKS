#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int evaluateExpression(char *expression, int start, int end);

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int power(int base, int exponent) {
    return (int)pow(base, exponent);
}

int evaluateExpression(char *expression, int start, int end) {
    if (start == end) {
        return expression[start] - '0'; // Convert char to int
    }

    int result = 0;
    int operatorIndex = -1;
    int parenthesesCount = 0;

    for (int i = start; i <= end; i++) {
        if (expression[i] == '(') {
            parenthesesCount++;
        } else if (expression[i] == ')') {
            parenthesesCount--;
        } else if (parenthesesCount == 0) {
            if (expression[i] == '+' || expression[i] == '*' || expression[i] == '^') {
                operatorIndex = i;
                break;
            }
        }
    }

    if (operatorIndex != -1) {
        int leftOperand = evaluateExpression(expression, start, operatorIndex - 1);
        int rightOperand = evaluateExpression(expression, operatorIndex + 1, end);

        switch (expression[operatorIndex]) {
            case '+':
                result = add(leftOperand, rightOperand);
                break;
            case '*':
                result = multiply(leftOperand, rightOperand);
                break;
            case '^':
                result = power(leftOperand, rightOperand);
                break;
        }
    }

    return result;
}

int main() {
    char expression[100];
    fgets(expression, sizeof(expression), stdin);

    int length = strlen(expression);
    if (expression[length - 1] == '\n') {
        expression[length - 1] = '\0'; // Remove newline character
    }

    int result = evaluateExpression(expression, 0, strlen(expression) - 1);
    printf("%d\n", result);

    return 0;
}
