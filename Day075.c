// Problem Statement
// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

// Input Format
// An integer array arr[].

// Output Format
// Print the length of the longest subarray with sum equal to zero.

// Sample Input
// 15 -2 2 -8 1 7 10 23

// Sample Output
// 5

// Explanation
// The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.


#include <stdio.h>

#define MAX 10000

int maxLenZeroSum(int arr[], int n) {
    int prefix = 0;
    int maxLen = 0;

    int map[2 * MAX + 1];

    for (int i = 0; i < 2 * MAX + 1; i++) {
        map[i] = -2;
    }

    // Offset to handle negative prefix sums
    int offset = MAX;

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        // Case 1: prefix sum is zero
        if (prefix == 0) {
            maxLen = i + 1;
        }

        // Case 2: prefix seen before
        if (map[prefix + offset] != -2) {
            int len = i - map[prefix + offset];
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            // store first occurrence
            map[prefix + offset] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLenZeroSum(arr, n));  // Output: 5

    return 0;
}