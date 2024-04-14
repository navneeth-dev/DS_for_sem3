#include <stdlib.h>
#include <stdio.h>

// Hash Function: x is the number of elements

int hash(int key, int x) {
    return key % x;
}

struct Node {
    int data;
    struct Node* next;
};

struct TableEntry {
    int data;
    struct Node* link;
}s[100];

void insert(int key, int n) {
    int value = hash(key, n);
    
    // if the slot is empty, then we directly insert the key
    
    if (s[value].data == -999) s[value].data = key;
    
    // Resolving collision via seperate chaining
    
    else {
        struct Node* ptr = s[value].link;
        struct Node* p = (struct Node*)malloc(sizeof(struct Node));
        p->data = key;
        p->next = NULL;
        
        // If there are no new nodes present, make an insertion
        
        if (ptr == NULL) s[value].link = p;
        
        // We loop through and find the last node and then make an insertion
        
        else {
            while (ptr->next != NULL) ptr = ptr->next;
            ptr->next = p;
        }
    }
}

void search(int key, int n) {
    int value = hash(key, n);
    
    // If slot is empty then the given key isnt present in the table
    
    if (s[value].data == -999) {
        printf("Key %d not found\n", key);
        return;
        
    
    } else {
        
        // If key is present in the slot itself, then we print it
        
        if(s[value].data == key){
            printf("Key %d found\n",key);
            return;
            
        // Otherwise we loop through the linked list and check
            
        }else{
            struct Node* ptr = s[value].link;
            while (ptr != NULL) {
            if (ptr->data == key) {
                printf("Key %d found\n", key);
                return;
            }
            ptr = ptr->next;
        }
        printf("Key %d not found\n", key);
        }
        
    }
}

int main() {
    int n, ele;
    printf("Enter the number of elements to be inserted\n");
    scanf("%d", &n);
    
    // We initialize all objects of the structure to have the data as -999
    // It is easier to work with this way
    
    for (int i = 0; i < n; i++) {
        s[i].data = -999;
        s[i].link = NULL;
    }
    
    printf("Enter the key values\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &ele);
        insert(ele, n);
    }
    
    printf("Enter the element you want to search");
    scanf("%d",&ele);
    search(ele,n);

    return 0;
}
