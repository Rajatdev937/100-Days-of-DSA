/* Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.
Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)
Output:
- Print the updated array with (n-1) elements, space-separated
Example:
Input:
5
10 20 30 40 50
2
Output:
10 30 40 50
Explanation: Delete position 2 (element 20), remaining elements shift left */

#include <stdio.h>     
int main() {
    int n, pos;
    int arr[100], newArr[100];
    int j = 0;
 

    printf("enter the size of array: ");
    scanf("%d", &n);

    printf("enter the %d of array: ",n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
 
    printf("enter the position of array : ");
    scanf("%d", &pos);


    for (int i = 0; i < n; i++) {
        if (i != pos - 1) {
            newArr[j++] = arr[i];
        }
    }

    for (int i = 0; i < n - 1; i++) {
        printf("%d ", newArr[i]);
    }

    return 0;
}
