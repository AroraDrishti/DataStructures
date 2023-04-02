/*	BOILER PLATE
NAME OF STUDENT: Deergh Kataria
CLASS & SECTION: 3CSE1 (X)
ENROLLMENT NO: A2305220099

NAME OF THE PRACTICAL: Lab Assignment-5

VARIABLE USED: cString, cStack, iTop, postExp, preExp, cCounter, fLoop, iStack, fLoop, rSize, cString1, cComp,
SIZE, x, revString, oP1, oP2, iChoice, cChoice
FUNCTIONS USED: Push, Pop, Display, isEmpty, isFull, Prec, Postfix, Prefix, Eval, calc, iStack, iPush
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 20

void Push(char);    // For Pushing Operation
void Pop();         // For Popping Operation
void Display();   // For Displaying
int isEmpty();      // To check whether a Stack is Empty or not
int isFull();       // To check whether a Stack is Full or not
int Prec(char);     // For checking the precedence of the operators
const char* Postfix(char* ,int);       // For Postfix Operation
void Prefix(char*,int);         // For Prefix Operation
void Eval(char* , int );    // For Evaluation of the Expression
int calc(int , int, char);  

char cString[SIZE];     // For Taking Input of Expression
char cStack[SIZE];      // For Stack
int iTop = -1;          // Top of the Stack
char postExp[20];       // Expression for Post Fix
char preExp[20];        // Expression for Pre Fix
int cCounter = 0;       // Counter to trace the value inside Loops
int fLoop;              // For Loop inside Functions     
int iStack[SIZE];

const char* Postfix(char* cString1, int rSize)
{
    int fLoop;
    
    for(fLoop = 0; fLoop < rSize; fLoop++)
    {
        if(isalpha(cString1[fLoop]) == 0 && iTop == -1)
        {
            Push(cString1[fLoop]);
        }
        else if(isalpha(cString1[fLoop]) != 0)
        {
            postExp[cCounter] = cString1[fLoop];
            cCounter++;
        }
        else
        {   if(cString1[fLoop] == ')')
            {
                
                while(cStack[iTop] != '(')
                {
                    postExp[cCounter] = cStack[iTop];
                    cCounter++;
                    Pop();
                }
                iTop--;
                

            }
            else if( Prec(cString1[fLoop]) <= Prec(cStack[iTop]) && cStack[iTop] != '(')
            {   
                postExp[cCounter] = cStack[iTop];
                cCounter++;
                Pop();
                Push(cString1[fLoop]);
            }
            else
            {
                Push(cString1[fLoop]);
            }

        }
    }
    while(isEmpty(cStack) != 1)
    {
        postExp[cCounter] = cStack[iTop];
        Pop();
        cCounter++;
    }
    printf("The Postfix Expression Using Stack is: ");
    puts(postExp);
    printf("\n");

    return postExp;

}

int Prec(char cComp)
{

    switch(cComp)
    {   
      
        case '*': return 2;     // Return value is assigned based on the precedence
        case '/': return 2;
        case '+': return 1;
        case '-': return 1;

    }
}

int isEmpty() 
{
    if(iTop == -1)
        return 1; // True
    else
        return 0; // False
}

int isFull() 
{
    if(iTop == SIZE-1) // Note: Make sure you use SIZE-1
        return 1; // True 
    else
        return 0; // False
}



void Push(char x)   // Here 'x' is a dummy variable for passing the value
{
    if(isFull())
    {
        printf("Stack Overflow!!!");
    }  
    else
    {
        iTop++;
        cStack[iTop] = x;
    }
}

void Pop()
{
    if(isEmpty())
    {
        printf("Stack is Empty!!!");
    }
    else
    {
        iTop--;         // Top shifts one location behind
    }

}

void Prefix(char* cString1, int rSize)
{   
    char* revString;   
    revString = strrev(cString1);// For reversing string for Prefix
   

    for(fLoop = 0; fLoop < rSize; fLoop++)
    {
        if(isalpha(revString[fLoop]) == 0 && iTop == -1)
        {
            Push(revString[fLoop]);
        }
        else if(isalpha(revString[fLoop]) != 0)
        {
            preExp[cCounter] = revString[fLoop];
            cCounter++;
        }
        else 
        {   if(revString[fLoop] == '(')
            {
                
                while(cStack[iTop] != ')')
                {
                    preExp[cCounter] = cStack[iTop];
                    cCounter++;
                    Pop();
                }
                iTop--;
            }
       
            else if( Prec(revString[fLoop]) < Prec(cStack[iTop]) && cStack[iTop] != ')' )
            {   
                preExp[cCounter] = cStack[iTop];
                cCounter++;
                Pop();
                Push(revString[fLoop]);
            }
            else
            {
                Push(revString[fLoop]);
            }

        }
    }
    while(isEmpty(cStack) != 1)
    {
        preExp[cCounter] = cStack[iTop];
        Pop();
        cCounter++;
    }

    printf("\nThe Prefix Expression Using Stack is: ");
    puts(strrev(preExp));
    printf("\n");
}


void iPush(int x)   // Here 'x' is a dummy variable for passing the value
{
    if(isFull())
    {
        printf("Stack Overflow!!!");
    }  
    else
    {
        iTop++;
        iStack[iTop] = x;
    }
}


void Eval(char* cString3, int rSize)
{   
    int iOp1, iOp2;     // Operators for Evaluating Postfix Expression
   
   
    for(fLoop = 0 ; fLoop < rSize; fLoop++)
    {
        if (isdigit(cString3[fLoop]) != 0)
        {
             iPush(cString3[fLoop] - '0');
        }
        
        else
        {
            iOp2 = iStack[iTop]  ;
            Pop();
            iOp1 = iStack[iTop] ;
            Pop();  

            switch(cString3[fLoop])
            {
            case '*' : iPush(iOp1 * iOp2);
                    break;
            case '/' : iPush(iOp1 / iOp2);
                    break;
            case '+' : iPush(iOp1 + iOp2);
                    break;
            case '-' : iPush(iOp1 - iOp2);
                    break;
            }
            
        }   
        
    }
    printf("\nEvaluated Answer:%d" , iStack[iTop]);
}

void main()
{   
    char cString[SIZE] ;
    int iSize;
    int iChoice;   // Choice for Menu Driven Program
    char cChoice;
    do
    {   cCounter = 0;
        iTop = -1;
        printf("\n1. Convert Infix to Postfix\n2. Convert Infix to Prefix\n3. Evaluating Postfix Expression for Infix Expressions\nEnter Choice: ");
        scanf("%d", &iChoice);
        
        switch(iChoice)
        {
            case 1:     // Infix to Postfix
            {
                printf("\nEnter the Infix Expression: ");
                fflush(stdin);
                gets(cString);
                iSize = strlen(cString);
                Postfix(cString, iSize);
                
            }
            break;

            case 2:     // Infix to Prefix
            {
                printf("\nEnter the Infix Expression: ");
                fflush(stdin);
                gets(cString);
                iSize = strlen(cString);
                Prefix(cString, iSize);
                
            }
            break;

            case 3:     // Evaluating the Postfix Expression
            {
                printf("\nEnter the Postfix Expression in digits: ");
                fflush(stdin);
                gets(cString);
                iSize = strlen(cString);
                Eval(cString, iSize);
            }
            break;
            default: printf("Wrong Choice!!!");
        } 
    
    printf("\nDo you want to continue?");
    scanf(" %c", &cChoice);
    } while ( cChoice == 'Y' || cChoice == 'y');    // Type y/Y to continue the code
}