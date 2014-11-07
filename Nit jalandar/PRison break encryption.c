#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
char s[200],ans[100][100];
int i=0,j=0,k=0,n=0;


printf("Columns :\n");
scanf("%d",&n);
fflush(stdin);
printf("Enter the string..\n");
gets(s);

for(i=0;i<(strlen(s)/n)&&(k<strlen(s));i++)
{
    if(i%2==1)
    for(j=n-1;j>=0;j--)
    {
        ans[i][j]=s[k];
        printf("ans[%d][%d] = %c\n",i,j,ans[i][j]);
        k++;
    }
    else
    for(j=0;j<n;j++)
    {
        ans[i][j]=s[k];
        printf("ans[%d][%d] = %c\n",i,j,ans[i][j]);
        k++;
    }
}
//ttyohhieneesiaabss

for(j=0;j<n;j++)
{
    for(i=0;i<(strlen(s)/n);i++)
    {
        printf("%c",ans[i][j]);
    }

}
/*
k=0;
while(k<=strlen(s))
{
    if(k%4==0)
    {
        i=(k*(strlen(s)/n));
        printf("case a i=%d %c",i,s[i]);
        k++;
    }
    else if(k%2==1)
    {
        i=(2*k*(strlen(s)/n))-1;
        printf("case b i=%d %c",i,s[i]);
        k++;
    }
}*/

}
