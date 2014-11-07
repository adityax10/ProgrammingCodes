#include<stdio.h>
void push(int c);
int pop();
int top=-1;
int stack[100];
void main()
{
int a,i,j;

for(j=0;j<=100;j++)
{
    printf("STACKS: Enter your choice\n");
printf("CHOICES:\n");
printf(" 1: push\n 2: pop\n 3:exit\n");
scanf("%d",&i);
switch(i)
{
    case 1:
    printf("Enter your number");
    scanf("%d",&a);
    push(a);
    break;
    case 2:
    printf("your previous value was... %d\n",pop());
    break;
    case 3:
    exit(1);
}
}
}
void push(int c)
{
if(top<99)
{
stack[++top]=c;
}
}
int pop()
{
    if(top>=0)
{
return stack[top--];
}
}
