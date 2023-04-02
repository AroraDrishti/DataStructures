#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL, *temp, *NN, *current, *temp2;

void create()
{
    int n, ch;
    do
    {
        printf("\nEnter the data: ");
        scanf("%d", &n);

        NN = (struct node *)malloc(sizeof(struct node *));

        NN->data = n;
        NN->next = NULL;

        if (start == NULL)
        {
            start = NN;
            current = NN;
        }
        else
        {
            current->next = NN;
            current = NN;
        }

        printf("\n press -1 to stop: ");
        scanf("%d", &ch);

    } while (ch != -1);
}

void display()
{
    temp = start;

    if (start == NULL) //Underflow
    {
        printf("\nNo elements in the list. ");
    }
    else
    {
        printf("\nPrinting all the values: \n");
        while (temp != NULL)
        {
            printf(" %d -> ", temp->data);
            temp = temp->next;
        }
    }
}

void insertfirst(int val)
{
    int n;

    NN = (struct node *)malloc(sizeof(struct node *));

    NN->data = val;
    NN->next = NULL;

    if (start == NULL)
    {
        start = NN;
        current = NN;
    }
    else
    {
        NN->next = start;
        start = NN;
    }
}

void insertmid(int val, int pos)
{
    int n;
    NN = (struct node *)malloc(sizeof(struct node *));

    NN->data = val;
    NN->next = NULL;

    if (start == NULL)
    {
        start = NN;
        current = NN;
    }
    else
    {
        temp = start; //traversing
        for (int i = 0; i < pos; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("\n Position doesn't exixt. ");
        }
        else
        {
            temp2 = temp->next;
            //temp -> NN -> temp2
            temp->next = NN;
            NN->next = temp2;
        }
    }
}

void insertend(int val, int pos)
{
    int n;
    NN = (struct node *)malloc(sizeof(struct node *));

    NN->data = val;
    NN->next = NULL;

    if (start == NULL)
    {
        start = NN;
        current = NN;
    }
    else
    {
        
    }
}

int main()
{
    create();
    display();
    insertfirst(100);
    display();
    insertmid(200, 4);
    display();
    //return 0;
}