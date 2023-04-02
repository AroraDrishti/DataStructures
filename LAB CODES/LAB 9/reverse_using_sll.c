#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int stack[MAX], stackreverse[MAX];
int topstack = -1, topreverse = -1;

struct node 
{
    int data;
    struct node * next;
};
    
struct node *start = NULL, *NN, *current, *temp;

void pushstack(int val)
{
    if (topstack == MAX - 1)
    {

        printf("\nStack Overflow");
    }
    else
    {
        topstack++;
        stack[topstack] = val;
    }
}

void pushreverse(int val)
{
    if (topreverse == MAX - 1)
    {

        printf("\nStack Overflow");
    }
    else
    {
        topreverse++;
        stack[topreverse] = val;
    }
}

int pop()
{
    if (topstack == -1)
    {
        printf("\nStack Underflow");
        return -1;
    }
    else
    {
        return stack[topstack--];
    }
}

void create()
{
    int ch, val;
    do
    {

        //dynamic memory allocation
        NN = (struct node *) malloc (sizeof(struct node*));

        printf("\nEnter data: ");
        scanf("%d", &val);

        NN->data = val;
        NN->next = NULL;

        //if first element
        if(start == NULL)
        {
            start = NN;
            current = NN;
        }
        else
        {
            current->next = NN;
            current = NN;
        }

        printf("\nEnter -1 to stop ");
        scanf("%d", &ch);

    } while (ch != -1);
    
}

void reverse()
{
    int i = 0;
    temp = start;
    while(temp != NULL)
    {
        i++;
        pushstack(temp->data);
        temp = temp->next;
    }
    for(int j = 0; j < i; j++)
    {
        int val;
        val = pop();
        pushreverse(val);
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

void displayreverse()
{
    for(int i = 0; i <= topreverse; i++)
    {
        printf(" %d ->", stack[i]);
    }
    printf(" NULL");
}

// void disrev()
// {
//     printf("\nStack Status: ");
//     for (int i = 0; i <= topreverse; i++)
//     {
//         printf(" %d ", stackreverse[i]);
//     }
// }

int main()
{
    create();
    display();
    reverse();
    // disrev();
    // printf("\n");
    displayreverse();
    return 0;
}