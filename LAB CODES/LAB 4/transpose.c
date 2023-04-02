#include <stdio.h>

int main()
{
    int r, c, a[10][10];
    printf("Enter number of rows of matrix: ");
    scanf("%d", &r);
    printf("Enter number of columns of matrix: ");
    scanf("%d", &c);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter element at index at (%d,%d)", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    int tra[c][r];
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            tra[i][j] = a[j][i];
        }
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("%d ", tra[i][j]);
        }
        printf("\n");
    }
    return 0;
}