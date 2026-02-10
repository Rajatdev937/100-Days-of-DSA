/* 
Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards */ 

#include<stdio.h>
#include<string.h>
int main ()
{
char str[100];
printf("enter a string: ");
scanf("%s",str);
int size=strlen(str);
int left=0;
int right=size-1;

while(left<right){
    if(str[left]!=str[right]){
     printf("Not palendrome");
     return 0;
    }
    left++;
    right--;
}
printf("Its palendrome");
return 0;
}