#include <stdio.h>
#include <string.h>
#define MAX 20

int stack[MAX];
int top = -1;
char expr[MAX];

void push(char val)
{
    if(top == MAX - 1)
    {
        printf("Stack overflow");
    }
    else
    {
        top++;
        stack[top] = val;
    }
}

char pop()
{
    if(top == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        return (stack[top--]);
    }
}

void evaluatePostfix(char expr[]) //123++
{
    for(int i = 0; i < strlen(expr); i++)
    {
        //operator
        if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            int op1 = pop();
            int op2 = pop();

            int result;

            switch (expr[i])
            {
            case '+':
                result = op1 + op2;
                push(result);
                break;

            case '-':
                result = op1 - op2;
                push(result);
                break;    
            
            case '*':
                result = op1 * op2;
                push(result);
                break;

            case '/':
                result = op1 / op2;
                push(result);
                break;

            default:
                break;
            }
        }

        //operand
        else
        {
            push(expr[i] - '0');
        }
    }
    printf("%d", stack[top]);
}

void evaluatePrefix(char expr[])
{
    for(int i = strlen(expr) - 1; i >= 0; i--)
    {
        //operator
        if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            int op1 = pop();
            int op2 = pop();
            int result;

            switch (expr[i])
            {
            case '+':
                result = op1 + op2;
                break;

            case '-':
                result = op1 - op2;
                break;    
            
            case '*':
                result = op1 * op2;
                break;

            case '/':
                result = op1 / op2;
                break;

            default:
                break;
            }

            push(result);
        }

        //operand
        else
        {
            push(expr[i] - '0');
        }
    }
    printf("%d", stack[top]);
}

int main()
{
    int choice;
    int choice2;

    do
    {   
        printf("Enter 1 for inputting prefix expression\n");
        printf("Enter 2 for inputting postfix expression\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            //evaluate prefix
            printf("Enter prefix expression\n");
            scanf("%s", expr);
            evaluatePrefix(expr);
            break;

        case 2:
            //evaluate postfix
            printf("Enter postfix expression\n");
            scanf("%s", expr);
            evaluatePostfix(expr);
            break;

        default:
            printf("Enter another choice\n");
            break;
        }

        printf("\nDo you want to continue?\n");
        printf("Enter '1' for yes\n");
        scanf("%d", &choice2);

        top = -1;

    } while (choice2 == 1);

    return 0;
}