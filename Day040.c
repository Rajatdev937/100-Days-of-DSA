// Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.

#include <stdio.h>

// 🔹 Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 🔹 Heapify (Max Heap)
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    // check left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // check right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if root is not largest
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest); // fix subtree
    }
}

// 🔹 Heap Sort function
void heapSort(int arr[], int n) {

    // Step 1: Build Max Heap
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements
    for (int i = n - 1; i > 0; i--) {
        // Move max to end
        swap(&arr[0], &arr[i]);

        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}

// 🔹 Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 🔹 Main function
int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
