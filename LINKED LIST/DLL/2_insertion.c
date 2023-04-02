#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *NN, *start, *current, *temp, *temp2;

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

void insertionatend()
{
    NN = (struct node *) malloc (sizeof(struct node *));

    int val;
    printf("\nEnter the data: ");
    scanf("%d", &val);

    NN->data = val;
    NN->next = NULL;    

    if(start == NULL)
    {
        NN->next = NULL;
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
        NN->prev = temp;
    }
}

void insertionatgivenposition()
{
    NN = (struct node *) malloc (sizeof(struct node *));

    int pos;
    printf("\nEnter the position at which data is to entered: ");
    scanf("%d", &pos);

    int val;
    printf("\nEnter the data to be entered at %d position: ", pos);
    scanf("%d", &val);

    NN->data = val;   

    if(start == NULL)
    {
        NN->prev = NULL;
        NN->next = NULL;
        start = NN;
    }
    else
    {
        temp = start;
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next->prev = NN;
        NN->next = temp->next;
        NN->prev = temp;
        temp->next = NN;
    }
}

void insertionbeforegivenposition()
{
    NN = (struct node *) malloc (sizeof(struct node *));

    int pos;
    printf("\nEnter the position before which data is to entered: ");
    scanf("%d", &pos);

    int val;
    printf("\nEnter the data to be entered before %d position: ", pos);
    scanf("%d", &val);

    NN->data = val;   

    if(start == NULL)
    {
        NN->prev = NULL;
        NN->next = NULL;
        start = NN;
    }
    else
    {
        temp = start;
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp2 = temp->prev;
        temp->prev = NN;
        NN->next = temp;
        NN->prev = temp2;
        temp2->next = NN;
    }
}

void insertionaftergivenposition()
{
    NN = (struct node *) malloc (sizeof(struct node *));

    int pos;
    printf("\nEnter the position after which data is to entered: ");
    scanf("%d", &pos);

    int val;
    printf("\nEnter the data to be entered after %d position: ", pos);
    scanf("%d", &val);

    NN->data = val;   

    if(start == NULL)
    {
        NN->prev = NULL;
        NN->next = NULL;
        start = NN;
    }
    else
    {
        temp = start;
        for(int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->next->prev = NN;
        NN->next = temp->next;
        NN->prev = temp;
        temp->next = NN;
    }
}

int main()
{
    create();
    display();
    // insertionatstart();
    // insertionatgivenposition();
    // insertionbeforegivenposition();
    insertionatgivenposition();
    // insertionatend();
    display();
    return 0;
}