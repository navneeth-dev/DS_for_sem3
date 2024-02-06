#include<stdio.h>
#include<stdlib.h>

struct Node {
    int coeff;
    int expp;
    struct Node* next;
};

struct Node* beg(struct Node* first, int coeff, int expp) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->coeff = coeff;
    ptr->expp = expp;
    if (first == NULL) {
        first = ptr;
        first->next = NULL;
        return first;
    }
    ptr->next = first;
    first = ptr;
    return first;
}

void display(struct Node* first) {
    struct Node* ptr = first;
    while (ptr != NULL) {
        printf("Element: %d %d\n", ptr->coeff, ptr->expp);
        ptr = ptr->next;
    }
}

struct Node* polyAdd(struct Node* q1, struct Node* q2) {
    struct Node* p1 = q1;
    struct Node* p2 = q2;
    struct Node* p3 = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->expp == p2->expp) {
            p3 = beg(p3, p1->coeff + p2->coeff, p1->expp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->expp > p2->expp) {
            p3 = beg(p3, p1->coeff, p1->expp);
            p1 = p1->next;
        } else {
            p3 = beg(p3, p2->coeff, p2->expp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        p3 = beg(p3, p1->coeff, p1->expp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        p3 = beg(p3, p2->coeff, p2->expp);
        p2 = p2->next;
    }

    return p3;
}


int main() {
    struct Node* q1 = NULL;
    struct Node* q2 = NULL;

    q1 = beg(q1, 2, 3);
    q1 = beg(q1, 5, 1);

    q2 = beg(q2, 3, 2);
    q2 = beg(q2, 1, 1);

    printf("Polynomial 1:\n");
    display(q1);

    printf("Polynomial 2:\n");
    display(q2);

    struct Node* result = polyAdd(q1, q2);

    printf("Polynomial Addition Result:\n");
    display(result);

    return 0;
}
