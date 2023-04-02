#include <stdio.h>
#define MAX 10

int** fun(int r, int c);

int main()
{
    int r, c;
    printf("Row");
    scanf("%d", &r);
    printf("Col");
    scanf("%d", &c);

    int** ptr = fun(r, c);


    printf("%d", ptr[0][0]);
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c;j++)
        {
            printf("%d", ptr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int** fun(int r, int c)
{
    static int arr[MAX][MAX];

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c;j++)
        {
            printf("Enter element at a[%d][%d]", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    return arr;
}