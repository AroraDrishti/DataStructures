#include <stdio.h>

int LinearSearch(int arr[], int n, int x)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    int arr[100], n, i = 0, x;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d of the array: ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to be matched: ");
    scanf("%d", &x);

    int result;

    result = LinearSearch(arr, n, x);

    if (result == -1)
    {
        printf("No match found");
    }
    else
    {
        printf("Index matched: %d", result);
    }
    return 0;
}