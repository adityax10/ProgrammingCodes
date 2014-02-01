/*logic used is transverin the infix in the reverse order nad pushing n poping the operators while copying the individual elemnts into the prefix */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *stack[20];
int top=-1;

void push(char *val)
{
    puts(val);
if(top<99)
stack[++top]=val;
printf("pushed at top= %d with char ",top);
puts(stack[top]);
}

char* pop()
{
//printf("poping charat top =%d\n",top);
//puts(stack[top]);
return stack[top--];
}



main()
{

   char postfix[30],*infix,*op1,*op2,*n[30];/*to enter each element of the stack one by one as directly using postfix[i] was  taking in the whole string..*/;
    int i;
    printf("Enter the postfix expression\n");
    gets(postfix);
    printf(" the expression is \n");
    printf("%s\n",postfix);
    for(i=0;postfix[i]!='\0';i++)
    { //printf("%c is being evaluated...\n",postfix[i]);
        char c[30]="(";/*using an arry to store ( as in the strcpy function.. size problem occours later in concatnation*/
        switch(postfix[i])
        {

    case'^':
    case'/':
    case'*':
case'+':
    case'-':
       op2=pop();
        puts("op2 is");puts(op2);
        op1=pop();
       puts("op1 is"); puts(op1);
        printf("Conatenating 1..\n");
         *(n+i)=postfix[i];
         strcat(c,op1);
        puts(c);
        strcat(c,n+i);
        puts(c);
        printf("Conatenating 2..\n");
        strcat(c,op2);
        puts(c);
        strcat(c,")");
        puts(c);
        strcpy(op1,c);
        puts(c);
        printf("just about to push concatenated string");

       push(op1);
       break;

    default:
    *(n+i)=postfix[i];
       push((n+i));
       break;
    }}
    infix=pop();
    printf("The infix expression is..: %s",infix);
}
