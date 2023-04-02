#include <stdio.h>
#define MAX 10

// Insert element at the beginning
int main()
{
    int n, i, arr[MAX];
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    if (n == MAX)
    {
        printf("Insertion not possible.");
    }
    else
    {
        n = n + 1;
        for (i = n - 1; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = 100;
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}