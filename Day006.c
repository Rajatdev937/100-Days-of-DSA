/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed  */

#include<stdio.h>
int main ()
{
int n1,n2;
printf("enter of size of 1st array: ");
scanf("%d",&n1);

int arr1[n1];
printf("enter 1st array of size %d: ",n1);
for(int i=0;i<n1;i++){
    scanf("%d",&arr1[i]);
}
printf("enter of size of 2st array: ");
scanf("%d",&n2);

int arr2[n2];
printf("enter 2nd array of size %d: ",n2);
for(int i=0;i<n2;i++){
    scanf("%D",&arr2[i]);
}

int arr3[n1+n2];
for(int i=0;i<n1;i++){
    arr3[i]=arr1[i];
}

for(int i=0;i<n2;i++){
    arr3[n1+i]=arr2[i];
}
int n3=n1+n2;

for(int i=0;i<n3-1;i++){
  for(int j = 0; j <n3-i-1; j++) {
     if(arr3[j]>arr3[j+1]) {
          int temp=arr3[j];
         arr3[j]=arr3[j+1];
        arr3[j+1]=temp;
            }
        }
}
printf("array containing all arrival times in chronological order:");
for(int i =0;i<n3;i++){
printf("%d ",arr3[i]);
}
return 0;
}