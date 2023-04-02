#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter the Number to be Swapped....");
    scanf("%d %d", &a, &b);
    printf("Before swap a=%d b=%d\n", a, b);

    a = a * b;
    b = a / b;
    a = a / b;
    printf("\nAfter swap a=%d b=%d", a, b);
    return 0;
}
