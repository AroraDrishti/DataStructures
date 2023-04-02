#include <stdio.h>

void Input(int, int, int[10][10]);
void Addition(int, int, int, int, int[10][10], int[10][10]);
void Subtraction(int, int, int, int, int[10][10], int[10][10]);
void Multiplication(int, int, int, int, int[10][10], int[10][10]);

void main()
{
    int flag = 0;
    do
    {
        int choice;
        printf("Choose the operation to perform\n");
        printf("1: Addition of matrices\n");
        printf("2: Subtraction of matrices\n");
        printf("3: Multiplication of matrices\n");
        scanf("%d", &choice);

        int ra, ca, rb, cb;
        int a[10][10], b[10][10];


        switch (choice)
        {
            case 1:
                printf("Enter number of rows of matrix 1: ");
                scanf("%d", &ra);
                printf("Enter number of columns of matrix 1: ");
                scanf("%d", &ca);
                printf("Enter number of rows of matrix 2: ");
                scanf("%d", &rb);
                printf("Enter number of columns of matrix 2: ");
                scanf("%d", &cb);
                
                if(ra==rb && ca==cb)
                {
                    Input(ra, ca, a);
                    Input(rb, cb, b);
                    Addition(ra, ca, rb, cb, a, b);
                }
                else
                {
                    printf("Addition not possible\n");
                }
                break;

            case 2:
                printf("Enter number of rows of matrix 1: ");
                scanf("%d", &ra);
                printf("Enter number of columns of matrix 1: ");
                scanf("%d", &ca);
                printf("Enter number of rows of matrix 2: ");
                scanf("%d", &rb);
                printf("Enter number of columns of matrix 2: ");
                scanf("%d", &cb);

                if(ra==rb && ca==cb)
                {
                    Input(ra, ca, a);
                    Input(rb, cb, b);
                    Subtraction(ra, ca, rb, cb, a, b);
                }
                else
                {
                    printf("Subtraction not possible\n");
                }
                break;

            case 3:
                printf("Enter number of rows of matrix 1: ");
                scanf("%d", &ra);
                printf("Enter number of columns of matrix 1: ");
                scanf("%d", &ca);
                printf("Enter number of rows of matrix 2: ");
                scanf("%d", &rb);
                printf("Enter number of columns of matrix 2: ");
                scanf("%d", &cb);

                if (rb == ca)
                {
                    Input(ra, ca, a);
                    Input(rb, cb, b);
                    Multiplication(ra, ca, rb, cb, a, b);
                }
                else
                {
                    printf("Multiplication not possible\n");
                }
                break;

            default:
                printf("Enter another choice");
                break;
        }

        printf("Do you want to continue?\n");
        printf("Enter 1 for yes\n");
        printf("Enter 0 for no\n");
        scanf("%d", &flag);
    } while (flag == 1);
}

void Input(int r, int c, int arr[10][10])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter element at index at (%d,%d)", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void Addition(int ra, int ca, int rb, int cb, int a[10][10], int b[10][10])
{
    int add[ra][ca];
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            add[i][j] = a[i][j] + b[i][j];
        }
    }

    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            printf("%d ", add[i][j]);
        }
        printf("\n");
    }
}

void Subtraction(int ra, int ca, int rb, int cb, int a[10][10], int b[10][10])
{
    int sub[ra][ca];
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            sub[i][j] = a[i][j] - b[i][j];
        }
    }

    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            printf("%d ", sub[i][j]);
        }
        printf("\n");
    }
}

void Multiplication(int ra, int ca, int rb, int cb, int a[10][10], int b[10][10])
{
    int mul[ra][cb];
    int k;
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < rb; k++)
            {
                mul[i][j] = mul[i][j] + a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            printf("%d ", mul[i][j]);
        }
        printf("\n");
    }
}