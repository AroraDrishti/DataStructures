#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 20

int arr[MAX];
int front1 = -1, rear1 = -1;
int front2 = MAX, rear2 = MAX;

void main()
{
    int ch, choice, val;
    do
    {
        printf("Enter the choice\n");
        printf("Enter 1 insert in Queue-1\n");
        printf("Enter 2 insert in Queue-2\n");
        printf("Enter 3 delete from Queue-1\n");
        printf("Enter 4 delete from Queue-2\n");
        printf("Enter 5 display Queue-1 and Queue-2\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number to be inserted in Queue-1: ");
            scanf("%d", &val);
            enQueue1(val);
            break;

        case 2:
            printf("Enter number to be inserted in Queue-2: ");
            scanf("%d", &val);
            enQueue2(val);
            break;

        case 3:
            deQueue1();
            break;

        case 4:
            deQueue2();
            break;

        case 5:
            printf("\n");
            display();
            break;

        default:
            printf("Enter another choice\n");
            break;
        }

        printf("Press 1 to continue\n");
        scanf("%d", &ch);
    } while (ch == 1);
}

void enQueue1(int val)
{
    int i;
    if (rear1 == rear2 - 1)
    {
        printf("Queue Overflow\n");
    }
    else if (front1 == -1 && rear1 == -1)
    {
        front1 = 0;
        rear1 = 0;
        arr[rear1] = val;
    }
    else
    {
        rear1++;
        arr[rear1] = val;
    }
}

void enQueue2(int val)
{
    int i;
    if (rear2 == rear1 + 1)
    {
        printf("Queue Overflow\n");
    }
    else if (front2 == MAX && rear2 == MAX)
    {
        front2 = MAX - 1;
        rear2 = MAX - 1;
        arr[rear2] = val;
    }
    else
    {
        rear2--;
        arr[rear2] = val;
    }
}

int deQueue1()
{
    if ((front1 == -1 && rear1 == -1) || (front1 > rear1))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Number deleted from Queue-1 is: %d\n", arr[front1]);
        front1++;
    }
}

int deQueue2()
{
    if ((front2 == MAX && rear2 == MAX) || (front2 < rear2))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Number deleted from Queue-2 is: %d\n", arr[front2]);
        front2--;
    }
}

void display()
{
    if (front1 == -1)
    {
        printf("Queue-1 is empty\n");
    }
    else
    {
        for (int i = front1; i <= rear1; i++)
        {
            printf("%d ", arr[i]);
        }
    }

    if (rear2 == MAX)
    {
        printf("Queue-2 is empty\n");
    }
    else
    {
        for (int j = front2; j >= rear2; j--)
        {
            printf("%d ", arr[j]);
        }
    }
    printf("\n");
}