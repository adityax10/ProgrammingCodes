#include<stdio.h>
#include<conio.h>

#define paste(a,b,c,d,e,f) b##d##f##e
#define okay paste(x,m,y,a,n,i)

okay()
{
printf("Without main");
getch();
}
