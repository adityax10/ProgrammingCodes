#include<stdio.h>

int main()
{
int *x,ans=1,n,i;
printf("Enter the number of cards : ");
scanf("%d",&n);
x=(int*)malloc(sizeof(int)*n);
printf("Enter the Colors on the cards : \n");

for(i=0;i<n;i++)
scanf("%d",x+i);

printf("Chances of Elephant's winning are  : ");

for(i=n-1;i>n/2;i--)
ans=ans+c(n,i);
printf("%d",ans);
}
int c(int x,int y)
{
return fact(x)/(fact(x-y)*fact(y));
}
int fact(int x)
{
if((x==0)||(x==1))
return 1;

return x*fact(x-1);
}
