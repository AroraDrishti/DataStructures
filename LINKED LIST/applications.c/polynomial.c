#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *NN, *start1 = NULL, *start2 = NULL, *current, *temp, *temp1, *temp2, *result, *startresult = NULL;

void create1()
{
    int ch1;
    do
    {
        NN = (struct node *) malloc (sizeof(struct node *));
        NN->next = NULL;

        printf("\nEnter coefficient for list 1: ");
        scanf("%d", &NN->coeff);
        printf("\nEnter exponent for list 1: ");
        scanf("%d", &NN->exp);

        if(start1 == NULL)
        {
            start1 = NN;
            current = NN;
        }
        else
        {
            current->next = NN;
            current = NN;
        }

        printf("\nEnter -1 to stop: ");
        scanf("%d", &ch1);
    } while (ch1 != -1);
}

void create2()
{
    int ch2;
    do
    {
        NN = (struct node *) malloc (sizeof(struct node *));
        NN->next = NULL;

        printf("\nEnter coefficient for list 2: ");
        scanf("%d", &NN->coeff);
        printf("\nEnter exponent for list 2: ");
        scanf("%d", &NN->exp);

        if(start2 == NULL)
        {
            start2 = NN;
            current = NN;
        }
        else
        {
            current->next = NN;
            current = NN;
        }

        printf("\nEnter -1 to stop: ");
        scanf("%d", &ch2);

    } while (ch2 != -1);
}

void display1()
{
    temp = start1;
    while(temp != NULL)
    {
        printf("\nCoefficient-> %d", temp->coeff);
        printf("\nExponent-> %d", temp->exp);
        temp = temp->next;
    }
}

void display2()
{
    temp = start2;
    while(temp != NULL)
    {
        printf("\nCoefficient-> %d", temp->coeff);
        printf("\nExponent-> %d", temp->exp);
        temp = temp->next;
    }
}

void add()
{
    temp1 = start1;
    temp2 = start2;
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->exp == temp2->exp)
        {
            result->exp = temp1->exp;
            result->coeff = temp1->coeff + temp2->exp;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}

void displayresult()
{
    temp = startresult;
    while(temp != NULL)
    {
        printf("\nCoefficient-> %d", temp->coeff);
        printf("\nExponent-> %d", temp->exp);
        temp = temp->next;
    }
}

int main()
{
    create1();
    create2();
    add();
    displayresult();
    return 0;
}