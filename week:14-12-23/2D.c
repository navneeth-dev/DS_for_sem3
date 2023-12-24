#include <stdio.h>

int isElementPresent(int arr[][3], int rows, int cols, int key) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] == key) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int rows, cols, key;

    printf("Enter the number of rows and columns in the 2D array: ");
    scanf("%d %d", &rows, &cols);

    int arr[rows][3];

    printf("Enter %d elements for the 2D array:\n", rows * cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    if (isElementPresent(arr, rows, cols, key)) {
        printf("Element %d is present in the 2D array\n", key);
    } else {
        printf("Element %d is not present in the 2D array\n", key);
    }

    return 0;
}
