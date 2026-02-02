/* Insert an Element in an Array
Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.
Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)
Output:
- Print the updated array (n+1 integers) in a single line, space-separated
Example:
Input:
5
1 2 4 5 6
3
3
Output:
1 2 3 4 5 6
Explanation: Insert 3 at position 3, elements [4,5,6] shift right */

#include <stdio.h>
int main() {
int n, pos, x;
printf("enter the number of elements: ");
scanf("%d", &n);
int arr[n + 1];  

printf("enter %d elements: ",n);
for (int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}

printf("enter the position to insert (1-based): " );
scanf("%d", &pos);

printf("enter the element to insert: ");
scanf("%d", &x);

for (int i = n; i >= pos; i--) {
arr[i] = arr[i - 1];
}
arr[pos - 1] = x;

printf("updated array: ");
for(int i = 0; i <= n; i++) {
printf("%d ", arr[i]);
}
return 0;
}
