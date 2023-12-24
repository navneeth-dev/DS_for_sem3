//Q. Binary Search 

#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    int size, key;

    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size\n");
        return 1;
    }

    int arr[size];

    printf("Enter %d sorted elements:\n", size);
    for (int i = 0; i < size; ++i) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, size, key);

    if (result != -1) {
        printf("Key %d found at index %d\n", key, result);
    } else {
        printf("Key %d not found in the array\n", key);
    }

    return 0;
}
