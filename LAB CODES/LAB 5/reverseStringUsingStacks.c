#include <stdio.h>
#include <string.h>
#define MAX 100

char name[MAX];
char reversed[MAX];
int top = -1, topD = -1;

void push(char val)
{
    if (top == MAX - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        top++;
        name[top] = val;
    }
}

void pushR(char letter)
{
    if (topD == MAX - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        topD = topD + 1;
        reversed[topD] = letter;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        char l = name[top];
        top = top - 1;
        return l;
    }
}

int main()
{
    int i;
    printf("Enter the string: ");
    gets(name);
    
    for (i = 0; i < strlen(name); i++)
    {
        push(name[i]);
    }
   
    for (i = 0; i < strlen(name); i++)
    {
        char letter = pop();
        pushR(letter);
    }

    printf("Reversed string: ");
    puts(reversed);

    return 0;
}