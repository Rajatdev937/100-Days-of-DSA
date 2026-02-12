/* Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the matrix

Output:
- Print "Symmetric Matrix" if the given matrix is symmetric
- Otherwise, print "Not a Symmetric Matrix"

Example:
Input:
3 3
1 2 3
2 4 5
3 5 6

Output:
Symmetric Matrix */


#include<stdio.h>
#include<stdlib.h>
int main ()
{
int row,col;
printf("enter number of rows: ");
scanf("%d",&row);

printf("enter number of columns: ");
scanf("%d",&col);

int **arr;

arr=(int**)malloc(row * sizeof(int*));
for(int i=0;i<row;i++){
    arr[i]=malloc(col *sizeof(int));
}

printf("enter the elements of matrices: ");
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        scanf("%d",&arr[i][j]);
    }
}
int issymetric=1;
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
   if(arr[i][j]!=arr[j][i]){
    issymetric=0;
    break;
   }
    }
}
if(issymetric){
    printf("its a symmetric matric");
}
else{
    printf("its not a symmertic matric");
}
return 0;
}
