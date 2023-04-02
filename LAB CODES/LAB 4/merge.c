#include <stdio.h>

int main()
{
    int a[10], b[10], m[20];
    int n1, n2, i, j;
    
    printf("Enter size of array 1: ");
    scanf("%d", &n1);
    printf("Enter size of array 2: ");
    scanf("%d", &n2);

    int n3 = n1 + n2;

    for (i = 0; i < n1; i++)
    {
        printf("Enter element at index arr[%d] of array 1: ", i);
        scanf("%d", &a[i]);
        m[i] = a[i];
    }

    int k = i;

    for (i = 0; i < n2; i++)
    {
        printf("Enter element at index arr[%d] of array 2: ", i);
        scanf("%d", &b[i]);
        m[k] = b[i];
        k++;
    }

    printf("\nArray 1\n");
    for (i = 0; i < n1; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nArray 2\n");
    for (i = 0; i < n2; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\nMerged Array\n");
    for (i = 0; i < n3; i++)
    {
        printf("%d ", m[i]);
    }
    return 0;
}