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

void insertionatstart()
{
    //dynamic memory allocation
    NN = (struct node *) malloc (sizeof(struct node*));

    int val;
    printf("\n\nEnter data to insert at the beginning of circular singly linked list: ");
    scanf("%d", &val);

    NN->data = val;
    NN->next = NULL;

    if(start == NULL)
    {
        start = NN;
        NN->next = start;
    }
    else
    {
        temp = start;
        do
        {
            temp = temp->next;
        }while(temp->next != start);

        temp->next = NN;
        NN->next = start;
        start = NN;
    }
}

void insertionatgivenposition()
{
    //dynamic memory allocation
    NN = (struct node *) malloc (sizeof(struct node*));

    int pos;
    printf("\n\nEnter the position at which data is to be inserted: ");
    scanf("%d", &pos);

    int val;
    printf("\n\nEnter data to be inserted at the %d position of circular singly linked list: ", pos);
    scanf("%d", &val);

    NN->data = val;
    NN->next = NULL;

    if(start == NULL)
    {
        start = NN;
        NN->next = start;
    }
    else
    {
        temp = start;
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        NN->next = temp->next;
        temp->next = NN;
    }
}

void insertionatend()
{
    //dynamic memory allocation
    NN = (struct node *) malloc (sizeof(struct node*));

    int val;
    printf("\n\nEnter data to insert at the end of circular singly linked list: ");
    scanf("%d", &val);

    NN->data = val;
    NN->next = NULL;

    if(start == NULL)
    {
        start = NN;
        NN->next = start;
    }
    else
    {
        temp = start;
        do
        {
            temp = temp->next;
        }while(temp->next != start);

        temp->next = NN;
        NN->next = start;
    }
}

void display()
{
    temp = start;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }while(temp != start);
}

int main()
{
    create();
    display();
    // insertionatstart();
    insertionatgivenposition();
    // insertionatend();
    display();
    return 0;
}