#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* enqueue(struct Node* front, struct Node* rear, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (front == NULL) {
        // Queue is empty
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    
    return rear;  // Return the updated rear
}

struct Node* dequeue(struct Node* front, struct Node* rear) {
    if (front == NULL && rear == NULL) {
        printf("UNDER-FLOW\n");
        exit(1);
    }

    struct Node* ptr = front;
    if (front == rear) {
        // Only one element in the queue
        front = rear = NULL;
    } else {
        front = ptr->next;
    }
    free(ptr);
    return front;  // Return the updated front
}

void display(struct Node* front, struct Node* rear) {
    if (rear == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    struct Node* ptr = front;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, element;

    do {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                rear = enqueue(front, rear, element);
                if (front == NULL) {
                    // Update front when the queue was empty
                    front = rear;
                }
                break;
            case 2:
                front = dequeue(front, rear);
                break;
            case 3:
                display(front, rear);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free memory before exiting the program
    while (front != NULL) {
        struct Node* temp = front;
        front = front->next;
        free(temp);
    }

    return 0;
}
