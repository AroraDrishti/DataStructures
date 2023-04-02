// // #include <stdio.h>
// // #include <stdlib.h>

// // struct node 
// // {
// //     int data;
// //     struct node * next;
// // };
    
// // struct node *NN, *top = NULL, *temp, *start;

// // void push(int value)
// // {
// //     //dynamic memory allocation
// //     NN = (struct node *) malloc (sizeof(struct node*));

// //     if (top == NULL)
// //     {
// //         start = NN;
// //         NN->next = NULL;
// //         top = NN;
// //     }
// //     else
// //     {
// //         top->next = NN;
// //         NN->next = NULL;
// //         top = NN;
// //     }
// // }

// // void pop()
// // {
// //     if (top == NULL)
// //     {
// //         printf("Stack is empty\n");
// //     }
// //     else
// //     {
// //         temp = top;
// //         top = top->next;
// //         free(temp);
// //     }
// // }

// // void display()
// // {
// //     if (top == NULL)
// //     {
// //         printf("Stack is empty\n");
// //     }
// //     else
// //     {
// //         while(temp->next != NULL)
// //         printf("%d -> ", temp->data);
// //         temp = temp->next;
// //     }
// // }

// // int main()
// // {
// //     push(10);
// //     push(20);
// //     display();
// //     // pop();
// //     // display();
// //     return 0;
// // }

// #include <stdio.h>
// #include <stdlib.h>
// #include <conio.h>
// #include <string.h>

// struct stack 
// {
//     int data;
//     struct stack *next;
// };

// struct stack *NN, *top=NULL, *start=NULL, *temp, *temp2;

// void push()
// {
//     int val;
//     int ch;

//     printf("Enter data: ");
//     scanf("%d", &val);
//     NN=(struct stack *)malloc(sizeof(struct stack *));
//     NN->data=val;
//     NN->next=NULL;
//     if (top==NULL)
//     {
//         start=top=NN;
//     }
//     else
//     {
//         top->next=NN;
//         top=NN;
//     }
// }

// int pop()
// {
//     if (start==NULL)
//     {
//         printf("The stack is empty\n");
//     }
//     else
//     {
//         temp=start;
//         while (temp!=top)
//         {
//             temp2=temp;
//             temp=temp->next;
//         }
//         top=temp2;
//         printf("Number popped from the stack is: %d\n", temp->data);
//         free(temp);
//     }
// }

// void display()
// {
//     int i;
//     if (top==NULL)
//     {
//         printf("Stack is empty\n");
//     }
//     else
//     {
//         temp=start;
//         while (temp!=top)
//         {
//             printf("%d -> ", temp->data);
//             temp=temp->next;
//         }
//         printf("%d -> ",top->data);
//         printf("\n");
//     }
// }

// void main()
// {
//     int choice, ch;
//     do
//     {
//         printf("-----Main Menu-----\n");
//         printf("1. Push\n");
//         printf("2. Pop\n");
//         printf("3. Display\n");
//         printf("4. Exit\n");
//         printf("Enter your choice here: ");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//             case 1:
//             {
//                 int chpush;
//                 do
//                 {
//                     push();
//                     printf("Press 1 to push more elements: ");
//                     scanf("%d", &chpush);
//                 }while(chpush==1);
//                 break;
//             }
//             case 2:
//             {
//                 pop();
//                 break;
//             }
//             case 3:
//             {
//                 display();
//                 break;
//             }
//             case 4:
//             {
//                 printf("The program has ended\n");
//                 exit(0);
//             }
//             default:
//             {
//                 printf("Please enter a valid choice\n");
//                 break;
//             }
//         }
//         printf("Press 1 to continue: ");
//         scanf("%d", &ch);
//     }while (ch==1);
// }

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct queue
{
    int data;
    struct queue *next;
};

struct queue *NN, *rear=NULL, *front=NULL, *temp, *temp2;

void enqueue()
{
    int val;
    int ch;

    printf("Enter data: ");
    scanf("%d", &val);
    NN=(struct queue *)malloc(sizeof(struct queue *));
    NN->data=val;
    NN->next=NULL;
    if (rear==NULL)
    {
        front=rear=NN;
    }
    else
    {
        rear->next=NN;
        rear=NN;
    }
}

int dequeue()
{
    if (front==NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        temp=front;
        front=front->next;
        printf("Number dequeued is: %d\n", temp->data);
        free(temp);
    }
}

void display()
{
    int i;
    if (rear==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp=front;
        while (temp!=rear)
        {
            printf("%d -> ", temp->data);
            temp=temp->next;
        }
        printf("%d -> ",rear->data);
        printf("\n");
    }
}

void main()
{
    int choice, ch;
    do
    {
        printf("-----Main Menu-----\n");
        printf("1. enQueue\n");
        printf("2. deQueue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice here: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                int chpush;
                do
                {
                    enqueue();
                    printf("Press 1 to enQueue more elements: ");
                    scanf("%d", &chpush);
                }while(chpush==1);
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("The program has ended\n");
                exit(0);
            }
            default:
            {
                printf("Please enter a valid choice\n");
                break;
            }
        }
        printf("Press 1 to continue: ");
        scanf("%d", &ch);
    }while (ch==1);
}