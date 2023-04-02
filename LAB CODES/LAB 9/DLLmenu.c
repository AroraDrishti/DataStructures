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
    int ch;
    do
    {
        NN = (struct node *)malloc(sizeof(struct node *));

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

void display()
{
    temp = start;
    while (temp != NULL)
    {
        printf(" %d -> ", temp->data);
        temp = temp->next;
    }
    printf(" NULL");
}

void insertionatstart()
{
    NN = (struct node *)malloc(sizeof(struct node *));

    int val;
    printf("\nEnter the data: ");
    scanf("%d", &val);

    NN->data = val;
    NN->prev = NULL;

    if (start == NULL)
    {
        NN->next = NULL;
        start = NN;
    }
    else
    {
        NN->next = start;
        start->prev = NN;
        start = NN;
    }
}

void insertionatend()
{
    NN = (struct node *)malloc(sizeof(struct node *));

    int val;
    printf("\nEnter the data: ");
    scanf("%d", &val);

    NN->data = val;
    NN->next = NULL;

    if (start == NULL)
    {
        NN->next = NULL;
        start = NN;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NN;
        NN->prev = temp;
    }
}

void insertionatgivenposition()
{
    NN = (struct node *)malloc(sizeof(struct node *));

    int pos;
    printf("\nEnter the position at which data is to entered: ");
    scanf("%d", &pos);

    int val;
    printf("\nEnter the data to be entered at %d position: ", pos);
    scanf("%d", &val);

    NN->data = val;

    if (start == NULL)
    {
        NN->prev = NULL;
        NN->next = NULL;
        start = NN;
    }
    else
    {
        temp = start;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next->prev = NN;
        NN->next = temp->next;
        NN->prev = temp;
        temp->next = NN;
    }
}

void insertionbeforegivenposition()
{
    NN = (struct node *)malloc(sizeof(struct node *));

    int pos;
    printf("\nEnter the position before which data is to entered: ");
    scanf("%d", &pos);

    int val;
    printf("\nEnter the data to be entered before %d position: ", pos);
    scanf("%d", &val);

    NN->data = val;

    if (start == NULL)
    {
        NN->prev = NULL;
        NN->next = NULL;
        start = NN;
    }
    else
    {
        temp = start;
        for (int i = 1; i < pos - 1; i++)
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
    NN = (struct node *)malloc(sizeof(struct node *));

    int pos;
    printf("\nEnter the position after which data is to entered: ");
    scanf("%d", &pos);

    int val;
    printf("\nEnter the data to be entered after %d position: ", pos);
    scanf("%d", &val);

    NN->data = val;

    if (start == NULL)
    {
        NN->prev = NULL;
        NN->next = NULL;
        start = NN;
    }
    else
    {
        temp = start;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->next->prev = NN;
        NN->next = temp->next;
        NN->prev = temp;
        temp->next = NN;
    }
}

void deletionatstart()
{
    if (start == NULL)
    {
        // do nothing
    }
    else
    {
        temp = start;
        start = temp->next;
        temp->prev = NULL;
    }
}

void deletionatgivenposition()
{
    if (start == NULL)
    {
        // do nothing
    }
    else
    {
        int pos;
        printf("\nEnter the position from which element is to deleted: ");
        scanf("%d", &pos);

        temp = start;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
    }
}

void deletionbeforegivenposition()
{
    if (start == NULL)
    {
        // do nothing
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
    if (start == NULL)
    {
        // do nothing
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

void deletionbyvalue()
{
    if (start == NULL)
    {
        // do nothing
    }
    else
    {
        int count = 1, val;
        temp = start;

        printf("\nEnter the value to be deleted: ");
        scanf("%d", &val);

        while (temp->data != val)
        {
            temp = temp->next;
            count++;
        }
        printf("\n%d is found at %d position\n", temp->data, count);
        temp->prev->next = temp->next;
    }
}

void deletionatend()
{
    if (start == NULL)
    {
        // do nothing
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
    }
}

void search()
{
    temp = start;
    int num, i = 1, flag = 1;
    printf("\nEnter the number to be searched: ");
    scanf("%d", &num);

    while (temp != NULL)
    {
        if (temp->data == num)
        {
            printf("\n%d is found at %d\n", num, i);
            flag = 0;
            break;
        }
        else
        {
            temp = temp->next;
            i++;
        }
    }
    if (flag == 1)
    {
        printf("\nElement not found.\n");
    }
}

int main()
{
    int ch = 1;
    do
    {
        int choice;
        printf("\nEnter the choice: \n");
        printf("Enter 1 for creation of DLL\n");
        printf("Enter 2 for insertion at the beginning of DLL\n");
        printf("Enter 3 for insertion at a given position of DLL\n");
        printf("Enter 4 for insertion at the end of DLL\n");
        printf("Enter 5 for deletion from the beginning of DLL\n");
        printf("Enter 6 for deletion from a given position of DLL\n");
        printf("Enter 7 for deletion at the end of DLL\n");
        printf("Enter 8 for deletion by value of DLL\n");
        printf("Enter 9 for searching in DLL\n");
        printf("Enter 10 for display DLL\n");
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
            insertionatend();
            break;

        case 5:
            deletionatstart();
            break;

        case 6:
            deletionatgivenposition();
            break;

        case 7:
            deletionatend();
            break;

        case 8:
            deletionbyvalue();
            break;

        case 9:
            search();
            break;

        case 10:
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