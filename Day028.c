/* problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop. */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to create circular linked list
Node* createCircularList(int n) {
    if (n <= 0) return NULL;

    Node *head = NULL, *temp = NULL, *newnode = NULL;

    for (int i = 0; i < n; i++) {
        newnode = (Node*)malloc(sizeof(Node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Make it circular
    temp->next = head;

    return head;
}

// Function to traverse circular list
void traverseCircularList(Node *head) {
    if (head == NULL) return;

    Node *ptr = head;

    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

int main() {
    int n;
    scanf("%d", &n);

    Node *head = createCircularList(n);

    traverseCircularList(head);

    return 0;
}