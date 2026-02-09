/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olle
Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored */

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
int temp;
while(left<right){
    temp=str[left]; 
    str[left]=str[right];
    str[right]=temp;

left++;
right--;
}
printf("Reversed  string : %s",str);
return 0;
}