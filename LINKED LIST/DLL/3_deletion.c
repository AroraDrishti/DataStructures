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

void deletionatstart()
{
    if(start == NULL)
    {
        //do nothing
    }
    else
    {
        temp = start;
        start = temp->next;
        temp->prev = NULL;
    }
}

void deletionatgivenposition()
{
    if(start == NULL)
    {
        //do nothing
    }
    else
    {
        int pos;
        printf("\nEnter the position from which element is to deleted: ");
        scanf("%d", &pos);

        temp = start;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        
    }
}

void deletionbeforegivenposition()
{
    if(start == NULL)
    {
        //do nothing
    }
    else
    {
        int pos;
        printf("\nEnter the position before which element is to deleted: ");
        scanf("%d", &pos);

        temp = start;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next; 
    }
}

void deletionaftergivenposition()
{
    if(start == NULL)
    {
        //do nothing
    }
    else
    {
        int pos;
        printf("\nEnter the position after which element is to deleted: ");
        scanf("%d", &pos);

        temp = start;
        for (int i = 1; i < pos + 1; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next; 
    }
}

void deletionatend()
{
    if(start == NULL)
    {
        //do nothing
    }
    else
    {
        temp = start;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
    }
}

void deletionbyvalue()
{
    if(start == NULL)
    {
        //do nothing
    }
    else
    {
        int count = 1, val;
        temp = start;

        printf("\nEnter the value to be deleted: ");
        scanf("%d", &val);
        
        while(temp->data != val)
        {
            temp = temp->next;
            count++;
        }
        printf("\n%d is found at %d position\n", temp->data, count);
        temp->prev->next = temp->next;
    }
}


int main()
{
    create();
    display();
    deletionbyvalue();
    display();
    return 0;
}