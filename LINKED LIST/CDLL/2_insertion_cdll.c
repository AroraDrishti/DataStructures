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

void insertionatstart()
{
    NN = (struct node *) malloc (sizeof(struct node *));

    int val;
    printf("\nEnter the data to be inseted at the beginning: ");
    scanf("%d", &val);

    NN->data = val;
    NN->prev = NULL;
    NN->next = NULL;

    if(start == NULL)
    {
        NN->next = start;
        NN->prev = start;
        start = NN;
    }
    else
    {
        temp = start;
        do
        {
            temp = temp->next;
        } while (temp->next != start);
        
        NN->next = start;
        start->prev = NN;
        temp->next = NN;
        NN->prev = temp;
        start = NN;
    }
}

void insertionatgivenposition()
{
    NN = (struct node *) malloc (sizeof(struct node *));

    int pos;
    printf("\nEnter the position at which data is to be inserted: ");
    scanf("%d", &pos);

    int val;
    printf("\nEnter the data to be inserted at %d position: ", pos);
    scanf("%d", &val);

    NN->data = val;
    NN->prev = NULL;
    NN->next = NULL;

    if(start == NULL)
    {
        NN->next = start;
        NN->prev = start;
        start = NN;
    }
    else
    {
        temp = start;
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        
        NN->next = temp->next;
        temp->next->prev = NN;
        temp->next = NN;
        NN->prev = temp;
    }
}

void insertionatend()
{
    NN = (struct node *) malloc (sizeof(struct node *));

    int val;
    printf("\nEnter the data to be inserted at the end: ");
    scanf("%d", &val);

    NN->data = val;
    NN->prev = NULL;
    NN->next = NULL;

    if(start == NULL)
    {
        NN->next = start;
        NN->prev = start;
        start = NN;
    }
    else
    {
        temp = start;
        do
        {
            temp = temp->next;
        } while (temp->next != start);

        temp->next = NN;
        NN->prev = temp;
        NN->next = start;
    }
}

void display()
{
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
    // insertionatstart();
    insertionatgivenposition();
    // insertionatend();
    display();
    return 0;
}