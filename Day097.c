// Problem: Given meeting intervals, find minimum number of rooms required.
// Sort by start time and use min-heap on end times.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Meeting;

/* Comparator for sorting meetings by start time */
int compare(const void *a, const void *b) {
    return ((Meeting *)a)->start - ((Meeting *)b)->start;
}

/* Min Heap Functions */
void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
            break;

        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;

        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        int temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;

        index = smallest;
    }
}

void push(int heap[], int *size, int value) {
    heap[*size] = value;
    heapifyUp(heap, *size);
    (*size)++;
}

int pop(int heap[], int *size) {
    int root = heap[0];

    heap[0] = heap[*size - 1];
    (*size)--;

    heapifyDown(heap, *size, 0);

    return root;
}

int top(int heap[]) {
    return heap[0];
}

int minMeetingRooms(Meeting meetings[], int n) {
    qsort(meetings, n, sizeof(Meeting), compare);

    int heap[n];
    int heapSize = 0;

    push(heap, &heapSize, meetings[0].end);

    for (int i = 1; i < n; i++) {
        if (top(heap) <= meetings[i].start) {
            pop(heap, &heapSize);   // Reuse room
        }

        push(heap, &heapSize, meetings[i].end);
    }

    return heapSize;
}

int main() {
    Meeting meetings[] = {
        {0, 30},
        {5, 10},
        {15, 20}
    };

    int n = sizeof(meetings) / sizeof(meetings[0]);

    printf("Minimum Rooms Required = %d\n",
           minMeetingRooms(meetings, n));

    return 0;
}