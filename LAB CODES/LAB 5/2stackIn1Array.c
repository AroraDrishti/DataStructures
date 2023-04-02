#include <stdio.h>
#define MAX 10

int stack[MAX], topA = -1, topB = MAX;

void pushA (int val)
{
    if (topB - topA == 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        topA = topA + 1;
        stack[topA] = val;
    }
}

void pushB (int val)
{
    if (topB - topA == 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        topB = topB - 1;
        stack[topB] = val;
    }
}

void display()
{
    int i;
    printf("\nElements of Stack A are: ");
    for (i = 0; i <= topA; i++)
    {
        printf(" %d ", stack[i]);
    }

    printf("\nElements of Stack B are: ");
    for (i = MAX - 1; i >= topB; i--)
    {
        printf(" %d ", stack[i]);
    }

    printf("\nElements of entire array are: ");
    for (i = 0; i < MAX; i++)
    {
        printf(" %d ", stack[i]);
    }
}

void popA()
{
    if (topA == -1)
    {
        printf("\nStack A is empty");
    }
    else
    {
        topA = topA - 1;
    }
}

void popB()
{
    if (topB == MAX)
    {
        printf("\nStack B is empty");
    }
    else
    {
        topB = topB + 1;
    }
}

int main()
{
    pushA(10);
    pushA(20);
    pushA(30);
    pushB(100);
    pushB(200);
    display();
    popA();
    pushB(200);
    popA();
    popA();
    display();

    return 0;
}