#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100 // Maximum number of employee records
#define MAX_HASH_SLOTS 50 // Maximum number of hash table slots

// Structure to represent an employee record
struct Employee {
    int key;
    // Add other fields as needed (e.g., name, age, salary)
};

// Structure to represent the hash table entry
struct HashEntry {
    int occupied; // Flag to check if the slot is occupied
    struct Employee employee;
};

// Function to calculate the hash value using remainder method
int hashFunction(int key, int m) {
    return key % m;
}

// Function to insert an employee record into the hash table
void insert(struct HashEntry hashTable[], int m, struct Employee emp) {
    int key = emp.key;
    int index = hashFunction(key, m);

    // Linear probing to resolve collisions
    while (hashTable[index].occupied) {
        index = (index + 1) % m; // Move to the next slot
    }

    // Insert the employee record into the hash table
    hashTable[index].employee = emp;
    hashTable[index].occupied = 1;
}

// Function to search for an employee record by key
int search(struct HashEntry hashTable[], int m, int key, struct Employee *result) {
    int index = hashFunction(key, m);

    // Linear probing to find the record
    while (hashTable[index].occupied) {
        if (hashTable[index].employee.key == key) {
            *result = hashTable[index].employee;
            return 1; // Employee found
        }
        index = (index + 1) % m; // Move to the next slot
    }

    return 0; // Employee not found
}

int main() {
    // Initialize the hash table
    struct HashEntry hashTable[MAX_HASH_SLOTS] = {0}; // Initialize to zero
    int m = MAX_HASH_SLOTS;

    // Example: Inserting employee records
    struct Employee emp1 = {1234}; // Example record with key 1234
    struct Employee emp2 = {5678}; // Example record with key 5678

    insert(hashTable, m, emp1);
    insert(hashTable, m, emp2);

    // Example: Searching for an employee record
    int searchKey = 5678;
    struct Employee result;

    if (search(hashTable, m, searchKey, &result)) {
        printf("Employee with key %d found!\n", searchKey);
        // Access other fields in 'result' as needed
    } else {
        printf("Employee with key %d not found!\n", searchKey);
    }

    return 0;
}
