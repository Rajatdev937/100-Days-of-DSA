
// Problem Statement
// Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

// Books must be allocated in contiguous order.

// Input Format
// n m
// n space-separated integers representing pages in books

// Output Format
// Print the minimum possible value of the maximum pages assigned to any student.

// Sample Input
// 4 2
// 12 34 67 90

// Sample Output
// 113

// Explanation
// One optimal allocation is:
// Student 1: 12 + 34 + 67 = 113
// Student 2: 90
// Maximum pages = 113 (minimum possible)
#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {

        // Single book has more pages than limit
        if (arr[i] > maxPages)
            return 0;

        // Allocate to next student
        if (pages + arr[i] > maxPages) {
            students++;
            pages = arr[i];

            if (students > m)
                return 0;
        }
        else {
            pages += arr[i];
        }
    }

    return 1;
}

int allocateBooks(int arr[], int n, int m) {

    // If students are more than books
    if (m > n)
        return -1;

    int low = 0;
    int high = 0;
    int ans = -1;

    for (int i = 0; i < n; i++) {
        high += arr[i];
    }

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", allocateBooks(arr, n, m));

    return 0;
}