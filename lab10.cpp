#include<stdio.h>
#include<conio.h>

int main () {
	char c[20];
	char ch;
	do{
		printf("enter anything to test: ");
		scanf("%s",&c);
		if (c[0] == '_' || c[0] == '0' || c[0] == '1' || c[0] == '2' || c[0] == '3' || c[0] == '4' || c[0] == '5' || c[0] == '6' || c[0] == '7' || c[0] == '8' || c[0] == '9' || c[0] == '@' || c[0] == '#' || c[0] == '!' || c[0] == '(' || c[0] == ')'){
		printf("Not Accepted\n");
		}
		else{
		printf("Accepted\n");
	}
	printf("do you want to continue (y/n): ");
	fflush(stdin);
	scanf("%c",&ch);
	}while(ch=='y' || ch=='Y');



}
