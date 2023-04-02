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
    printf(" NULL");
}

void insertionatstart()
{
    NN = (struct node *) malloc (sizeof(struct node *));

    int val;
    printf("\nEnter the data: ");
    scanf("%d", &val);

    NN->data = val;
    NN->prev = NULL;    

    if(start == NULL)
    {
        NN->next = NULL;
        start = NN;
    }
    else
    {
        NN->next = start;
        start->prev = NN;
        start = NN;
    }
}

void insertionatgivenposition()
{
//
}

void insertionbeforegivenposition()
{
//
}

void insertionaftergivenposition()
{
//
}

void insertionatend()
{
//
}

int main()
{
    create();
    display();
    insertionatstart();
    // insertionatgivenposition();
    // insertionbeforegivenposition();
    // insertionaftergivenposition();
    // insertionatend();
    display();
    return 0;
}