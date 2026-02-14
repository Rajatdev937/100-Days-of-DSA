/* Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix */

#include<stdio.h>
#include<stdlib.h>
int main ()
{
char choice;


do{
int n;

printf("Enter the size of sqr matrix:");
scanf("%d",&n);

int **arr;
arr=(int**)malloc(n * sizeof(int*));

for(int i=0;i<n;i++){
    arr[i]=(int*)malloc(n*sizeof(int));
}


printf("enter the elements of matrix: ");
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&arr[i][j]);
    }
}
int identity=1;

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){

        if(i==j && arr[i][j] != 1)
        identity=0;

        if(i!=j && arr[i][j] != 0)
        identity=0;
    }
}

if(identity)
printf("Matrix is identity matrix \n");
else
printf("Matrix is not a identity matrix \n");

for(int i=0;i<n;i++){
    free(arr[i]);
}
free(arr);

printf("\n Enter new matrix?(y/n): ");
scanf("%c",&choice);

}while(choice =='y' || choice=='Y');
printf("program ended");
return 0;
}
