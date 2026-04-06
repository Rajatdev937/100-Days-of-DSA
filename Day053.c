// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4
// 2
// 1 5 6
// 3
// 7

// Explanation:
// Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together


#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for BFS (store node + HD)
struct Pair {
    struct Node* node;
    int hd;
};

struct Pair queue[200];
int front = 0, rear = 0;

void enqueue(struct Node* node, int hd) {
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

struct Pair dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Build tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node* q[100];
    int f = 0, r = 0;

    q[r++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = q[f++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            q[r++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            q[r++] = curr->right;
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalTraversal(struct Node* root) {
    if (!root) return;

    // HD range
    int minHD = 0, maxHD = 0;

    // Store values: index shifted by +100
    int result[200][100]; // result[hd][values]
    int count[200] = {0};

    front = rear = 0;
    enqueue(root, 0);

    while (!isEmpty()) {
        struct Pair p = dequeue();
        struct Node* curr = p.node;
        int hd = p.hd + 100;  // shift index

        result[hd][count[hd]++] = curr->data;

        if (p.hd < minHD) minHD = p.hd;
        if (p.hd > maxHD) maxHD = p.hd;

        if (curr->left)
            enqueue(curr->left, p.hd - 1);
        if (curr->right)
            enqueue(curr->right, p.hd + 1);
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + 100;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", result[idx][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalTraversal(root);

    return 0;
}