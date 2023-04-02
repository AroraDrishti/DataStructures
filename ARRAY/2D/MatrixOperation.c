#include <stdio.h>

void Input(int, int, int[10][10]);
void Addition(int, int, int, int, int[10][10], int[10][10]);
void Subtraction(int, int, int, int, int[10][10], int[10][10]);
void Multiplication(int, int, int, int, int[10][10], int[10][10]);
void Transpose(int, int, int[10][10]);
void ColumnMatrix(int, int, int[10][10]);
void RowMatrix(int, int, int[10][10]);
void DiagonalElements(int, int, int[10][10]);
void UpperTriangular(int, int, int[10][10]);
void LowerTriangular(int, int, int[10][10]);
void SumOfAllElements(int, int, int[10][10]);
void SumOfRowElements(int, int, int[10][10]);
void SumOfColumnElements(int, int, int[10][10]);

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
        printf("4: Transpose of matrix\n");
        printf("5: Column Matrix\n");
        printf("6: Row Matrix\n");
        printf("7: Diagonal Elements of Matrix\n");
        printf("8: Upper Triangular Matrix\n");
        printf("9: Lower Triangular Matrix\n");
        printf("10: Sum of all elements of Matrix\n");
        printf("11: Sum of elements of rows of Matrix\n");
        printf("12: Sum of elements of columns of Matrix\n");
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
            Input(ra, ca, a);
            Input(rb, cb, b);
            Addition(ra, ca, rb, cb, a, b);
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
            Input(ra, ca, a);
            Input(rb, cb, b);
            Subtraction(ra, ca, rb, cb, a, b);
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
            Input(ra, ca, a);
            Input(rb, cb, b);
            Multiplication(ra, ca, rb, cb, a, b);
            break;

        case 4:
            printf("Enter number of rows of matrix: ");
            scanf("%d", &ra);
            printf("Enter number of columns of matrix: ");
            scanf("%d", &ca);
            Input(ra, ca, a);
            Transpose(ra, ca, a);
            break;

        case 5:
            printf("Enter number of rows of matrix: ");
            scanf("%d", &ra);
            printf("Enter number of columns of matrix: ");
            scanf("%d", &ca);
            Input(ra, ca, a);
            ColumnMatrix(ra, ca, a);
            break;

        case 6:
            printf("Enter number of rows of matrix: ");
            scanf("%d", &ra);
            printf("Enter number of columns of matrix: ");
            scanf("%d", &ca);
            Input(ra, ca, a);
            RowMatrix(ra, ca, a);
            break;

        case 7:
            printf("Enter number of rows of matrix: ");
            scanf("%d", &ra);
            printf("Enter number of columns of matrix: ");
            scanf("%d", &ca);
            Input(ra, ca, a);
            DiagonalElements(ra, ca, a);
            break;

        case 8:
            printf("Enter number of rows of matrix: ");
            scanf("%d", &ra);
            printf("Enter number of columns of matrix: ");
            scanf("%d", &ca);
            Input(ra, ca, a);
            UpperTriangular(ra, ca, a);
            break;

        case 9:
            printf("Enter number of rows of matrix: ");
            scanf("%d", &ra);
            printf("Enter number of columns of matrix: ");
            scanf("%d", &ca);
            Input(ra, ca, a);
            LowerTriangular(ra, ca, a);
            break;

        case 10:
            printf("Enter number of rows of matrix: ");
            scanf("%d", &ra);
            printf("Enter number of columns of matrix: ");
            scanf("%d", &ca);
            Input(ra, ca, a);
            SumOfAllElements(ra, ca, a);
            break;

        case 11:
            printf("Enter number of rows of matrix: ");
            scanf("%d", &ra);
            printf("Enter number of columns of matrix: ");
            scanf("%d", &ca);
            Input(ra, ca, a);
            SumOfRowElements(ra, ca, a);
            break;

        case 12:
            printf("Enter number of rows of matrix: ");
            scanf("%d", &ra);
            printf("Enter number of columns of matrix: ");
            scanf("%d", &ca);
            Input(ra, ca, a);
            SumOfColumnElements(ra, ca, a);
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

    if (ra == rb && ca == cb)
    {
        for (int i = 0; i < ra; i++)
        {
            for (int j = 0; j < ca; j++)
            {
                add[i][j] = a[i][j] + b[i][j];
            }
        }

        for (int i = 0; i < ca; i++)
        {
            for (int j = 0; j < ra; j++)
            {
                printf("%d ", add[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Addition not possible");
    }
}

void Subtraction(int ra, int ca, int rb, int cb, int a[10][10], int b[10][10])
{
    int sub[ra][ca];

    if (ra == rb && ca == cb)
    {
        for (int i = 0; i < ra; i++)
        {
            for (int j = 0; j < ca; j++)
            {
                sub[i][j] = a[i][j] - b[i][j];
            }
        }

        for (int i = 0; i < ca; i++)
        {
            for (int j = 0; j < ra; j++)
            {
                printf("%d ", sub[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Subtraction not possible");
    }
}

void Multiplication(int ra, int ca, int rb, int cb, int a[10][10], int b[10][10])
{
    int mul[ra][cb];
    int k;

    if (rb == ca)
    {
        for (int i = 0; i < ra; i++)
        {
            for (int j = 0; j < cb; j++)
            {
                mul[i][j] = 0;
                for (int k = 0; k < rb; k++)
                {
                    mul[i][j] = mul[i][j] + a[i][k] + b[k][j];
                }
            }
        }

        for (int i = 0; i < ca; i++)
        {
            for (int j = 0; j < ra; j++)
            {
                printf("%d ", mul[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Multiplication not possible");
    }
}

void Transpose(int ra, int ca, int a[10][10])
{
    int tra[ca][ra];
    for (int i = 0; i < ca; i++)
    {
        for (int j = 0; j < ra; j++)
        {
            tra[i][j] = a[j][i];
        }
    }

    for (int i = 0; i < ca; i++)
    {
        for (int j = 0; j < ra; j++)
        {
            printf("%d ", tra[i][j]);
        }
        printf("\n");
    }
}

void ColumnMatrix(int ra, int ca, int a[10][10])
{
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            if (j == 0)
            {
                printf("%d ", a[i][j]);
            }
        }
        printf("\n");
    }
}

void RowMatrix(int ra, int ca, int a[10][10])
{
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            if (i == 0)
            {
                printf("%d ", a[i][j]);
            }
        }
        printf("\n");
    }
}

void DiagonalElements(int ra, int ca, int a[10][10])
{
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            if (i == j)
            {
                printf("%d ", a[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void UpperTriangular(int ra, int ca, int a[10][10])
{
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            if (i <= j)
            {
                printf("%d ", a[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void LowerTriangular(int ra, int ca, int a[10][10])
{
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            if (i >= j)
            {
                printf("%d ", a[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void SumOfAllElements(int ra, int ca, int a[10][10])
{
    int sum = 0;
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            sum = sum + a[i][j];
        }
        printf("\n");
    }
    printf("Sum of all elements is %d\n", sum);
}

void SumOfRowElements(int ra, int ca, int a[10][10])
{
    for (int i = 0; i < ra; i++)
    {
        int sum = 0;
        for (int j = 0; j < ca; j++)
        {
            sum = sum + a[i][j];
        }
        printf("Sum of elements of Row %d is %d\n", i + 1, sum);
    }
}

void SumOfColumnElements(int ra, int ca, int a[10][10])
{
    for (int j = 0; j < ca; j++)
    {
        int sum = 0;
        for (int i = 0; i < ra; i++)
        {
            sum = sum + a[i][j];
        }
        printf("Sum of elements of Column %d is %d\n", j + 1, sum);
    }
}