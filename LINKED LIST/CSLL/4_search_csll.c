#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node * next;
};
    
struct node *start = NULL, *NN, *temp;

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

void search()
{
    int num, i = 1, flag = 0;
    printf("\nEnter the value to be searched: ");
    scanf("%d", &num);

    temp = start;
    
    while(temp != NULL)
    {
        if(temp->data == num)
        {
            flag = 1;
            printf("\n%d found at %d", temp->data, i);
            break;
        }
        else
        {
            temp = temp->next;
            i++;
        }
    }

    if(flag == 0)
    {
        printf("\nElement not found\n");
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
    search();
    return 0;
}