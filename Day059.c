// Problem Statement:
// Construct a binary tree from given inorder and postorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains inorder traversal
// - Third line contains postorder traversal

// Output Format:
// - Print preorder traversal of constructed tree

// Example:
// Input:
// 5
// 4 2 5 1 3
// 4 5 2 3 1

// Output:
// 1 2 4 5 3

// Explanation:
// Postorder gives root at end, inorder divides left and right subtrees.


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int search(int inorder[], int start, int end, int value) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(int inorder[], int postorder[], int start, int end, int *postIndex) {
    if(start > end)
        return NULL;

    // Get root from postorder
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = postorder[*postIndex];
    node->left = node->right = NULL;

    (*postIndex)--;

    if(start == end)
        return node;

    int inIndex = search(inorder, start, end, node->data);

    // IMPORTANT: build right first
    node->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    node->left  = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return node;
}

void preorder(Node* root) {
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}