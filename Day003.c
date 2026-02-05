/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons) */


#include<stdio.h>
int main ()
{
int size;
printf("enter the size of array: ");
scanf("%d",&size);

int arr[size];
printf("Enter array of size %d: ",size);
for(int i=0;i<size;i++){
    scanf("%d",&arr[i]);
}
int ele;
printf("enter the element to find: ");
scanf("%d",&ele);

int found=0;
int comparison=0;
for(int i=0;i<size;i++){
    comparison++;
    if(arr[i]==ele){
        printf("element found at %d\n",i);
        found=1;
        break;
    }
}

if(found==0){
    printf("element not found: ");
}
printf("%d comparisons",comparison);
return 0;
}
