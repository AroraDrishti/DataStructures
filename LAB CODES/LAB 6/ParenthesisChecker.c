#include <stdio.h>
#include <string.h>
#define MAX 100

int top = -1, stack[MAX];
void push(char);
char pop();

void main()
{
    char expr[MAX], temp;
    int i, flag = 1;
    printf("Parenthesis Checker");
    printf("\nEnter an expression: ");
    scanf("%s", expr);

    for (i = 0; i < strlen(expr); i++)
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
            push(expr[i]);
        }

        if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if (top == -1)
            {
                flag = 0;
            }

            else
            {
                temp = pop();
                if (expr[i] == ')' && (temp == '{' || temp == '['))
                    flag = 0;
                else if (expr[i] == '}' && (temp == '(' || temp == '['))
                    flag = 0;
                else if (expr[i] == ']' && (temp == '(' || temp == '{'))
                    flag = 0;
            }
        }
    }

    if (top >= 0)
        flag = 0;

    if (flag == 1)
    {
        printf("Valid Expression");
    }
    else
    {
        printf("Invalid Expression");
    }
}

void push(char c)
{
    if (top == (MAX - 1))
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stack[top] = c;
    }
}
char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        return (stack[top--]);
    }
}