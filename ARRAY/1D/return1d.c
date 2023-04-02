#include <stdio.h>

int *Call(int[3]);

int main()
{
    int a[3];
    int *ptr = Call(a);
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", ptr[i]);
    }
    return 0;
}

int *Call(int arr[3])
{
    for (int i = 0; i < 3; i++)
    {
        printf("Enter number");
        scanf("%d", &arr[i]);
    }
    return arr;
}