#include <stdio.h>
#define MAX 5

int rear = -1, front = -1;
int arr[MAX];

int isFull()
{
    if((front == 0 && rear == MAX -1) || ((rear + 1) % MAX == front))
    {
        return 1;
    }
    else 
    {
        return 0;
    }    
}

int isEmpty()
{
    if(front == -1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void enqueue(int val)
{
    if(isFull() == 1)
    {
        printf("Overflow\n");
    }    
    else
    {
        if(front == -1 && rear == -1)
        {
            front++;
            rear++;
        }
        else if(rear == MAX - 1 && front != 0)
        {
            rear = (rear + 1) % MAX;
        }
        else
        {
            rear++;
        }
        arr[rear] = val;
    }
}

void dequeue()
{
    if(isEmpty() == 1)
    {
        printf("Underflow\n");
    }
    else
    {
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if(front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}

void display()
{
    if(front <= rear)
    {
        for(int i = front; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    else
    {
        for(int i = front; i < MAX; i++)
        {
            printf("%d ", arr[i]);
        }
        for(int i = 0; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
    }    
}

int main()
{
    int cchoice;
    do
    {  
        int choice;
        printf("Operations on Circular Queue\n");
        printf("Enter 1 for enqueue\n");
        printf("Enter 2 for dequeue\n");
        printf("Enter 3 for display the queue\n");
        scanf("%d", &choice);
        int value;

        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        default:
            printf("Enter another choice\n");
            break;
        }

        printf("\nPress 1 to continue\n");
        printf("Press any other key to exit\n");
        scanf("%d", &cchoice);

    } while (cchoice == 1);  
       
    return 0;
}