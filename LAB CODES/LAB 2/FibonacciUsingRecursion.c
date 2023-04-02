#include <stdio.h>

void Fibonacci(int);

int main()
{
    int terms, i;
    printf("Enter number of terms");
    scanf("%d", &terms);

    printf("Fibonacci Series\n");
    printf("0\n1\n");

    Fibonacci(terms - 2);

    return 0;
}

void Fibonacci(int terms)
{
    static int n1 = 0, n2 = 1, n3;
    if (terms > 0)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        printf("%d\n", n3);
        Fibonacci(terms - 1);
    }
}