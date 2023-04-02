#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 20

int queue[MAX], p[MAX];
int front = -1, rear = -1;

void main()
{
    int ch, choice;
    int val, priority;
    do
    {
        printf("Enter the choice\n");
        printf("Enter 1 to enQueue\n");
        printf("Enter 2 to deQueue\n");
        printf("Enter 3 to display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number to be inserted: ");
            scanf("%d", &val);
            printf("Enter priority of the number to be inserted: ");
            scanf("%d", &priority);
            enqueue(val, priority);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            printf("The elements of the queue and their priorities are: \n");
            display();
            break;

        case 4:
            printf("The program has ended\n");
            exit(0);

        default:
            printf("Please enter a valid choice.\n");
            break;
        }

        printf("Press 1 to continue\n");
        scanf("%d", &ch);
    } while (ch == 1);
}

void enqueue(int val, int priority)
{
    int i;
    if (front == 0 && rear == MAX - 1)
    {
        printf("Queue overflow\n");
    }
    else if (front == -1)
    {
        front = rear = 0;
        queue[rear] = val;
        p[rear] = priority;
    }
    else if (rear == MAX - 1)
    {
        for (i = front; i <= rear; i++)
        {
            queue[i - front] = queue[i];
            p[i - front] = p[i];
            rear = rear - front;
            front = 0;
        }
        for (i = front; i <= rear; i++)
        {
            if (priority < p[i])
            {
                queue[i + 1] = queue[i];
                p[i + 1] = p[i];
            }
            else
                break;
            queue[i + 1] = val;
            p[i + 1] = priority;
            rear++;
        }
    }
    else
    {
        for (i = rear; i >= front; i--)
        {
            if (priority < p[i])
            {
                queue[i + 1] = queue[i];
                p[i + 1] = p[i];
            }
            else
                break;
        }
        queue[i + 1] = val;
        p[i + 1] = priority;
        rear++;
    }
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("The number deleted from the queue is: %d\n", queue[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
}

void display()
{
    int i;
    if ((front == -1 && rear == -1) || (front > rear))
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d\t%d\n", queue[i], p[i]);
        }
    }
    printf("\n");
}