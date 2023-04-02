#include <stdio.h>
#define MAX 10

//Deleting an element by value
int main()
{
    int n, i, del, index=-1, arr[MAX];
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the element is to be deleted: ");
    scanf("%d", &del);

    //search element and delete
    for(i=0;i<n;i++)
    {
        if(arr[i]==del)
        {
            index=i;

            for(i=index;i<n;i++)
            {
                arr[i-1]=arr[i];
            }
            n=n-1;
            for(i=0;i<n;i++)
            {
                printf("%d ", arr[i]);
            }
        }
    }

    return 0;
}