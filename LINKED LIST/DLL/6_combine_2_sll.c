#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *NN, *start = NULL, *current, *temp, *NN2, *start2 = NULL, *current2, *temp2;;

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

void create2()
{
    int ch;
    do
    {
        NN2 = (struct node *) malloc (sizeof(struct node *));

        int val;
        printf("\nEnter the data: ");
        scanf("%d", &val);

        NN2->data = val;
        NN2->next = NULL;

        if (start2 == NULL)
        {
            NN2->prev = NULL;
            start2 = NN2;
            current2 = NN2;
        }
        else
        {
            current2->next = NN2;
            NN2->prev = current2;
            current2 = NN2;
        }

        printf("\nEnter -1 to stop\n");
        scanf("%d", &ch);

    } while (ch != -1);
}

void concatenate()
{
    temp = start;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    temp->next = start2;
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

int main()
{
    create();
    create2();
    concatenate();
    display();
    return 0;
}