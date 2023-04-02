#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *NN, *start, *current, *temp, *temp2;

void create()
{
    int ch = 1;
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

void insertionatstart()
{
    NN = (struct node *) malloc (sizeof(struct node *));

    int val;
    printf("\nEnter the data to be inseted at the beginning: ");
    scanf("%d", &val);

    NN->data = val;
    NN->prev = NULL;
    NN->next = NULL;

    if(start == NULL)
    {
        NN->next = start;
        NN->prev = start;
        start = NN;
    }
    else
    {
        temp = start;
        do
        {
            temp = temp->next;
        } while (temp->next != start);
        
        NN->next = start;
        start->prev = NN;
        temp->next = NN;
        NN->prev = temp;
        start = NN;
    }
}

void insertionatgivenposition()
{
    NN = (struct node *) malloc (sizeof(struct node *));

    int pos;
    printf("\nEnter the position at which data is to be inserted: ");
    scanf("%d", &pos);

    int val;
    printf("\nEnter the data to be inserted at %d position: ", pos);
    scanf("%d", &val);

    NN->data = val;
    NN->prev = NULL;
    NN->next = NULL;

    if(start == NULL)
    {
        NN->next = start;
        NN->prev = start;
        start = NN;
    }
    else
    {
        temp = start;
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        
        NN->next = temp->next;
        temp->next->prev = NN;
        temp->next = NN;
        NN->prev = temp;
    }
}

void insertionbeforegivenposition()
{
    NN = (struct node *) malloc (sizeof(struct node *));

    int pos;
    printf("\nEnter the position before which data is to entered: ");
    scanf("%d", &pos);

    int val;
    printf("\nEnter the data to be entered before %d position: ", pos);
    scanf("%d", &val);

    NN->data = val;   

    if(start == NULL)
    {
        NN->prev = NULL;
        NN->next = NULL;
        start = NN;
    }
    else
    {
        temp = start;
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp2 = temp->prev;
        temp->prev = NN;
        NN->next = temp;
        NN->prev = temp2;
        temp2->next = NN;
    }
}

void insertionaftergivenposition()
{
    NN = (struct node *) malloc (sizeof(struct node *));

    int pos;
    printf("\nEnter the position after which data is to entered: ");
    scanf("%d", &pos);

    int val;
    printf("\nEnter the data to be entered after %d position: ", pos);
    scanf("%d", &val);

    NN->data = val;   

    if(start == NULL)
    {
        NN->prev = NULL;
        NN->next = NULL;
        start = NN;
    }
    else
    {
        temp = start;
        for(int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->next->prev = NN;
        NN->next = temp->next;
        NN->prev = temp;
        temp->next = NN;
    }
}

void insertionatend()
{
    NN = (struct node *) malloc (sizeof(struct node *));

    int val;
    printf("\nEnter the data to be inserted at the end: ");
    scanf("%d", &val);

    NN->data = val;
    NN->prev = NULL;
    NN->next = NULL;

    if(start == NULL)
    {
        NN->next = start;
        NN->prev = start;
        start = NN;
    }
    else
    {
        temp = start;
        do
        {
            temp = temp->next;
        } while (temp->next != start);

        temp->next = NN;
        NN->prev = temp;
        NN->next = start;
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
        temp = start;
        do
        {
            temp = temp->next;
        } while (temp->next != start);
        
        start->next->prev = temp;
        temp->next = start->next;
        start = start->next;
    }
}

void deletionatgivenposition()
{
    if(start == NULL)
    {
        //do nothing
    }
    else
    {
        int pos;
        printf("\nEnter the position from which element is to deleted: ");
        scanf("%d", &pos);

        temp = start;
        for(int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        
        temp->prev->next = temp->next;
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
        printf("\nEnter the position before which element is to deleted: ");
        scanf("%d", &pos);

        temp = start;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next; 
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
        printf("\nEnter the position after which element is to deleted: ");
        scanf("%d", &pos);

        temp = start;
        for (int i = 1; i < pos + 1; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next; 
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
        temp = start;
        do
        {
            temp = temp->next;
        } while (temp->next != start);
        
        temp->prev->next = start;
        start->prev = temp->prev;
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
            temp = temp->next;
            count++;
        }
        printf("\n%d is found at %d position\n", temp->data, count);
        temp->prev->next = temp->next;
    }
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

void display()
{
    temp = start;
    do
    {
        printf(" %d -> ", temp->data);
        temp = temp->next;
    }while(temp != start);
}

int main()
{
    int ch;
    do
    {
        int choice;
        printf("\nEnter the choice: \n");
        printf("Enter 1 for creation of CDLL\n");
        printf("Enter 2 for insertion at the beginning of CDLL\n");
        printf("Enter 3 for insertion at a given position of CDLL\n");
        printf("Enter 4 for insertion before a given position of CDLL\n");
        printf("Enter 5 for insertion after a given position of CDLL\n");
        printf("Enter 6 for insertion at the end of CDLL\n");
        printf("Enter 7 for deletion from the beginning of CDLL\n");
        printf("Enter 8 for deletion from a given position of CDLL\n");
        printf("Enter 9 for deletion before a given position of CDLL\n");
        printf("Enter 10 for deletion after a given position of CDLL\n");
        printf("Enter 11 for deletion at the end of CDLL\n");
        printf("Enter 12 for deletion by value of CDLL\n");
        printf("Enter 13 for searching in CDLL\n");
        printf("Enter 14 for display CDLL\n");
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
            insertionatgivenposition();
            break;

        case 4:
            insertionbeforegivenposition();
            break;

        case 5:
            insertionaftergivenposition();
            break;

        case 6:
            insertionatend();
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