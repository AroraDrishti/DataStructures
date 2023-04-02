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
            start = NN;
            NN->prev = start;
            NN->next = start;
            current = NN;
        }
        else
        {
            current->next = NN;
            NN->prev = current;
            current = NN;
            NN->next = start;
            start->prev = NN;
        }

        printf("\nEnter -1 to stop\n");
        scanf("%d", &ch);

    } while (ch != -1);
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
        do
        {
            temp = temp->next;
        } while (temp->next != start);
        
        start->next->prev = temp;
        temp->next = start->next;
        start = start->next;
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
        for(int i = 1; i < pos; i++)
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
        do
        {
            temp = temp->next;
        } while (temp->next != start);
        
        temp->prev->next = start;
        start->prev = temp->prev;
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

void display()
{
    printf("\n");
    temp = start;
    do
    {
        printf(" %d -> ", temp->data);
        temp = temp->next;
    }while(temp != start);
}

int main()
{
    create();
    display();
    // deletionatstart();
    // deletionatgivenposition();
    // deletionatend();
    deletionbyvalue();
    display();
    return 0;
}