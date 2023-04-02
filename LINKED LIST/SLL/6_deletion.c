#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node * next;
};

struct node *start = NULL, *NN, *current, *temp, *temp2, *temp3;

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

void deletionatstart()
{
    if(start == NULL)
    {
        //do nothing
    }
    else
    {
        temp = start->next;
        start = temp;
    }
}

void deletionatgivenposition()
{
    int pos;
    printf("\nEnter the position at which the element has to be deleted: ");
    scanf("%d", &pos);

    if(start == NULL)
    {
        //do nothing
    }

    else if (start->next == NULL)
    {
        start = NULL;
    }

    else
    {
        temp = start->next;
        temp2 = start;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
            temp2 = temp2->next;
        }
        temp2->next = temp->next;
    }
}

void deletionatbeforeposition()
{
    if(start == NULL)
    {
        //do nothing
    }
    else
    {
        int pos;
        printf("\nEnter the position before which the element has to be deleted: ");
        scanf("%d", &pos);

        temp = start->next->next;
        temp2 = start->next;
        temp3 = start;

        if(pos == 2)
        {
            start->next = start->next->next;
        }
        else if(pos == 3)
        {
            start->next->next = start->next->next->next;
        }
        else
        {
            for(int i = 3; i < pos; i++)
            {
                temp = temp->next;
                temp2 = temp2->next;
                temp3 = temp3->next;
            }
            temp3->next = temp2->next;

        }
    }
}

void deletionatafterposition()
{
    if(start == NULL)
    {
        //do nothing
    }
    else
    {
        int pos;
        printf("\nEnter the position after which the element has to be deleted: ");
        scanf("%d", &pos);
        temp = start;
        for(int i = 1; i < pos; i++)
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
    else
    {
        // temp = start->next;
        temp2 = start;

        while(temp2->next->next != NULL)
        {
            // temp = temp->next;
            temp2 = temp2->next;
        }
        temp2->next = NULL;
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

void display()
{
    temp = start;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    create();
    display();
    deletionatend();
    display();

    return 0;
}