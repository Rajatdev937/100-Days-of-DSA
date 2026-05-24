#include <stdio.h>

void sortArray(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] == key) return mid;      // Found
        else if(arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;  
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Sort the array
    sortArray(arr, n);

    // Print sorted array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

   
    return 0;
}