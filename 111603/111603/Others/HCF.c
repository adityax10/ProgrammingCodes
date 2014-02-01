#include<stdio.h>
#include<conio.h>
HCF(int a,int b)
{
 		if(b==0)
 		return a;
 		if(b!=0)
 		HCF(b,a%b);
}

int main()
{
 	printf("%d",HCF(24));
 	//while(1)
 	getch();
}
