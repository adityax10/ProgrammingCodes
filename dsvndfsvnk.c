#include<stdio.h>
main()
{
int x,y,z;
x=y=z=1;
z=++x||++y&&++z;
printf("x=%d y=%d z=%d\n",x,y,z);
gets(x);
}
