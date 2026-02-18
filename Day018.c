// Problem: Given an array of integers, rotate the array to the right by k positions.

// Input:
// - First line: integer n
// - Second line: n integers
// - Third line: integer k

// Output:
// - Print the rotated array

// Example:
// Input:
// 5
// 1 2 3 4 5
// 2

// Output:
// 4 5 1 2 3


#include<stdio.h>
int main ()
{
int size;
printf("enter the size of array: ");
scanf("%d",&size);

int arr[size];
printf("Enter the array of size %d: ",size);
for(int i=0;i<size;i++){
    scanf(" %d",&arr[i]);
}

int k;
printf("enter the frequency of rotation: ");
scanf("%d",&k);

int temp_arr[size];

printf("\n Original Array:\n ");
printf("[");
for(int i=0;i<size;i++){
    printf(" %d",arr[i]);
}
printf("]");


for(int i=0 ; i<size ; i++){
    temp_arr[(i+k)%size]=arr[i];
}
for(int i=0;i<size;i++){
    arr[i]=temp_arr[i];
}
printf("\n Rotated array:\n");
printf("[");
for(int i=0;i<size;i++){
    printf(" %d", arr[i]);
}
printf("]");
return 0;
}