/*logic used is transverin the infix in the reverse order nad pushing n poping the operators while copying the individual elemnts into the postfix */
#include<stdio.h>
#include<stdlib.h>
/*For evaluating the operators*/
char stack[20];
int top=-1;

void push(char val)
{
if(top<99)
stack[++top]=val;
printf("this has been inputed %c\n",stack[top]);
}
char pop()
{
return stack[top--];
}


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

    char postfix[30],op1,op2,temp;
    int i,n,k=0;
    printf("Enter the postfix expression\n");
    gets(postfix);
    printf(" the expression is \n");
    printf("%s\n",postfix);

    char prefix[strlen(postfix)];
    push('#');
    for(i=strlen(postfix);i!=-1;i--)
    {
        printf("%c is being evaluated...\n",postfix[i]);
        switch(postfix[i])
        {

    case'^':
    case'/':
    case'*':
    case'+':
    case'-':

       /*while(precedence(postfix[i])<precedence(stack[top]))
       {
          prefix[k]=pop();
          k++;
       }*/
       //key2=0;

         prefix[k]=postfix[i];
       printf("prefix[%d] is %c...\n",k,prefix[k]);
       k++;
       break;

    default:
     push(postfix[i]);
       //key2++;
       //if(key2>=2)
       //{prefix[k]=pop();
       //k++;}
    }}
   while(top!=0)
    {
        prefix[k]=pop();
        k++;
    }
    prefix[k]=NULL;
    printf("THe prefix expression is..: ");
    printf("%s",prefix);


    }

