#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
void menu();
int add(int,int);
int sub(int,int);
int mul(int,int);
int mod(int,int);
int div(int,int);

void main(){
	menu();
	getch();
}

void menu(){
	int iChoice;
	char cChoice;
	int iA,iB;
	int iLoop;
	float fRes;
	do{
		clrscr();
		printf("\nEnter first number:");
		scanf("%d",&iA);
		printf("\nEnter second number:");
		scanf("%d",&iB);

		printf("\nPress a key for calculator");
		for(iLoop=0;iLoop<10;iLoop++){
			printf(".");
			delay(1000);
		}
		getch();
		clrscr();

		printf("\n\n\t\tMENU FOR CALCULATOR");
		printf("\n\t1.Addition");
		printf("\n\t2.Substraction");
		printf("\n\t3.Multiplication");
		printf("\n\t4.Modulus");
		printf("\n\t5.Division");
		printf("\n\t6.Exit");
		printf("\n\n\tEnter your choice(1-6):");
		scanf("%d",&iChoice);

		switch(iChoice){

			case 1:

					printf("\nAdditon of %d and %d is %d",iA,iB,add(iA,iB));
					break;
			case 2:
					printf("\nSubstraction of %d and %d is %d",iA,iB,sub(iA,iB));
					break;
			case 3:

					printf("\nMultiplication of %d and %d is %d",iA,iB,mul(iA,iB));
					break;
			case 4:

					printf("\nModulus of %d and %d is %d",iA,iB,mod(iA,iB));
					break;
			case 5:
					printf("\nDivision of %d and %d is %d",iA,iB,div(iA,iB));
					break;
			case 6:
					printf("\nThank you for using calculator!!!!");
					exit(0);
			default:
				printf("\n\nWRONG CHOICE!!!!");
		}


		printf("\nDo you want to continue(y->yes||Y->YES):");
		fflush(stdin);
		scanf("%c",&cChoice);
	}while(cChoice=='y' || cChoice=='Y');

	getch();
}

int add(int iTA,int iTB){
	return (iTA+iTB);
}
int sub(int iTA,int iTB){
	return (iTA-iTB);
}
int mul(int iTA,int iTB){
	return (iTA*iTB);
}
int mod(int iTA,int iTB){
	return (iTA%iTB);
}
int div(int iTA,int iTB){
	if(iTB!=0){
		return (iTA/iTB);
	}
	return(-1);
}