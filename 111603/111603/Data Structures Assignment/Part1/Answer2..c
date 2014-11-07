#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float stack[100];
int top=-1;
void push(float val)
{
if(top<99)
stack[++top]=val;
printf("%f has been pushed\n",stack[top]);
}
float pop()
{
return stack[top--];
}


   /* char *reverse(char *p)
    {
        int n=strlen(p);
        char *f;
        int i=0;
        while(i<n)
        {
            *(f+n-1-i)=*(p+i);
            i++;
        }
        *(f+n)=NULL;
        return f;
    }*/

main()
{
    char *prefix,temp;
    int i;
    float op1,op2;
    prefix=(char*)malloc(sizeof(char)*30);
    printf("Enter PREFIX The Expression\n");
    gets(prefix);
    printf(" the expression is \n");
    printf("%s\n",prefix);
         for(i=strlen(prefix)-1;i>=0;i--)
    {
        printf("%c is being evaluated..\n",prefix[i]);
        switch(prefix[i])

    {
    case '/':                       op1=pop();op2=pop();push(op1/op2);break;
    case '*':                       op1=pop();op2=pop();push(op1*op2);break;
    case '+':                       op1=pop();op2=pop();push(op1+op2);break;
    case '-':                       op1=pop();op2=pop();push(op1-op2);break;
    case ' ':                          break;
    default: push((float)prefix[i]-48);
    }}
    printf("The Answer is: %f",pop());
    }
