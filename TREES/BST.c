#include <stdio.h>
#include <stdlib.h>

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

void preOrder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
void postOrder(struct Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void search(struct Node* root,int data){
    if(root==NULL){
        printf("%d not found\n",data);
        return;
    }
    if(root->data == data){
        printf("%d found\n",root->data);
        return;
    }
    if(data<root->data) search(root->left,data);
    else search(root->right,data);
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

    printf("Preorder traversal: ");
    preOrder(root);

    printf("\nInorder traversal: ");
    inOrder(root);

    printf("\nPostorder traversal: ");
    postOrder(root);

    search(root,41);

    return 0;
}
