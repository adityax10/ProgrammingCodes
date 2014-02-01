#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;

struct node *link;
}node;
main()
{
    char a;
    int x,i=0;
node *start,*temp1,*temp2;
int b[5]={5,4,3,2,1};

start=(node*)malloc(sizeof(node));
temp1=(node*)malloc(sizeof(node));
temp2=(node*)malloc(sizeof(node));
start=NULL;
//printf("do you want to enter data?? y/n\n");
//scanf("%c",&a);
//printf("%c\n",a);
//while((a!='n')||(a!='N'))
while(i<5)
{
    temp1->data=b[i];
    temp1->link=NULL;
   //printf("enter data...\n");
    //scanf("%d",&x);
    if(start==NULL)
    {
   start=temp1;
   start->link=temp1;
    }

    //printf("do you further want to enter data??\n");

    //scanf("%c",&a);
    //printf("%c\n",a);

    //if((a=='y')||(a='Y'))
     else
    {

        temp2->link=temp1;
        temp2=temp1;
    }
i++;

}
//if(a=='n')
{
printf("Values entered by you were..\n");
temp1=start;
i=0;
while(i<5)
{
printf(" %d ",temp1->data);
temp1=temp1->link;
getch();
i++;
}
}}
