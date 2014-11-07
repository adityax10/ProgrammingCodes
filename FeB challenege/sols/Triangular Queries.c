
#include<stdio.h>
#include<string.h>

typedef struct triangle
{
    int x,y,d;
}triangle;

typedef struct coord
{
    int x,y;
}coord;

main()
{
    triangle *t;
    coord *c;
    int q,i=0,n,j;

    printf("Enter the number of coordinates : \n");
     scanf("%d",&n);
    c=(coord *)malloc(sizeof(coord)*n);
    while(i<n)
    {
    printf("Enter the values : \n x \n y \n");
    scanf("%d%d",&((c+i)->x),&((c+i)->y));
    i++;
    }
    i=0;

    printf("Enter the number of triangles : \n");
    scanf("%d",&q);
    t=(triangle *)malloc(sizeof(triangle)*q);
    while(i<q)
    {
    printf("Enter the values : \n x \n y \n d \n");
    scanf("%d%d%d",&((t+i)->x),&((t+i)->y),&((t+i)->d));
    i++;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<q;j++)
        check(c+i,t+j);
    }


}

void check(coord *c,triangle *t)
{

    if(((c->y)+(c->x)-(t->x)-(t->y)-(t->d))<=0)
    {
    if((((c->x)>=(t->x))&&(c->x)<=(t->x)+t->d)&&(((c->y)>=(t->y))&&((c->y)<=(t->y)+t->d)))
    printf(" %d %d Lies Inside..!\n",c->x,c->y);
    }
    else
    printf(" %d %d Lies Outside..!\n",c->x,c->y);
}

