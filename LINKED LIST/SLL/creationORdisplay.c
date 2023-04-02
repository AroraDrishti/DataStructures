#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node * start = NULL, * temp, * NN, * current;

void create()
{
    int n, ch;
    do
    {
        printf("\nEnter the data: ");
        scanf("%d", &n);

        NN = (struct node *) malloc (sizeof(struct node *));

        NN->data = n;
        NN->next = NULL;

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

        printf("\nPress -1 to stop\n");
        scanf("%d", &ch);
    } while (ch != -1); 
}

void display()
{
    temp = start;

    if(start == NULL)
    {
        printf("\nNo elements in the list");
    }
    else
    {
        printf("\nPrinting all values: ");
        while(temp != NULL)
        {
            printf("\n%d", temp->data);
            temp = temp->next;
        }
    }
}

void insertAtFirst(int val)
{
    NN = (struct node *) malloc (sizeof(struct node *));
    
    NN->data = val;
    NN->next = NULL; 

    if(start == NULL)
    {
        start == NN;
        current == NN;
    }
    else
    {
        NN->next = start;
        start == NN;
    }
}

int main()
{
    create();
    display();
    insertAtFirst(100);
    display();
    return 0;
}