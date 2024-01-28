#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* newNode(int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}
struct Node* insertBeg(struct Node* first, int data) {
    struct Node* ptr = newNode(data);
    ptr->next = first;
    first = ptr;
    return first;
}
struct Node* insertMid(struct Node* first, int data, int pos) {
    struct Node* ptr = newNode(data);
    if (pos == 0) {
        return insertBeg(first, data);
    }
    struct Node* p1 = first;
    struct Node* p2 = first;
    int i = 0;
    while (i != pos && p2->next != NULL) {
        p1 = p2;
        p2 = p2->next;
        i++;
    }
    if (i != pos) {
        printf("Position %d is invalid\n", pos);
        return first;
    }
    p1->next = ptr;
    ptr->next = p2;
    return first;
}
struct Node* insertEnd(struct Node* first, int data) {
    struct Node* ptr = newNode(data);
    struct Node* p = first;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return first;
}
void display(struct Node* first) {
    struct Node* p = first;
    while (p != NULL) {
        printf("Element %d\n", p->data);
        p = p->next;
    }
}
int main() {
    struct Node* head = NULL;
    int choice, data, pos;
    while (1) {
        printf("\nOptions:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at a specific position\n");
        printf("3. Insert at the end\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertBeg(head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insertMid(head, data, pos);
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertEnd(head, data);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
