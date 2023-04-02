#include <stdio.h>
#define MAX 10

int main()
{
    int arr[MAX], i, n, num, flag=0;
    int LowerBound=0, UpperBound=n-1;

    printf("Enter the size of array ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        printf("Enter element at index %d ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to be searched ");
    scanf("%d", &num);

    while(UpperBound>=LowerBound)
    {
        int MidPoint= LowerBound + (UpperBound-LowerBound)/2;
        if(num<arr[MidPoint])
        {
            UpperBound=MidPoint-1;
        }
        else if(num>arr[MidPoint])

        {
            LowerBound=MidPoint+1;
        }
        else if (num==arr[MidPoint])
        {
            printf("\n Value id found at %d index", MidPoint);
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        printf("\n Element not found");
    }
    return 0;
}