/* Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

Input:
- Single integer n

Output:
- Print the n-th Fibonacci number

Example:
Input:
6

Output:
8

Explanation: Sequence: 0,1,1,2,3,5,8 at positions 0,1,2,3,4,5,6  */
#include<stdio.h>
int fibo(int n){
if(n==0){
return 0;
}
if(n==1){
return 1;
}
return fibo(n-1)+fibo(n-2);
}
int main ()
{
int n,result;
printf("enter a integer: ");
scanf("%d",&n);
result=fibo(n);
printf("fibonaci of %d term is %d",n,result);
return 0;
}
