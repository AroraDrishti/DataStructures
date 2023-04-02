#include <stdio.h>

int** Input(int r, int c, int a[10][10])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter element at index (%d,%d)", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    return a;
}

// void Display(int r, int c, int a[10][10])
// {
//     for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < c; j++)
//         {
//             printf("%d", a[i][j]);
//         }
//     }
// }

int main()
{
    int r, c, a[10][10];
    int **ptr;
    printf("Enter number of rows");
    scanf("%d", &r);
    printf("Enter number of columns");
    scanf("%d", &c);
    ptr = Input(r, c, a);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }
    // Display(r, c, ptr);
    return 0;
}