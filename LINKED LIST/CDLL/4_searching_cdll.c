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

void display()
{
    temp = start;
    do
    {
        printf(" %d -> ", temp->data);
        temp = temp->next;
    }while(temp != start);
}

void search()
{
    temp = start;
    int num, i=1, flag = 1;
    printf("\nEnter the number to be searched: ");
    scanf("%d", &num);

    while(temp != NULL)
    {
        if(temp->data == num)
        {
            printf("\n%d is found at %d\n",num, i);
            flag = 0;
            break;
        }
        else
        {
            temp = temp->next;
            i++;
        }
    }
    if(flag == 1)
    {
        printf("\nElement not found.\n");
    }
}

int main()
{
    create();
    display();
    search();
    return 0;
}