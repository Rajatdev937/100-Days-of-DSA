// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

// Output:
// - Print the linked list elements after rotation, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 40 50 10 20 30

// Explanation:
// Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

/* Create Linked List */
Node* createList(int n){
    Node *head = NULL, *temp = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++){
        newNode = (Node*)malloc(sizeof(Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

/* Rotate Right by k */
Node* rotateRight(Node* head, int k){

    if(head == NULL || head->next == NULL || k == 0)
        return head;

    Node *temp = head;
    int length = 1;

    /* Find length and last node */
    while(temp->next != NULL){
        temp = temp->next;
        length++;
    }

    k = k % length;   // Important
    if(k == 0)
        return head;

    /* Make circular */
    temp->next = head;

    /* Move to (length - k)th node */
    int steps = length - k;
    Node *newTail = head;

    for(int i = 1; i < steps; i++){
        newTail = newTail->next;
    }

    Node *newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

/* Traverse List */
void traverse(Node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){

    int n, k;

    scanf("%d", &n);
    Node* head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, k);

    traverse(head);

    return 0;
}