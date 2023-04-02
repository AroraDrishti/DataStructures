#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node * next;
};
    
struct node *start = NULL, *NN, *current, *temp;

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
            current = NN;
        }
        else
        {
            current->next = NN;
            current = NN;
        }

        printf("\nEnter -1 to stop ");
        scanf("%d", &ch);

    } while (ch != -1);
    
}

void display()
{
    temp = start;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    create();
    display();
    return 0;
}