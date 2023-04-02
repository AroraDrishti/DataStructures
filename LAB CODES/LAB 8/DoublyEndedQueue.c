#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int queue[MAX];
int front = -1, rear = -1;

void main()
{
    int ch, choice;
    int val;
    do
    {
        printf("Enter choice\n");
        printf("Enter 1 to insert at front\n");
        printf("Enter 2 to insert at end\n");
        printf("Enter 3 to delete from front\n");
        printf("Enter 4 to delete from end\n");
        printf("Enter 5 to display\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number to be inserted at the front: ");
            scanf("%d", &val);
            insertfront(val);
            break;

        case 2:
            printf("Enter number to be inserted at the end: ");
            scanf("%d", &val);
            insertend(val);
            break;

        case 3:
            deletefront();
            break;
        
        case 4:
            deleteend();
            break;
        
        case 5:
            printf("The elements of the queue are:\n");
            display();
            break;
        
        default:
            printf("Enter another choice.\n");
            break;
        
        }

        printf("Press 1 to continue.\n");
        scanf("%d", &ch);
    } while (ch == 1);
}

void insertfront(int val)
{
    if (front == 0 && rear == MAX - 1 || front > rear)
    {
        printf("Queue Overflow\n");
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        queue[front] = val;
    }
    else
    {
        rear++;
        queue[rear] = queue[rear - 1];
        for (int i = front; i < rear - 1; i++)
        {
            queue[i + 1] = queue[i];
        }
        queue[front] = val;
    }
}

void insertend(int val)
{
    if (front == 0 && rear == MAX - 1 || front > rear)
    {
        printf("Queue Overflow\n");
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = val;
    }
    else
    {
        rear++;
        queue[rear] = val;
    }
}

int deletefront()
{
    if ((front == -1 && rear == -1) || (front > rear))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Number deleted from the queue is: %d\n", queue[front]);
        front++;
    }
}

int deleteend()
{
    if ((front == -1 && rear == -1) || (front > rear))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Number deleted from the queue is: %d\n", queue[rear]);
        rear--;
    }
}

void display()
{
    if ((front == -1 && rear == -1) || (front > rear))
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}