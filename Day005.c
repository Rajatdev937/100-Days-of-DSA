/*problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3
*/

#include<stdio.h>
int main ()
{
int size;
printf("enter the size of array: ");
scanf("%d",&size);

int arr[size];
printf("enter the size of array: ");
for(int i=0;i<size;i++){
    scanf("%d",&arr[i]);
}
for(int i=0;i<size-1;i++){
    if(arr[i]!=arr[i+1]){
        printf("%d ",arr[i]);
    }
}
printf("%d",arr[size-1]);
return 0;
}