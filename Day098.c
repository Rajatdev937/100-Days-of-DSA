// Problem: Given intervals, merge all overlapping ones.
// Sort first, then compare with previous.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compare(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

void mergeIntervals(Interval arr[], int n) {
    if (n == 0) return;

    qsort(arr, n, sizeof(Interval), compare);

    Interval result[n];
    int k = 0;

    result[k] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[k].end) {
            result[k].end = (result[k].end > arr[i].end)
                                ? result[k].end
                                : arr[i].end;
        } else {
            k++;
            result[k] = arr[i];
        }
    }

    printf("Merged Intervals:\n");
    for (int i = 0; i <= k; i++) {
        printf("[%d, %d] ", result[i].start, result[i].end);
    }
}

int main() {
    Interval arr[] = {{1,3}, {2,6}, {8,10}, {15,18}};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}