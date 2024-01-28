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
struct Node* insertMid(struct Node* first, int data, int pos) {
    struct Node* ptr = newNode(data);
    if (pos == 0) {
        ptr->next = first;
        first = ptr;
        return first;
    }
    struct Node* p1 = first;
    struct Node* p2 = first;
    int i = 0;
    while (i != pos && p2!= NULL) {
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
struct Node* DeleteBeg(struct Node* first) {
    if(first==NULL){
        printf("Linked List Empty\n");
        return first;
    }
    struct Node* ptr = first;
    first = first->next;
    free(ptr);
    return first;
}
struct Node* DeleteMid(struct Node* first,int pos) {
    if (pos == 0) {
        return DeleteBeg(first);
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
    p1->next = p2->next;
    free(p2);
    return first;
}
struct Node* DeleteEnd(struct Node* first) {
    struct Node* p = first;
    while (p->next->next != NULL) {
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
    return first;
}
void display(struct Node* first) {
    if(first==NULL){
        printf("Empty List\n");
    }
    struct Node* p = first;
    while (p != NULL) {
        printf("Element %d\n", p->data);
        p = p->next;
    }
}
int main(){
    struct Node* head = NULL;
    int choice, data, pos;
    while (1) {
        printf("\nOptions:\n");
        printf("1. Insert at a specific position\n");
        printf("2. Delete at start\n");
        printf("3. Delete at specified index\n");
        printf("4. Delete at end\n");
        printf("5. display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insertMid(head, data, pos);
                break;
            case 2:
                head = DeleteBeg(head);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = DeleteMid(head,pos);
                break;
            case 4:
                head = DeleteEnd(head);
                break;
            case 5:
                display(head);
                break;     
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
