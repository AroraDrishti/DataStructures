#include <stdio.h>
#include <string.h>
#include <ctype.h>

int a[100], top = -1;

int main(void)
{
    int length, i;

    char exp[20], temp, temp1, temp2;

    printf("Enter a postfix expression: ");
    scanf("%s", &exp);

    length = strlen(exp);
    printf("\n%d\n", length);

    for (i = 0; i < length; i++)
    {
        temp = exp[i]-'0';

        if (isdigit(temp))
        {
            top++;
            a[top] = temp - '0';

            for (i = 0; i <= top; i++)
            {
                printf("\n%d\n", a[i]);
            }
        }

        else if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
        {
            temp1 = a[top] - '0';
            temp2 = a[top - 1] - '0';
            top = top - 2;

            switch (temp)
            {
            case '+':
                top++;
                a[top] = temp1 + temp2;
                // printf("\n%d%c%d\n", temp1, temp, temp2);
                // printf("\n%d\n", a[top]);
                break;

            case '-':
                top++;
                a[top] = temp1 - temp2;
                // printf("\n%d%c%d\n", temp1, temp, temp2);
                // printf("\n%d\n", a[top]);
                break;

            case '*':
                top++;
                a[top] = temp1 * temp2;
                // printf("\n%d%c%d\n", temp1, temp, temp2);
                // printf("\n%d\n", a[top]);
                break;

            case '/':
                top++;
                a[top] = temp1 / temp2;
                // printf("\n%d%c%d\n", temp1, temp, temp2);
                // printf("\n%d\n", a[top]);
                break;

            default:
                printf("\nInvalid character.\n");
                break;
            }
            printf("\n%d\n", top);
        }
    }
    printf("ANS: %d", a[top]);
    for (i = 0; i <= top; i++)
    {
        printf("\n%d \n", a[i]);
    }
}