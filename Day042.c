// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.


// Input Format:
// - First line contains integer N.
// - Second line contains N space-separated integers.


// Output Format:
// - Print the reversed queue.


// Example:
// Input:
// 5
// 10 20 30 40 50.


// Output:
// 50 40 30 20.

#include <stdio.h>
#define MAX 100

// Queue
int queue[MAX];
int front = -1, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Queue Functions
void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1) return -1;
    int val = queue[front];
    if (front == rear) front = rear = -1;
    else front++;
    return val;
}
// Stack Functions
void push(int x) {
    if (top == MAX - 1) return;
    stack[++top] = x;
}
int pop() {
    if (top == -1) return -1;
    return stack[top--];
}
int main() {
    int n, x;
    scanf("%d", &n);

// Input queue
for (int i = 0; i < n; i++) {
scanf("%d", &x);
enqueue(x);
}
// Step 1: Queue → Stack
while (front != -1) {
 push(dequeue());
}

// Step 2: Stack → Queue
while (top != -1) {
enqueue(pop());
}

// Print reversed queue
for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
}
return 0;
}
