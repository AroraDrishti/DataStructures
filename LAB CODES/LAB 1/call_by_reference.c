#include <stdio.h>

void SwapCallByReference(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    printf("Swapped numbers: %d %d", *a, *b);
}

int main()
{
    int a, b;
    printf("Enter 2 numbers ");
    scanf("%d %d", &a, &b);

    SwapCallByReference (&a, &b);

    return 0;
}