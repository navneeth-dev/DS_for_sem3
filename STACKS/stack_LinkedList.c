#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the stack
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element onto the stack
struct Node* push(struct Node* top, int data) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    // If the stack is empty, set the new node as the top
    if (top == NULL) {
        newNode->next = NULL;
        top = newNode;
        return top;
    }
    // Otherwise, link the new node to the current top and update the top
    newNode->next = top;
    top = newNode;
    return top;
}

// Function to pop an element from the stack
struct Node* pop(struct Node* top) {
    // Check if the stack is empty
    if (top == NULL) {
        printf("Underflow\n");
        exit(1); // Exit the program if underflow occurs
    }
    // Store the current top node and move the top pointer to the next node
    struct Node* ptr = top;
    top = ptr->next;
    // Free the memory of the popped node
    free(ptr);
    return top;
}

// Function to display the elements of the stack
void display(struct Node* top) {
    // Check if the stack is empty
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    // Traverse the stack and print each element
    struct Node* current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL; // Initialize the stack as empty
    int choice, element;

    do {
        // Display the stack menu
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                top = push(top, element);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free any remaining nodes in the stack
    while (top != NULL) {
        struct Node* temp = top;
        top = top->next;
        free(temp);
    }

    return 0;
}

