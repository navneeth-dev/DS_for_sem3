#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node {
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->left = ptr->right = NULL;
    ptr->data = data;
    return ptr;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data > root->data) root->right = insert(root->right, data);
    else root->left = insert(root->left, data);
    return root;
}

void search(struct Node* root,int data){
    if(root==NULL){
        printf("Element %d not found",data);
        return;
    }
    if(root->data == data){
        printf("Element %d found",data);
        return;
    }
    if(root->data < data) search(root->right,data);
    if(root->data > data)search(root->left,data);
}

void display(struct Node* root, int level) {
    if (root != NULL) {
        display(root->right, level + 1);
        for (int i = 0; i < level; i++)
            printf("\t");
        printf("%d\n", root->data);
        display(root->left, level + 1);
    }
}
int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    search(root,200);

    return 0;
}
