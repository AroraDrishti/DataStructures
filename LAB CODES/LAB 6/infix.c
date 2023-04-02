#include <stdio.h>
#include <string.h>
#define MAX 20

int stack[MAX];
int top = -1;

void push(int val)
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

void evaluatePostfix(char exp[])
{
    for(int i = 0; i < strlen(exp); i++)
    {
        //operator
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            int op1 = (pop() - '0');
            int op2 = (pop() - '0');

            int result;

            switch (exp[i])
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
            push(exp[i]);
        }
    }
    printf("%d\n", stack[top]);
}

void evaluatePrefix(char exp[])
{
    for(int i = strlen(exp) - 1; i >= 0; i++)
    {
        //operator
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            int op1 = pop();
            int op2 = pop();
            int result;

            switch (exp[i])
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
            push(exp[i]);
        }
    }
    printf("%d\n", stack[top]);
}

int main()
{
    int choice;
    char exp[MAX];
    int choice2;
    // int choice3;

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
            scanf("%s", exp);
            gets(exp);
            evaluatePrefix(exp);
            break;

        case 2:
            //evaluate postfix
            printf("Enter postfix expression\n");
            scanf("%s", exp);
            gets(exp);
            evaluatePostfix(exp);
            break;

        default:
            printf("Enter another choice\n");
            break;
        }

        printf("Do you want to continue?\n");
        printf("Enter '1' for yes\n");
        scanf("%d", &choice2);

    } while (choice2 == 1);

    return 0;
}