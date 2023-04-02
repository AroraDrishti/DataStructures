#include <stdio.h>

int** Input(int a[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter element at index (%d,%d)", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    return a;
}

int main()
{
    int r, c, a[3][3];

    int** ptr = Input(a);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d, ", ptr[i][j]);
        }
    }
    return 0;
}
