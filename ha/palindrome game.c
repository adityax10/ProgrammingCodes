#include<stdio.h>
int main()
{
char s[1000000];
int i;
gets(s);
i=strlen(s);
if(i%2) printf("Ram\n");
else printf("Shyam\n");
return 0;
}
