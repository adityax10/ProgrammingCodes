#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int SIZE=10;
int list[SIZE];
int top=-1;
int a=2;//(SIZE/2)-1);
int b=3;//(SIZE/2);
void push(int val)
{
if(top<=a)
list[++top]=val;
printf("%d has been pushed\n",list[top]);
if(top>a)
{
printf("Increased stack!\n");
a++;
b++;
list[++top]=val;
printf("%d has been pushed\n",list[top]);
}
}
int pop()
{
return list[top--];
}

int front=-1,rear=-1;

void addq(int val)
{
if(rear<=(b))
{
list[++rear]=val;
}}

int deleteq()
{
if(front==rear)
printf("Queue is empty..\n");
else
{
return list[++front];
}
}

main()
{
    int x;
    int val;
    while(x!=3)
    {
printf("Choose to\n 1)Add Data\n 2)Display Data\n 3)Exit\n");
scanf("%d",&x);
switch(x)
{
    case 1:
    printf("Add data to:\n1)Stack\n 2)Queue\n");
   scanf("%d",&x);
   switch(x)
{
    case 1:
    printf("Enter:");
    scanf("%d",&val);
    push(val);
    break;
    case 2:
    printf("Enter:");
    scanf("%d",&val);
    addq(val);
    break;
}
break;

    case 2:
    printf("Display data from:\n1)Stack\n 2)Queue\n");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
    printf("Value at Stack: %d",pop());

    break;
    case 2:
    printf("Value in Queue: %d",deleteq());
    break;
    }
    break;

    case 3:
    printf("Exiting....\n");
    exit(1);


}


}}

