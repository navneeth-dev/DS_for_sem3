#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

void sort(struct Node* first) {
    for (struct Node* i = first; i->next != NULL; i = i->next) {
        int b = 0;  // Use int instead of boolean
        for (struct Node* j = first; j->next != NULL; j = j->next) {
            if (j->data > j->next->data) {
                int temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
                b = 1;
            }
        }
        if (!b) break; 
    }
}

int main() {
    return 0;
}
