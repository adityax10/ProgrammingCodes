#include<stdio.h>
#include<conio.h>

#define PRINT(int) printf("int=%d",int);

main()

{int x,y,z;

x=03;y=-2;z=1;

PRINT(x^x);

z<<=3;PRINT(z);

y>>=0;PRINT(y);
getch();
}
