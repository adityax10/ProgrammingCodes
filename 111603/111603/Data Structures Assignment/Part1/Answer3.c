/*logic used is transverin the infix in the reverse order nad pushing n poping the operators while copying the individual elemnts into the prefix */
#include<stdio.h>
#include<stdlib.h>
/*For evaluating the operators*/
char stack[20];
int top=-1;

void push(char val)
{
if(top<99)
stack[++top]=val;
//printf("this has been inputed %c\n",stack[top]);
}
char pop()
{
return stack[top--];
}

int precedence(char x)
{
    switch(x)
    {
    case '^':return 6; break;
    case '/':return 5; break;
    case '*':return 4; break;
    case '+':return 3; break;
    case '-':return 2; break;
    case '#':return 1; break;
    }}

    /*char *reverse(char *p)
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

    char infix[30],op1,op2,temp;
    int i,n,k;
    printf("Enter the infix expression\n");
    gets(infix);
    printf(" the expression is \n");
    printf("%s\n",infix);
    n=strlen(infix);
    k=n-1;
    char prefix[n];
    push('#');
    for(i=n-1;i>=0;i--)
    { printf("%c is being evaluated...\n",infix[i]);
        switch(infix[i])
        {
        case'(': push(infix[i]);break;
        case')':      temp=pop();

                    while(temp!='(')
                       {
                           prefix[k]=temp;
                           k--;
                           temp=pop();
                       }
                       break;

    case'^':
    case'/':
    case'*':
    case'+':
    case'-':

       while(precedence(infix[i])<precedence(stack[top]))
       {
          prefix[k]=pop();
          k--;
       }
       push(infix[i]);
       break;

    default:
       prefix[k]=infix[i];
       printf("prefix[%d] is %c...\n",k,prefix[k]);
       k--;
    }}
   while(top!=0)
    {
        prefix[k]=pop();
        k--;
    }
    prefix[n]=NULL;
    printf("%s",prefix);


    }
