#include <stdio.h>

void Input(int r, int c, int a[10][10])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter element at index at (%d,%d)", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void Display(int r, int c, int a[][10])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[10][10];
    int r, c;
    printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter number of columns: ");
    scanf("%d", &c);
    Input(r, c, a);
    Display(r, c, a);
    return 0;
}