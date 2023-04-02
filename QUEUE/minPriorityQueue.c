// Ascending Priority Queue or Min Priority Queue

#include <stdio.h>
#define MAX 10
int queue[MAX][2], front = -1, rear = -1;
int i, j, min, min_item; //min=2

void enqueue (int val, int priority)
{
    if (rear == MAX - 1)
    {
        printf("\n Queue is full");
    }
    else
    {
        if (front == - 1 && rear == -1) //1st insertion
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
            queue[rear][0] = val;
            queue[rear][1] = priority;
    }
}

getMinPriorityItem()
{
    min = queue[0][1];
    min_item = queue[0][0];
    for(i = front; i <= rear; i++)
    {
        for(j=0; j<=1; j++)
        {
            if (queue[i][1] > min) //2>2, 3>2, 1>2, 4>1
            {
                min = queue[i][1];
                min_item = queue[i][0];
            }
        }
    }

    printf("\nMinimum Priority Item: %d and priority: %d", min_item, min);
}

void dequeue()
{
    getMinPriorityItem();
    for (i = front; i <= rear; i++)
    {
        if (queue[i][0] == min_item && queue[i][1] == min)
        {
            for (j = i; j <= rear; j++)
            {
                queue[j][0] = queue[j+1][0];
                queue[j][1] = queue[j+1][1];
            }
            rear--;
            break;
        }
    }
}

void display()
{
    int i, j;
    printf("\nElements of priority queue are: \n");
    for( i= front; i <= rear; i++)
    {
        for(j=0; j<=1; j++)
        {
            printf(" %d ", queue[i][j]);
        }
        printf("\n");
    }
    // getMinPriorityItem();
}

int main()
{
    enqueue(10,2);
    enqueue(20,3);
    enqueue(30,1);
    enqueue(40,4);
    display();
    dequeue();
    display();
    return 0;
}