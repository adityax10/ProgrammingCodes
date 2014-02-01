#include<stdio.h>
#include<string.h>
main()
{
char s[100],c;
int i=0,j,n;
printf("Enter the string......\n");
gets(s);
printf("yo have entered....\n %s\n",s);
n=strlen(s);
printf("Enter the case you want...u/l?");
scanf("%c",&c);
switch(c)
{case 'u': {printf("%s\n",s);}
break;
case 'l':
while(s[i]!='\0')
{
    while((s[i]>='#'&&s[i]<='&')||(s[i]=='*')||(s[i]=='@'))
{
for(j=i;s[j]!='\0';j++)
{
s[j]=s[j+1];
}s[j]='null';}i++;
}
printf("%s",s);
}
}


