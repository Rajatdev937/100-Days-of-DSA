// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

int evaluatePostfix(char exp[])
{
    int i = 0;

    while(exp[i] != '\0')
    {
        if(exp[i] == ' ')
        {
            i++;
            continue;
        }

        if(isdigit(exp[i]))
        {
            int num = 0;

            while(isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
        }
        else
        {
            int op2 = pop();
            int op1 = pop();

            switch(exp[i])
            {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }

            i++;
        }
    }

    return pop();
}

int main()
{
    char exp[100];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}