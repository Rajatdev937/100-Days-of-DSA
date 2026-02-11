/* Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the first matrix
- Next m lines: n integers each representing the elements of the second matrix

Output:
- Print the resultant matrix after addition, with each row on a new line and elements separated by spaces

Example:
Input:

1 2 3
4 5 6
7 8 9
9 8 7
6 5 4
3 2 1

Output:
10 10 10
10 10 10
10 10 10

Explanation:
Each element of the result matrix is the sum of the corresponding elements from the two input matrices. */


#include <stdio.h>
#include <stdlib.h>

int main() {

    int m, n;
    scanf("%d %d", &m, &n);

    // Dynamic allocation of matrices
    int **a, **b, **sum;

    a = (int**)malloc(m * sizeof(int*));
    b = (int**)malloc(m * sizeof(int*));
    sum = (int**)malloc(m * sizeof(int*));

    for(int i = 0; i < m; i++) {
        a[i] = (int*)malloc(n * sizeof(int));
        b[i] = (int*)malloc(n * sizeof(int));
        sum[i] = (int*)malloc(n * sizeof(int));
    }

    // Input first matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input second matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Addition
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    // Print result
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for(int i = 0; i < m; i++) {
        free(a[i]);
        free(b[i]);
        free(sum[i]);
    }

    free(a);
    free(b);
    free(sum);

    return 0;
}