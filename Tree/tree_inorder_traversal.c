#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// In-order traversal of a binary tree
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
printf("a:%d ", root->data);
    // Recursively traverse the left subtree
    inorderTraversal(root->left);

    // Process the current node
    printf("b:%d \n", root->data);

    // Recursively traverse the right subtree
    inorderTraversal(root->right);
}

int main() {
    // Create a simple binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("In-order traversal of the binary tree: ");
    inorderTraversal(root);

    // Clean up the allocated memory (not shown in this simple example)
    
    return 0;
}