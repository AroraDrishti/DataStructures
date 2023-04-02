#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void InsertionAtIndex(int, int[]);
void InsertionAtBeginning(int, int[]);
void InsertionBeforeGivenIndex(int, int[]);
void InsertionAfterGivenIndex(int, int[]);
void Deletion(int, int[]);
void Traversal(int, int[]);

int main()
{
    int n, i, index, arr[MAX], choice, flag;
    
    do
    {
        printf("Enter the size of the array: ");
        scanf("%d", &n);

        for (i = 0; i < n; i++)
        {
            printf("Enter the element at index %d: ", i);
            scanf("%d", &arr[i]);
        }

        printf("\nEnter choice\n");
        printf("1: Insertion at a given index\n");
        printf("2: Insertion at the beginning\n");
        printf("3: Insertion before the given index\n");
        printf("4: Insertion after the given index\n");
        printf("5: Deletion of an element\n");
        printf("6: Traversal in an array\n");
        printf("7: Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            InsertionAtIndex(n, arr);
            break;

        case 2:
            InsertionAtBeginning(n, arr);
            break;

        case 3:
            InsertionBeforeGivenIndex(n, arr);
            break;

        case 4:
            InsertionAfterGivenIndex(n, arr);
            break;

        case 5:
            Deletion(n, arr);
            break;

        case 6:
            Traversal(n, arr);
            break;

        case 7:
            exit(0);
            break;

        default:
            printf("Enter another choice");
            break;
        }

        printf("\nDo you want to continue\n");
        int num;
        printf("1: Yes\n");
        printf("0: No\n");
        scanf("%d", &num);
        if (num == 1)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            printf("Program ends");
        }
    } while (flag == 1);

    return 0;
}

void InsertionAtIndex(int n, int arr[])
{
    int index, ins;
    printf("Enter the index at which element is to be added: ");
    scanf("%d", &index);

    printf("Enter the element to be inserted: ");
    scanf("%d", &ins);

    if (n == MAX)
    {
        printf("Insertion not possible.");
    }
    else
    {
        n = n + 1;

        for (int i = n - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }

        arr[index] = ins;

        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}

void InsertionAtBeginning(int n, int arr[])
{
    int ins;
    printf("Enter the element to be inserted: ");
    scanf("%d", &ins);
    if (n == MAX)
    {
        printf("Insertion not possible.");
    }
    else
    {
        n = n + 1;
        
        for (int i = n - 1; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }

        arr[0] = ins;
        
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}

void InsertionBeforeGivenIndex(int n, int arr[])
{
    int index, ins;
    printf("Enter the index before which element is to be added: ");
    scanf("%d", &index);

    printf("Enter the element to be inserted: ");
    scanf("%d", &ins);

    if (n == MAX)
    {
        printf("Insertion not possible.");
    }
    else
    {
        n = n + 1;
        for (int i = n - 1; i >= index - 1; i--)
        {
            arr[i + 1] = arr[i];
        }

        arr[index - 1] = ins;

        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}

void InsertionAfterGivenIndex(int n, int arr[])
{
    int index, ins;
    printf("Enter the index after which element is to be added: ");
    scanf("%d", &index);

    printf("Enter the element to be inserted: ");
    scanf("%d", &ins);

    if (n == MAX)
    {
        printf("Insertion not possible.");
    }
    else
    {
        n = n + 1;
        for (int i = n - 1; i >= index + 1; i--)
        {
            arr[i + 1] = arr[i];
        }

        arr[index + 1] = ins;

        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}

void Deletion(int n, int arr[])
{
    int del, index;
    printf("Enter the element to be deleted: ");
    scanf("%d", &del);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == del)
        {
            index = i;

            for (i = index; i < n; i++)
            {
                arr[i] = arr[i + 1];
            }

            n = n - 1;
            
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
        }
    }
}

void Traversal(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}