#include <stdio.h>
#include <string.h>

int searchSubstring(const char *mainStr, const char *subStr) {
    int mainLen = strlen(mainStr);
    int subLen = strlen(subStr);

    for (int i = 0; i <= mainLen - subLen; ++i) {
        int j;
        for (j = 0; j < subLen; ++j) {
            if (mainStr[i + j] != subStr[j]) {
                break;
            }
        }

        if (j == subLen) {
            return i;
        }
    }

    return -1;
}

int main() {
    char mainStr[100], subStr[50];

    printf("Enter the main string: ");
    scanf("%s", mainStr);

    printf("Enter the substring to search: ");
    scanf("%s", subStr);

    int result = searchSubstring(mainStr, subStr);

    if (result != -1) {
        printf("Substring found at index %d\n", result);
    } else {
        printf("Substring not found in the main string\n");
    }

    return 0;
}
