// Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
// Distribute into buckets, sort each, concatenate.
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float bucket[100];
    int count;
} Bucket;

// Insertion Sort for a bucket
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    Bucket buckets[n];

    // Initialize buckets
    for (int i = 0; i < n; i++) {
        buckets[i].count = 0;
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];
        buckets[idx].bucket[buckets[idx].count++] = arr[i];
    }

    // Sort each bucket
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i].bucket, buckets[i].count);
    }

    // Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            arr[k++] = buckets[i].bucket[j];
        }
    }
}

int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}