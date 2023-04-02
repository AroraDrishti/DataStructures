#include <stdio.h>

int LinearSearch(int arr[20][20], int r, int c, int x)
{
    int i = 0, j = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (arr[i][j] == x)
            {
                printf("Index matched: %d %d ", i + 1, j + 1);
                return 0;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[20][20], r, c, i = 0, j = 0, x;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("Enter the element at %d %d: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter the element to be matched: ");
    scanf("%d", &x);

    int result;
    
    result = LinearSearch(arr, r, c, x);

    if (result == -1)
    {
        printf("No match found");
    }

    return 0;
}