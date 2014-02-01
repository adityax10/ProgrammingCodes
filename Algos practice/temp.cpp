#include<stdio.h>
#include<stdlib.h>

int main()
{
	char *c=NULL;
	char s[10]="hello!";
	c=(char*)malloc(sizeof(char));
	 *c='a';
	 *(c+1)='b';
	 *(c+2)='\0';
	 printf("%s",c);
	 
	 return 0;
}
