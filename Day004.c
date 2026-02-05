/* problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays */

#include<stdio.h>
int main ()
{
int size;
printf("enter size of array: ");
scanf("%d",&size);

int arr[size];

printf("enter %d elements of array:",size);
for(int i=0;i<size;i++){
    scanf("%d",&arr[i]);
}
printf("reversed array:\n");
for(int i=size-1;i>=0;i--){
    printf(" %d", arr[i]);
}
return 0;
}