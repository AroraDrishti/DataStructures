#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node * next;
};
    
struct node *start = NULL, *NN, *temp, *temp2;

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
            temp = NN;
            start->next = start;
        }
        else
        {
            temp->next = NN;
            NN->next = start;
            temp = NN;
        }

        printf("\nEnter -1 to stop ");
        scanf("%d", &ch);

    } while (ch != -1);
    
}

void display()
{
    printf("\n\n");
    temp = start;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }while(temp != start);
}

void deletionatstart()
{
    if(start == NULL)
    {
        //do nothing
    }

    else if(start->next == start)
    {
        start = NULL;
    }

    else
    {
        temp = start;
        do
        {
            temp = temp->next;
        } while (temp->next != start);

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
        printf("\n\nEnter the position from which data is to be deleted: ");
        scanf("%d", &pos);

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
}

void deletionatend()
{
    if(start == NULL)
    {
        //do nothing
    }

    else if(start->next == start)
    {
        start = NULL;
    }

    else
    {
        temp2 = start;
        temp = start->next;
        do
        {
            temp2 = temp2->next;
            temp = temp->next;
        } while (temp->next != start);

        temp2->next = start;
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
            temp2 = temp;
            temp = temp->next;
            count++;
        }
        printf("\n%d is found at %d position\n", temp->data, count); 
        temp2->next = temp->next;
    }
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