#include <stdio.h>
#define MAX 5
int front = -1, rear = -1, queue[10];

void enqueue(int val)
{
    if(front == 0 && rear == MAX - 1)
    {
        printf("\nOverflow\n");
    }
    else if(front == -1 && rear == -1)
    {
        front++;
        rear++;
        queue[rear] = val;
    }
    else if(rear == MAX -1 && front != 0)
    {
        rear = 0;
        queue[rear] = val;
    }
    else
    {
        rear++;
        queue[rear] = val;
    }
}

int dequeue()
{
    int val;
    if (front == -1)
    {
        printf("\nUnderflow\n");
    }
    else if (front == rear)
    {
        val = queue[front];
        front = -1;
        rear = -1;
        return val;
    }
    else if(front == MAX - 1)
    {
        val = queue[front];
        front = 0;
        return val;
    }
    else
    {
        val = queue[front];
        front++;
        return val;
    }
}

void display()
{
    printf("\nElements in Circular Queue: ");
    if(front <= rear)
    {
        for(int i = front; i <= rear; i++)
        {
            printf(" %d ", queue[i]);
        }
    }
    else
    {
        for(int i = front; i <= MAX - 1; i++)
        {
            printf(" %d ", queue[i]);
        }
        for(int i = 0; i <= rear; i++)
        {
            printf(" %d ", queue[i]);
        }
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    
    enqueue(6);
    dequeue();
    dequeue();
    display();
    enqueue(7);
    enqueue(8);
    display();
    
    return 0;
}