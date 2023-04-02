#include <stdio.h>
#define MAX 5
int front = -1, rear = -1, queue[MAX];

int peek()
{
    return queue[front];
}

int isFull()
{
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (front == - 1 || front > rear)
        return 1;
    else
        return 0;
}

void enqueue(int val)
{
    if (isFull() == 1)
    {
        printf("\nOverflow\n");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
        }
        else
        {
            rear++;
        }
        queue[rear] = val;
    }
}

void dequeue()
{
    if (isEmpty() == 1)
    {
        printf("\nUnderflow\n");
    }
    else
    {
        front++;
    }
}

void display()
{
    printf("\nQueue: ");
    for (int i= front; i<= rear; i++)
    {
        printf("%d ", queue[i]);
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
    enqueue(6);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
    dequeue();
    enqueue(1);
    display();
    return 0;
}