#include <stdio.h>

void SwapCallByValue(int a, int b);
void SwapCallByReference(int *a, int *b);

void SwapCallByValue(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void SwapCallByReference(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;
    printf("Enter two numbers ");
    scanf("%d %d", &a, &b);

    printf("Before Swapping %d %d \n", a, b);
    SwapCallByValue(a, b);
    printf("After Swapping by Call By Value %d %d \n", a, b);
    SwapCallByReference(&a, &b);
    printf("After swapping by Call By Reference %d %d \n ", a, b);

    return 0;
}