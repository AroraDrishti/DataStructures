e;
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
 