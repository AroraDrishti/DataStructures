#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *NN, *start, *current, *temp;

void create()
{
    int ch;
    do
    {
        NN = (struct node *) malloc (sizeof(struct node *));

        int val;
        printf("\nEnter the data: ");
        scanf("%d", &val);

        NN->data = val;
        NN->next = NULL;

        if (start == NULL)
        {
            NN->prev = NULL;
            start = NN;
            current = NN;
        }
        else
        {
            current->next = NN;
            NN->prev = current;
            current = NN;
        }

        printf("\nEnter -1 to stop\n");
        scanf("%d", &ch);

    } while (ch != -1);
}

void display()
{
    temp = start;
    while(temp != NULL)
    {
        printf(" %d -> ", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}

void reverse()
{
    printf(" \nRveverse of linked list is \n");
    temp = start;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    while(temp->prev != NULL)
    {
        printf(" %d -> ", temp->data);
        temp = temp->prev;
    }
    printf(" %d -> ", temp->data);
    printf(" NULL\n");
}

int main()
{
    create();
    display();
    reverse();
    return 0;
}