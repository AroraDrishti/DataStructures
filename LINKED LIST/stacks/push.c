#include <stdio.h>
#include <stdlib.h>

struct stack 
{
    int data;
    struct stack * next;
};
    
struct stack *start = NULL, *NN, *top, *temp;

void insertionatend()
{
    NN = (struct stack*) malloc (sizeof(struct stack*));
    NN->data = 10;
    NN->next = NULL;

    if(top == NULL)
    {
        top == NN;
        start = NN;
    }
    else
    {
        top->next = NN;
        top = NN;
    }
}

void display()
{
    temp = start;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    insertionatend();
    display();
    return 0;
}