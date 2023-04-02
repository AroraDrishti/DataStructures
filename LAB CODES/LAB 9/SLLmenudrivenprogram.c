#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node * next;
};
    
struct node *start = NULL, *NN, *current, *temp, *temp2, *temp3;

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

void insertionatstart()
{
    //dynamic memory allocation
    NN = (struct node *) malloc (sizeof(struct node*));

    int val;
    printf("\n\nEnter data to insert at the beginning: ");
    scanf("%d", &val);

    NN->data = val;
    NN->next = NULL;

    if(start == NULL)
    {
        start = NN;
    }
    else
    {
        NN->next = start;
        start = NN;
    }
}

void insertionatmid()
{
    //dynamic memory allocation
    NN = (struct node *) malloc (sizeof(struct node*));

    int val, pos;
    printf("\n\nEnter the position: ");
    scanf("%d", &pos);
    printf("\nEnter data to insert at %d position: ", pos);
    scanf("%d", &val);

    NN->data = val;
    NN->next = NULL;

    if(start == NULL)
    {
        start = NN;
    }
    else
    {
        temp = start;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        NN->next = temp->next; 
        temp->next = NN;
    }
}

void insertionbeforegivenposition()
{
    //dynamic memory allocation
    NN = (struct node *) malloc (sizeof(struct node*));

    int val, pos;
    printf("\n\nEnter the position: ");
    scanf("%d", &pos);
    printf("\nEnter data to insert before %d position: ", pos);
    scanf("%d", &val);

    NN->data = val;
    NN->next = NULL;

    if(start == NULL)
    {
        start = NN;
    }
    else
    {
        temp = start;
        for(int i = 1; i < pos - 1; i++)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NN;
        NN->next = temp;
    }
}

void insertionaftergivenposition()
{
    //dynamic memory allocation
    NN = (struct node *) malloc (sizeof(struct node*));

    int val, pos;
    printf("\n\nEnter the position: ");
    scanf("%d", &pos);
    printf("\nEnter data to insert after %d position: ", pos);
    scanf("%d", &val);

    NN->data = val;
    NN->next = NULL;

    if(start == NULL)
    {
        start = NN;
    }
    else
    {
        temp = start;
        for(int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        NN->next = temp->next;
        temp->next = NN;
    }
}

void insertionatlast()
{
    //dynamic memory allocation
    NN = (struct node *) malloc (sizeof(struct node*));

    int val;
    printf("\n\nEnter data to insert at the end: ");
    scanf("%d", &val);

    NN->data = val;
    NN->next = NULL;

    if(start == NULL)
    {
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
    }
}

void deletionatstart()
{
    if(start == NULL)
    {
        //do nothing
    }
    else
    {
        temp = start->next;
        start = temp;
    }
}

void deletionatgivenposition()
{
    int pos;
    printf("\nEnter the position at which the element has to be deleted: ");
    scanf("%d", &pos);

    if(start == NULL)
    {
        //do nothing
    }

    else if (start->next == NULL)
    {
        start = NULL;
    }

    else
    {
        temp = start->next;
        temp2 = start;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
            temp2 = temp2->next;
        }
        temp2->next = temp->next;
    }
}

void deletionbeforegivenposition()
{
    if(start == NULL)
    {
        //do nothing
    }
    else
    {
        int pos;
        printf("\nEnter the position before which the element has to be deleted: ");
        scanf("%d", &pos);

        temp = start->next->next;
        temp2 = start->next;
        temp3 = start;

        if(pos == 2)
        {
            start->next = start->next->next;
        }
        else if(pos == 3)
        {
            start->next->next = start->next->next->next;
        }
        else
        {
            for(int i = 3; i < pos; i++)
            {
                temp = temp->next;
                temp2 = temp2->next;
                temp3 = temp3->next;
            }
            temp3->next = temp2->next;

        }
    }
}

void deletionaftergivenposition()
{
    if(start == NULL)
    {
        //do nothing
    }
    else
    {
        int pos;
        printf("\nEnter the position after which the element has to be deleted: ");
        scanf("%d", &pos);
        temp = start;
        for(int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
}

void deletionatend()
{
    if(start == NULL)
    {
        //do nothing
    }
    else
    {
        temp = start->next;
        temp2 = start;

        while(temp->next != NULL)
        {
            temp = temp->next;
            temp2 = temp2->next;
        }
        temp2->next = NULL;
    }
}

void deletionbyvalue()
{
    if(start == NULL)
    {
        //do nothing
    }
    else
    {
        int count = 1, val;
        temp = start;

        printf("\nEnter the value to be deleted: ");
        scanf("%d", &val);
        
        while(temp->data != val)
        {
            temp2 = temp;
            temp = temp->next;
            count++;
        }
        printf("\n%d is found at %d position\n", temp->data, count); 
        temp2->next = temp->next;
    }
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
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    int ch = 1;
    do
    {
        int choice;
        printf("\nEnter the choice: \n");
        printf("Enter 1 for creation of SLL\n");
        printf("Enter 2 for insertion at the beginning of SLL\n");
        printf("Enter 3 for insertion at a given position of SLL\n");
        printf("Enter 4 for insertion before a given position of SLL\n");
        printf("Enter 5 for insertion after a given position of SLL\n");
        printf("Enter 6 for insertion at the end of SLL\n");
        printf("Enter 7 for deletion from the beginning of SLL\n");
        printf("Enter 8 for deletion from a given position of SLL\n");
        printf("Enter 9 for deletion before a given position of SLL\n");
        printf("Enter 10 for deletion after a given position of SLL\n");
        printf("Enter 11 for deletion at the end of SLL\n");
        printf("Enter 12 for deletion by value of SLL\n");
        printf("Enter 13 for searching in SLL\n");
        printf("Enter 14 for display SLL\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;

        case 2:
            insertionatstart();
            break;

        case 3:
            insertionatmid();
            break;

        case 4:
            insertionbeforegivenposition();
            break;

        case 5:
            insertionaftergivenposition();
            break;

        case 6:
            insertionatlast();
            break;

        case 7:
            deletionatstart();
            break;

        case 8:
            deletionatgivenposition();
            break;

        case 9:
            deletionbeforegivenposition();
            break;

        case 10:
            deletionaftergivenposition();
            break;

        case 11:
            deletionatend();
            break;

        case 12:
            deletionbyvalue();
            break;

        case 13:
            search();
            break;

        case 14:
            display();
            break;

        default:
            printf("\nEnter another choice");
            break;
        }

        printf("\nEnter 1 to continue\n");
        scanf("%d", &ch);
    } while (ch == 1);
    return 0;
}