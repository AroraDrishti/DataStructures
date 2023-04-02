#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node *temp, *temp2, *start =NULL, *NN, *current, *temp3;

void create()
{
    int val, ch;
    do
    {
        printf("\n enter the number");
        scanf("%d", &val);

        NN = (struct node*) malloc(sizeof(struct node*));

        if(start == NULL) //LL is mepty
        {
            start ==NN;
            current ==NN;
        }
        else
        {
            current->next == NN;
            current == NN;
        }

        printf("\n press -1 to stop");
        scanf("%d", &ch);
    } while (ch != -1);
    
}

void display()
{
    temp = start;
    printf("Elements of SLL");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

void deletestart()
{
    if(start == current)
    {
        start = NULL;
        current = NULL;
    }
    else
    {
        temp = start->next;
        start = temp;
    }
}

void deleteend()
{
    if(start == current)
    {
        start = NULL;
        current = NULL;
    }
    else
    {
        temp = start;
        while(temp != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        printf("\nlast element: %d, second last element: %d", temp->data, temp2->data);

        free(temp);
        temp2->next = NULL;
        current = temp2;
    }
    
}

void deletebefore()
{
    int val;
    if(start == current)
    {
        start = NULL;
        current = NULL;
    }
    else
    {
        printf("\nEnter the number before which is to be deleted ");
        scanf("%d", &val);
        temp = start;
        temp2 = start;
        temp3 = start;

        while(temp->data != val)
        {
            temp3 = temp2;
            temp2 = temp;
            temp = temp->next;
        }

        temp3->next = temp;
        free(temp2);
    }
}

void deleteafter()
{
    int val;
    if(start == current)
    {
        start = NULL;
        current = NULL;
    }
    else
    {
        printf("\nEnter the number before which is to be deleted ");
        scanf("%d", &val);
        temp = start;
        
        while(temp->data != val)
        {
            temp = temp->next;
        }

        temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}

int main()
{
    create();
    display();
    // deletestart();
    // deleteend();
    deletebefore();
    deleteafter();
    display();
    return 0;
}