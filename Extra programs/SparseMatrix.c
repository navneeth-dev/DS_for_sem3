#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    int row;
    int col;
    struct Node* next;
};

struct Node* end(struct Node* first, int val, int row, int col) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->val = val;
    ptr->row = row;
    ptr->col = col;
    ptr->next = NULL;

    if (first == NULL) {
        return ptr;
    }

    struct Node* p = first;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    return first;
}

int main() {
    struct Node* first = NULL;
    int mat[][5] = {
        {0, 0, 10, 1, 2},
        {2, 0, -4, 0, 1}
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            if (mat[i][j] != 0) {
                first = end(first, mat[i][j], i, j);
            }
        }
    }
    struct Node* p = first;
    while (p != NULL) {
        printf("Value: %d, Row: %d, Column: %d\n", p->val, p->row, p->col);
        p = p->next;
    }

    return 0;
}

