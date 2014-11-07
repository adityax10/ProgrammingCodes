#include<stdio.h>
#include<string.h>
main()
{
char str[200];
int i=0,j,k=1,n,price=0;
printf("Enter the string : ");
scanf("%s",str);
fflush(stdin);
n=strlen(str);
while(i<n)
{
for(j=i+1;j<n;j++)
 {
 if(str[i]==str[j])
 {k=k+1;}}
 printf("The frequency of %c is %d\n",str[i],k);
 i++;
 for(j=i-1;j>=0;j--)
 {
     if(str[i]==str[j])
{
 i++;
 j=i-1;
 } }

 if(k%2==0)
 price=price+k/2;
 else
 price=price+k/2+1;
 k=1;
 }

 printf("The price  is %d :",price);
}


