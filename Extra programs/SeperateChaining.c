#include <stdio.h>
#include <stdlib.h>

#define max 10

struct Node {
    int data;
    struct Node* next;
};

struct Hash {
    int data;
    struct Node* next;
};

// Hashing function to determine the index in the hash table
int hash(int data) {
    return data % max;
}

// Create a new node with the given data
struct Node* newNode(int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

// Insert a new element into the hash table
void insert(struct Hash* h, int data) {
    int index = hash(data);
    if (h[index].data == 0) {
        // If the slot is empty, insert the data directly
        h[index].data = data;
        h[index].next = NULL;
    } else {
        // If collision occurs, insert the data at the end of the linked list
        struct Node* current = h[index].next;
        if (current == NULL) {
            h[index].next = newNode(data);
        } else {
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode(data);
        }
    }
}

// Search for an element in the hash table
int search(struct Hash* h, int data) {
    int index = hash(data);
    if (h[index].data == data) {
        return 1; // Element found in the main slot
    } else {
        struct Node* current = h[index].next;
        while (current != NULL) {
            if (current->data == data) {
                return 1; // Element found in the linked list
            }
            current = current->next;
        }
    }
    return 0; // Element not found
}

int main() {
    struct Hash h[max];

    // Initialize the hash table
    for (int i = 0; i < max; i++) {
        h[i].data = 0;
        h[i].next = NULL;
    }

    // Example: Inserting values into the hash table
    insert(h, 42);
    insert(h, 15);
    insert(h, 71);
    insert(h, 33);
    insert(h, 42); // Collision, inserted at the end

    // Example: Searching for a value
    int searchData = 42;
    if (search(h, searchData)) {
        printf("%d found in the hash table.\n", searchData);
    } else {
        printf("%d not found in the hash table.\n", searchData);
    }

    return 0;
}
