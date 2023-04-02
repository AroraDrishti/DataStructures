#include <stdio.h>
#define MAX 20

int front = -1, rear = -1;
int arr[MAX];

int isFull()
{
    if(rear == MAX -1)
        return 1;
    else 
        return 0;
}

int isEmpty()
{
    if(front == -1 || front > rear)
        return 1;
    else 
        return 0;
}

void enqueue(int val)
{
    if(isFull() == 1)
    {
        printf("Overflow\n");
    }
    else
    {
        if(front == -1)
        {
            front++;
            rear++;
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
        printf("Element popped is %d\n", arr[front]);
        front++;
    }
}

int peek()
{
    return arr[front];
}

void display()
{
    for(int i = front; i <= rear; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int cchoice;
    do
    {  
        int choice;
        printf("Operations on Linear Queue\n");
        printf("Enter 1 for enqueue\n");
        printf("Enter 2 for dequeue\n");
        printf("Enter 3 for peek\n");
        printf("Enter 4 for display the queue\n");
        scanf("%d", &choice);
        int peekval;
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
            peekval = peek();
            printf("Element at the front is %d\n", peekval);
            break;
        
        case 4:
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