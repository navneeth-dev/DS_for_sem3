#include <stdio.h>
#include <string.h>

void lexicographicSort(char arr[][100], int n) {
    char temp[100];

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char strings[n][100];

    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", strings[i]);
    }

    lexicographicSort(strings, n);

    printf("Strings sorted lexicographically:\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
