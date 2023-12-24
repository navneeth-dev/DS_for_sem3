//Q. Create a program in C to search for the minimum and maximum elements in an array
//with a user defined function. 
#include <stdio.h>

void findMinMax(int arr[], int size, int *min, int *max) {

    *min = *max = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] < *min) {
            *min = arr[i]; // Update minimum
        } else if (arr[i] > *max) {
            *max = arr[i]; // Update maximum
        }
    }
}
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Invalid array size\n");
        return 1; // Exit with an error code
    }
    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; ++i) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int min, max;
    findMinMax(arr, size, &min, &max);
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
    return 0;
}
