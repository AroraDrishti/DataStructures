#include <stdio.h>
#include <conio.h>
#include <string.h>

int stk[20];
int top=-1;
int pop();
void push(int);

int get_type(char c)
{
    if (c=='+' || c=='-' || c=='*' || c=='/')
        return 1;
    else
        return 0;
}

int main()
{
    char prefix[20];

    int len, i, val, opr1, opr2, result;

    printf("Enter the prefix expression: ");
    scanf("%s",prefix);

    len=strlen(prefix);
    
    for (i=len-1;i>=0;i--)
    {
        switch (get_type(prefix[i]))
        {
            case 0:
                val=prefix[i]-'0';
                push(val);
                break;

            case 1:
                opr1=pop();
                opr2=pop();

                switch(prefix[i])
                {
                    case '+':
                        result=opr1+opr2;
                        break;
                    case '-':
                        result=opr1-opr2;
                        break;
                    case '*':
                        result=opr1*opr2;
                        break;
                    case '/':
                        result=opr1/opr2;
                        break;
                }
                push(result);
        }
    }
    printf("The result of the evaluation is: %d\n",stk[0]);
    return 0;
}

void push(int val)
{
    if (top>20)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stk[top]=val;
    }
}

int pop()
{
    if (top==-1)
    {
        printf("Stack underflow\n");
    }
    else 
    {
        return stk[top--];
        // top--;
    }
}