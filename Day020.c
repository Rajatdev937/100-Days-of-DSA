// Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the count of subarrays having sum zero

// Example:
// Input:
// 6
// 1 -1 2 -2 3 -3

// Output:
// 6

// Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.


#include<stdio.h>

int main()
{
    int n;
    printf("enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("enter the elements of array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int count = 0;

    for(int i = 0; i < n; i++){
        int sum = 0;

        for(int j = i; j < n; j++){
            sum += arr[j];

            if(sum == 0){
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}