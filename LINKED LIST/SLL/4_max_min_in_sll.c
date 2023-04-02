#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node * next;
};

int maxm, minm;
struct node *start = NULL, *NN, *current, *temp;

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

void max()
{
    temp = start;
    maxm = start->data;

    while(temp != NULL)
    {
        if(temp->data > maxm)
        {
            maxm = temp->data;
        }
        temp = temp->next;
    }
    printf("\nLargest element: %d", maxm);
}

void min()
{
    temp = start;
    minm = start->data;

    while(temp != NULL)
    {
        if(temp->data < minm)
        {
            minm = temp->data;
        }
        temp = temp->next;
    }
    printf("\nSmallest element: %d", minm);
}

int main()
{
    create();
    display();
    max();
    min();
    return 0;
}