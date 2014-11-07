#include<stdio.h>

main()
{
unsigned int x,y;
int a,b,count=0,c=0;
scanf("%d",&x);
scanf("%d",&y);

while((a!=0)||(b!=0))
{
a=x%10;
x=x/10;
b=y%10;
y=y/10;
printf("a =%d  b =%d \n",a,b);
c=a+b+c;
printf("c =%d \n",c);
c=c/10;
if(c)
{
count++;
printf("count = %d",count);
}
}
if(count!=0)
{
    printf("%d times carry \n",count);
}
else
   printf("No  carry");

}

