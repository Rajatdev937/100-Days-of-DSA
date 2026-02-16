// Problem: Given an array of integers, count the frequency of each distinct element and print the result.

// Input:
// - First line: integer n (size of array)
// - Second line: n integers

// Output:
// - Print each element followed by its frequency in the format element:count

// Example:
// Input:
// 5
// 1 2 2 3 1

// Output:
// 1:2 2:2 3:1

#include <stdio.h>

int main() {
    int n;
    printf("enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    
printf("enter the elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int count = 1;

        // If element already processed, skip it
        int already_counted = 0;
        for (int k = 0; k < i; k++) {
            if (arr[i] == arr[k]) {
                already_counted = 1;
                break;
            }
        }

        if (already_counted)
            continue;

        // Count occurrences ahead
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    return 0;
}

