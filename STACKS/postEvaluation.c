
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

void push(int item) {
    if (top == MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

int evaluatePostfix(char postfix[]) {
    int i = 0;
    while (postfix[i] != '\0') {
        char currentSymbol = postfix[i];
        if (isdigit(currentSymbol)) {
            push(currentSymbol - '0');
        } else if (isOperator(currentSymbol)) {
            int operand2 = pop();
            int operand1 = pop();
            switch (currentSymbol) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                case '%':
                    push(operand1 % operand2);
                    break;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char postfixExpression[100];

    printf("Enter postfix expression: ");
    scanf("%s", postfixExpression);

    int result = evaluatePostfix(postfixExpression);

    printf("Result: %d\n", result);

    return 0;
}
