#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node * next;
};
    
struct node *start = NULL, *NN, *current, *temp, *temp2;

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

void insertionatstart()
{
    //dynamic memory allocation
    NN = (struct node *) malloc (sizeof(struct node*));

    int val;
    printf("\n\nEnter data to insert at the beginning: ");
    scanf("%d", &val);

    NN->data = val;
    NN->next = NULL;

    if(start == NULL)
    {
        start = NN;
    }
    else
    {
        NN->next = start;
        start = NN;
    }
}

void insertionatmid()
{
    //dynamic memory allocation
    NN = (struct node *) malloc (sizeof(struct node*));

    int val, pos;
    printf("\n\nEnter the position: ");
    scanf("%d", &pos);
    printf("\nEnter data to insert at %d position: ", pos);
    scanf("%d", &val);

    NN->data = val;
    NN->next = NULL;

    if(start == NULL)
    {
        start = NN;
    }
    else
    {
        temp = start;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        NN->next = temp->next; 
        temp->next = NN;
    }
}

void insertionbeforegivenposition()
{
    //dynamic memory allocation
    NN = (struct node *) malloc (sizeof(struct node*));

    int val, pos;
    printf("\n\nEnter the position: ");
    scanf("%d", &pos);
    printf("\nEnter data to insert before %d position: ", pos);
    scanf("%d", &val);

    NN->data = val;
    NN->next = NULL;

    if(start == NULL)
    {
        start = NN;
    }
    else
    {
        temp = start;
        for(int i = 1; i < pos - 1; i++)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NN;
        NN->next = temp;
    }
}

void insertionaftergivenposition()
{
    //dynamic memory allocation
    NN = (struct node *) malloc (sizeof(struct node*));

    int val, pos;
    printf("\n\nEnter the position: ");
    scanf("%d", &pos);
    printf("\nEnter data to insert after %d position: ", pos);
    scanf("%d", &val);

    NN->data = val;
    NN->next = NULL;

    if(start == NULL)
    {
        start = NN;
    }
    else
    {
        temp = start;
        for(int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        NN->next = temp->next;
        temp->next = NN;
    }
}

void insertionatlast()
{
    //dynamic memory allocation
    NN = (struct node *) malloc (sizeof(struct node*));

    int val;
    printf("\n\nEnter data to insert at the end: ");
    scanf("%d", &val);

    NN->data = val;
    NN->next = NULL;

    if(start == NULL)
    {
        start = NN;
    }
    else
    {
        temp = start;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NN;
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
    create();
    display();
    insertionaftergivenposition();
    display();

    return 0;
}