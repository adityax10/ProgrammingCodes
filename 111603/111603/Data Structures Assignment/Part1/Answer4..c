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
printf("this has been inputed %c\n",stack[top]);
}
char pop()
{
return stack[top--];
}

main()
{

    char prefix[30],op1,op2,temp;
    int i,n,k=0,key1=0,key2=0;
    printf("Enter the prefix expression\n");
    gets(prefix);
    printf(" the expression is \n");
    printf("%s\n",prefix);

    char postfix[n];
    push('#');
    for(i=0;prefix[i]!='\0';i++)
    {
        printf("%c is being evaluated...\n",prefix[i]);
        switch(prefix[i])
        {
        case'(': push(prefix[i]);break;
        case')':      temp=pop();

                    while(temp!='(')
                       {
                           postfix[k]=temp;
                           k++;
                           temp=pop();
                       }
                       break;

    case'^':
    case'/':
    case'*':
    case'+':
    case'-':

       /*while(precedence(prefix[i])<precedence(stack[top]))
       {
          postfix[k]=pop();
          k++;
       }*/
       key2=0;
       push(prefix[i]);
       break;

    default:
       postfix[k]=prefix[i];
       printf("postfix[%d] is %c...\n",k,postfix[k]);
       k++;
       key2++;
       if(key2>=2)
       {postfix[k]=pop();
       k++;}
    }}
   while(top!=0)
    {
        postfix[k]=pop();
        k++;
    }
    postfix[n]=NULL;
    printf("THe postfix expression is..: ");
    printf("%s",postfix);


    }

