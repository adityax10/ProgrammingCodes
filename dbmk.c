#include <stdio.h>
#include<conio.h>

#define MAX(x,y) (x)>(y)?(x):(y);

#define PRINT_TOKEN(token) printf(#token " is %d", token)
#define NAME_CONCAT(name) MyNameIs##name

int main()
{
/*int i = 11;
int j =12;
int k=0;
k = MAX(i,j++);
printf("%d %d %d",i,j,k);*/

NAME_CONCAT (Aditya);

PRINT_TOKEN("hello");
//printf("%s",NAME_CONCAT("Aditya"));
getch();
return 0;
}
