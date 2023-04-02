#include <stdio.h>

int main()
{
    int arr[10], size, sum=0;

    printf("Enter the size of the array ");
    scanf("%d", &size);

    for(int i=0; i<size; i++)
    {
        printf("Enter element at index %d", i);
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }

    for(int i=0; i<size; i++)
    {
        sum=sum+arr[i];
    }    
    printf("Sum is %d ", sum);

    return 0;
}