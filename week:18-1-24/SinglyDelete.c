#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

void addAtIndex(struct Node** head, int index, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        for (int i = 0; i < index - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Invalid index!\n");
            free(newNode);
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Element added at index %d\n", index);
}

// Function to delete the first node
void deleteAtStart(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct Node* temp = *head;
    *head = temp->next;
    free(temp);

    printf("Element deleted at the start\n");
}
void deleteAtIndex(struct Node** head, int index) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct Node* temp = *head;
    if (index == 0) {
        *head = temp->next;
        free(temp);
        printf("Element deleted at index 0\n");
    } else {
        for (int i = 0; i < index - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            printf("Invalid index!\n");
            return;
        }

        struct Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);

        printf("Element deleted at index %d\n", index);
    }
}
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }

    free(temp);

    printf("Element deleted at the end\n");
}
void displayList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, index, data;

    while (1) {
        printf("\n1. Add element at a given index\n");
        printf("2. Delete at start\n");
        printf("3. Delete at index\n");
        printf("4. Delete at end\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter index and data to add: ");
                scanf("%d %d", &index, &data);
                addAtIndex(&head, index, data);
                break;
            case 2:
                deleteAtStart(&head);
                break;
            case 3:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                deleteAtIndex(&head, index);
                break;
            case 4:
                deleteAtEnd(&head);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
