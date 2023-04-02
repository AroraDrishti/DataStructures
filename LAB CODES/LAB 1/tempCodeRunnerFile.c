#include <stdio.h>

int main()
{
    int d, m, y;
    printf("Enter day");
    scanf("%d", &d);
    printf("Enter month");
    scanf("%d", &m);
    printf("Enter year");
    scanf("%d", &y);

    //check year
    if(y>=1200 && y<=9999)
    {
        //check month
        if(m>=1 && m<=12)
        {
            //check day
            if((d>=1 &&d<=31) && (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12))
            {
                printf("Date is valid");
            }
            else if((d>=1 &&d<=30) && (m==4 || m==6 || m==9 || m==11))
            {
                printf("Date is valid");
            }
            else if((d>=1 && d<=28) && m==2)
            {
                printf("Date is valid");
            }
            else if(d==29 && m==2 && (y%400==0 || y%4==0 && y%100!=0))
            {
                printf("Date is valid");
            }
        }
        else 
        {
            printf("Date is invalid");
        }
    }
    return 0;
}