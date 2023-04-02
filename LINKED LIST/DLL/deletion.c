#include <stdio.h>

struct node
{
    int data;
    struct node *next;
    ​struct node *prev;
};

struct node *start = NULL, *current, *NN, *temp, *temp2, *temp3;

void display()
{
    ​
    temp = start;
    printf("\n Elements of DLL: ");
    while (temp != NULL)
    {
        ​
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    ​
}

void create()
{
    ​int ch, val;
    do
    {
        ​
        printf("\n enter the no.: ");
        scanf("%d", &val);
        NN = (struct node *)malloc(sizeof(struct node *));
        NN->data = val;
        NN->prev = NULL;
        NN->next = NULL;
        if (start == NULL)
        {
            ​
            start = NN;
            current = NN;
        }
        ​else
        {
            ​
                current->next = NN;
            NN->prev = current;
            current = NN;
        }
        ​
            printf("\n Press -1 to stop");
        scanf("%d", &ch);
    }
    ​while(ch != -1);
}

void deletestart()
{
    ​if (start == NULL)
    {
        ​
        printf("\n Underflow");
    }
    ​else
    {
        ​
        temp = start;
        start = start->next;
        start->prev = NULL;
        free(temp);
    }
    ​
}
​ 
void deleteend()
{
    ​ if (start == NULL)
    {
        ​
        printf("\n Underflow");
    }
    ​ else
    {
        ​
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp2 = temp->prev;
        temp2->next = NULL;
        free(temp);
    }
    ​
}
​ 
void deletemid()
{
    ​int val;
    if (start == NULL)
    {
        ​
        printf("\n Underflow");
    }
    ​else
    {
        ​
        printf("\n enter no. to be deleted: ");
        scanf("%d", &val);
        temp = start;
        while (temp->data != val)
            temp = temp->next;
        temp3 = temp->prev;
        temp2 = temp3->prev;
        // t2 -> t3 -> t
        temp->prev = temp2;
        temp2->next = temp;
        free(temp3);
    }
    ​
}
​ void main()
{
    create();
    display();
    deletestart();
    display();
    deleteend();
    display();
    deletemid();
    display();
}
​