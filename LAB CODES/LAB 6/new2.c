#include <stdio.h>
#include <string.h>
#define MAX 20

int stack[MAX];
int stackOperand[MAX];
int stackOperator[MAX];
int topOperand = -1;
int topOperator = -1;
int top = -1;
char expr[MAX];

void pushOperand(char val)
{
    if(topOperand == MAX - 1)
    {
        printf("Stack overflow");
    }
    else
    {
        topOperand++;
        stackOperand[topOperand] = val;
    }
}

char popOperand()
{
    if(topOperand == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        return (stackOperand[topOperand--]);
    }
}

void pushOperator(char val)
{
    if(topOperator == MAX - 1)
    {
        printf("Stack overflow");
    }
    else
    {
        topOperator++;
        stackOperator[topOperator] = val;
    }
}

char popOperator()
{
    if(topOperator == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        return (stackOperator[topOperator--]);
    }
}

void evaluateInfix(char expr[]) //(1+2/3*4-5)
{
    int result;

    for(int i = 0; i < strlen(expr); i++)
    {
        if(expr[i] == '(')
        {
            pushOperator(expr[i]);
        }
        else if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            pushOperand(expr[i]);
            if(expr[i] == '+')
            {
                int op1 = popOperator();
                int op2 = popOperator();
                result = op1 + op2;
            }
            else if(expr[i] == '-')
            {
                int op1 = popOperator();
                int op2 = popOperator();
                result = op1 - op2;
            }
            else if(expr[i] == '*')
            {
                pushOperator(expr[i]);
            }
            else if(expr[i] == '/')
            {
                pushOperator(expr[i]);
            }
        }
        else
        {
            pushOperand(expr[i]);
        }
    }
}

int main()
{
    printf("Enter the infix expression");
    scanf("%s", expr);
    evaluateInfix(expr);
    return 0;
}


// void infixToPrefix(char expr[])
// {
//     for(int i = strlen(expr); i >= 0; i--)
//     {
//         if(expr[i] == ')')
//         {
//             push(expr[i]);
//         }

//         else if(expr[i] == '(')
//         {
//             do
//             {
//                 pop();
//             } while(stack[top] != ')');
//         }
        
//         //operator
//         if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
//         {
//             switch (expr[i])
//             {
//             case '+':
//                 break;

//             case '-':
//                 break;    
            
//             case '*':
//                 break;

//             case '/':
//                 break;

//             default:
//                 break;
//             }
//         }

//         else
//         {
//             push(expr[i] - '0');
//         }
//     }
// }