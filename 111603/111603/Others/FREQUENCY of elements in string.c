#include<stdio.h>
#include<string.h>
main()
{
char str[30];
int i=0,j,k=1,n;
printf("Enter the string : ");
scanf("%s",str);
fflush(stdin);
n=strlen(str);
while(str[i]!='\0')
{
for(j=i+1;j<n;j++)
 {
 if(str[i]==str[j])
 {k=k+1;}}
 printf("the frequency of %c is %d\n",str[i],k);
 i++;k=1;
 for(j=1;j<=i;j++)
 {
     if(str[i]==str[i-j])
{
 i++;} }
 }
}


