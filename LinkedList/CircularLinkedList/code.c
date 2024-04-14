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

struct Node* insert(struct Node* first,int data,int pos){
    struct Node* p = first;
    struct Node* ptr = newNode(data);
    if(first==NULL){
        ptr->next = ptr;
        first = ptr;
        return first;
    }
    while(p->next!=first) p = p->next;
    if(pos==0){
        ptr->next = first;
        p->next = ptr;
        first = ptr;
        return first;
    }
    struct Node* p1=first,*p2 = first;
    int i = 0;
    while(i!=pos-1 && p1->next!=first){
        p1=p1->next;
        i++;
    }
    if(i!=pos-1){
        printf("Inavlid Position\n");
        return first;
    }    
    if(p1->next==NULL){
        p1->next = ptr;
        ptr->next = first;
        return first;
    }
    p2=p1->next;
    p1->next = ptr;
    ptr->next = p2;
    return first;
}

struct Node* delete(struct Node* first,int pos){
    if(first==NULL){
        printf("Empty List\n");
        return first;
    }
    struct Node* p = first;
    while(p->next!=first) p = p->next;
    if(pos==0){
        struct Node* ptr = first;
        if(ptr->next == first) return NULL;
        first=ptr->next;
        p->next = first;
        free(ptr);
        return first;
    }
    struct Node* p1=first,*p2 = first;
    int i = 0;
    while(i!=pos-1 && p1->next!=first){
        p1=p1->next;
        i++;
    }
    if(i!=pos-1){
        printf("Inavlid Position\n");
        return first;
    }
    if(p1->next==NULL){
        printf("Invalid Position\n");
        return first;
    }
    p2 = p1->next;
    p1->next = p2->next;
    free(p2);
    return first;
}

void display(struct Node* first){
    if(first==NULL){
        printf("Empty List\n");
        return;
    }
    struct Node* ptr = first;
    if(ptr->next == first){
        printf("%d",ptr->data);
        return;
    }
    while(ptr->next!=first){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\nOptions:\n");
        printf("1. Insert at a specific position\n");
        printf("2. Delete at specified index\n");
        printf("3. display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insert(head, data, pos);
                break;

            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = delete(head,pos);
                break;

            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
