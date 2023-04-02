#include <stdio.h>

int Factorial(int);

int main()
{
    int num, factorial;

    printf("Enter a number ");
    scanf("%d", &num);

    printf("Factorial is %d ", Factorial(num));
    return 0;
}

int Factorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * Factorial(num - 1);
    }
}