// Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of terms)
// - Next n lines: two integers (coefficient and exponent)

// Output:
// - Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Example:
// Input:
// 5
// 10 4
// 20 3
// 30 2
// 40 1
// 50 0

// Output:
// 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Explanation:
// // Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
struct Node* insert(struct Node* head, int c, int e) {
    struct Node* newNode = createNode(c, e);

    if(head == NULL)
        return newNode;

    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Display polynomial
void display(struct Node* head) {
    struct Node* temp = head;

    while(temp != NULL) {
        if(temp->exp == 0)
            printf("%d", temp->coeff);
        else if(temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main() {
    int n, coeff, exp;
    struct Node* head = NULL;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        head = insert(head, coeff, exp);
    }

    display(head);

    return 0;
}