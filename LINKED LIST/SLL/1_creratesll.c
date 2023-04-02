#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node * next;
};

int main()
{
    struct node *head, *one, *two, *three, *temp;

    //dynamic memory allocation
    one = (struct node*) malloc (sizeof(struct node *));
    two = (struct node*) malloc (sizeof(struct node *));
    three = (struct node*) malloc (sizeof(struct node *));

    //set data
    one->data = 1;
    two->data = 2;
    three->data = 3;

    //linking nodes
    one->next = two;
    two->next = three;
    three->next = NULL;

    //set head at the starting
    head = one;

    //display
    temp = head;
    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}