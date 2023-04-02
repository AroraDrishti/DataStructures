#include <stdio.h>
#define MAX 10

//Inserting an element before a given index
int main()
{
    int n, i, index, arr[MAX];
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the index at which element is to be added: ");
    scanf("%d", &index);

    if(n==MAX)
    {
        printf("Insertion not possible.");
    }
    else
    {
        n=n+1;
        for(i=n-1;i>=index-1;i--)
        {
            arr[i+1]=arr[i];
        }

        arr[index-1]=100;

        for(i=0;i<n;i++)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}