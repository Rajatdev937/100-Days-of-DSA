// Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of nodes)
// - Second line: n space-separated integers (linked list elements)
// - Third line: integer key (element to be counted)

// Output:
// - Print the number of times the key appears in the linked list

// Example:
// Input:
// 6
// 10 20 30 20 40 20
// 20

// Output:
// 3

// Explanation:
// Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    for (int i = 0; i < n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

int countOccurrences(struct node* head, int key) {
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}
int main() {
    int n, key;
    scanf("%d", &n);
    struct node* head = createList(n);
    scanf("%d", &key);
    int result = countOccurrences(head, key);
    printf("%d\n", result);
    return 0;
}