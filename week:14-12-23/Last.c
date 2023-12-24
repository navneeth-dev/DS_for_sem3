// Q. Write a C program to find the index of the last occurrence of a number in an array
//with a user defined function.
#include <stdio.h>

int lastOccurrenceIndex(int arr[], int size, int key) {
    int lastIndex = -1;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            lastIndex = i;
        }
    }
    return lastIndex;
}

int main() {
    int size, key;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size\n");
        return 1;
    }

    int arr[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; ++i) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to find the last occurrence: ");
    scanf("%d", &key);

    int result = lastOccurrenceIndex(arr, size, key);

    if (result != -1) {
        printf("Last occurrence of %d at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}
