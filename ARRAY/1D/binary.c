#include <stdio.h>
#define MAX 10

int main()
{
    int arr[MAX], i, s, lb, ub, mp, num, flag = 0;

    printf("Enter the size of the array ");
    scanf("%d", &s);

    for (i = 0; i < s; i++)
    {
        printf("Enter element at index %d ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to be searched ");
    scanf("%d", &num);

    lb = 0;
    ub = s - 1;

    while (ub >= lb)
    {
        mp = (ub + lb) / 2;
        if (num == arr[mp])
        {
            printf("%d is found at %d", num, mp);
            flag = 1;
            break;
        }
        else if (num < arr[mp])
        {
            ub = mp - 1;
        }
        else if (num > arr[mp])
        {
            lb = mp + 1;
        }
    }

    if (flag == 0)
    {
        printf("Element not found");
    }

    return 0;
}