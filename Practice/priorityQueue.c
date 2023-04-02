//Minimum Prioirity Queue
#include <stdio.h>
#define MAX 10

int front = -1, rear = -1;
int min_item, max, i, j;
int arr[MAX][2];

int isFull()
{
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

void enqueue(int value, int priority)
{
    if (isFull() == 1)
    {
        printf("Overflow");
    }
    else
    {
        if (front == -1 || rear == -1)
        {
            front++;
            rear++;
        }
        else
        {
            rear++;
        }
        arr[rear][0] = value;
        arr[rear][1] = priority;
    }
}

void getMinimumPriorityItem()
{
    max = arr[0][1];
    for (i = front; i <= rear; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (arr[i][1] > max)
            {
                max = arr[i][1];
                min_item = arr[i][0];
            }
        }
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
        getMinimumPriorityItem();
        if (arr[i][0] == min_item && arr[i][0] == max)
        {
            for (j = i; j <= rear; j++)
            {
                arr[j][0] = arr[j + 1][0];
                arr[j][1] = arr[j + 1][1];
            }
        }
        rear--;
    }
}

void display()
{
    printf("\nElements of priority queue are: \n");
    for (int i = front; i <= rear; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    enqueue(10, 2);
    enqueue(20, 3);
    enqueue(30, 1);
    enqueue(40, 4);
    display();
    dequeue();
    display();
    return 0;
}