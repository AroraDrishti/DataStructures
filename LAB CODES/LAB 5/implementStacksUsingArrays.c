#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int val)
{
    if (top == MAX - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        top = top + 1;
        stack[top] = val;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        top = top - 1;
    }
}

void display()
{
    printf("\nStack : ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
}

int main()
{
    push(10);
    display();
    push(20);
    display();
    push(30);
    display();
    push(40);
    display();
    push(50);
    display();
    push(60);
    display();

    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    
    return 0;
}