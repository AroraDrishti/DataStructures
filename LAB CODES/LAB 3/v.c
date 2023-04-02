#include <stdio.h>
#include<stdlib.h>
#define MAX 10
 
void display(int arr[], int size){
    // Code for Traversal
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");   
}

int insertion(int arr[],int size,int num,int index){
    if(size>=MAX){
        printf("You can't insert");
    }else
    {
        size=size+1;
    }

    for(int i=size-1;i>=index;i--){//loop for shifting the number after the index towards right
        arr[i+1]=arr[i];
    }

    arr[index]=num;

    printf("Display of arr \n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    
}
int deletion(int arr[],int size,int index){
    for(int i=index;i<size-1;i++){//moving the elements towards left
        arr[i]=arr[i+1];
    }
    size-=1;
    printf("Display of arr \n");
    for( int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

}

int main(){
    int option;
     int arr[MAX],size,i,num,index,flag=0;
    printf("Enter the size of the array: " );
    scanf("%d",&size);

    printf("Enter the Elements in the array : ");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    do
    {
    printf("Choose the operation that you want to execute");
    printf("\n 1: transverse \n 2: insertion \n 3: Deletion \n 4:Exit \n ");
    scanf("%d",&option);

    

    switch (option)
    {
        case 1: {
            printf("Each Element of array");
            display(arr,size);
        }
        break;
        case 2:{
            printf("Enter the element that you want to insert: " );
            scanf("%d",&num);
            printf("Enter the index at which you want to insert: " );
            scanf("%d",&index);

            insertion(arr,size,num,index);
        }
        break;
        case 3:{
             printf("Enter the index at which you want to delete: " );
            scanf("%d",&index);

            deletion(arr,size,index);


        }
        break;
        case 4:{
            exit(0);
        }
    
            break;
    
    default: printf("The option entered is incorrect") ;
        break;

    }
    printf("\n Do you want to continue");
    int choice;
    printf("\n if yes press 1 and if no press 2 : ");
    scanf("%d",&choice);
    if(choice == 1){
        flag=1;
    }else{
        flag=0;
    }

    }while (flag==1);

    
    return 0;
}