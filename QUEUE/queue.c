#include <stdio.h>
#define MAX 5
int front = -1, rear = -1, queue[MAX];

// int peek()
// {
//     return queue[front];
// }

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
        printf("Overflow");
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
        printf("Underflow");
    }
    else
    {
        front++;
    }
}

void display()
{
    printf("\nFront = %d, Rear = %d", front, rear);

    printf("\nQueue values: ");
    for (int i= front; i<= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    dequeue();
    // dequeue();
    // dequeue();
    // dequeue();
    // dequeue();
    // dequeue();
    display();
    return 0;
}