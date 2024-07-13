#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Define the size of the stack

int top = -1; // Initialize the top of the stack to -1 (indicating an empty stack)
int stack[SIZE]; // Array to hold stack elements

// Function prototypes
void push(int element);
int pop();
void display();

int main() {
    int choice, element;

    // Menu-driven program
    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform operation based on user choice
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                element = pop();
                if (element != -1) {
                    printf("Popped element: %d\n", element);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to push an element onto the stack
void push(int element) {
    if (top == SIZE - 1) {
        // Check for stack overflow
        printf("Stack Overflow. Cannot push element %d.\n", element);
    } else {
        // Increment top and add the new element
        top++;
        stack[top] = element;
        printf("Element %d pushed onto the stack.\n", element);
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        // Check for stack underflow
        printf("Stack Underflow. Cannot pop from an empty stack.\n");
        return -1; // Indicate failure
    } else {
        // Retrieve the top element and decrement top
        int element = stack[top];
        top--;
        return element;
    }
}

// Function to display the elements of the stack
void display() {
    if (top == -1) {
        // Check if the stack is empty
        printf("Stack is empty.\n");
    } else {
        // Traverse and print all stack elements
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

