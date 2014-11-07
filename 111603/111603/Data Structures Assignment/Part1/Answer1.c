#include<stdio.h>
#include<conio.h>
#include<string.h>
int top=-1;
int SIZE;

int *list=NULL;

void push(int val)
{
    if(top<(SIZE-1))
    {
        ++top;
       *(list+top)=val;
    }
    else
    {
    printf("Expanded stack by 1 unit and value is added..!\n");
    top++;
    realloc(list,sizeof(int)*(SIZE+1));
    *(list+top)=val;

    }
}

int pop()
{
    if(top>=0)
    {
        return *(list+(top--));
    }
    else
    {
        printf("NOthing Left!!\n");
    }
}

main()
{
    int x,val,i=0;
    char *c;
    printf("Enter the number of values you wish to enter into the stack:");
    scanf("%d",&SIZE);
    list=(int*)malloc(SIZE*sizeof(int));
    //c=(char*)malloc(SIZE*sizeof(char));
   // printf("lenght is %d",sizeof(c));
    //fflush(stdin);
    //gets(c);
    //puts(c);

    while(x!=3)
    {
    printf("Enter your choice...:\n1) Push Value\n2)Pop Value\n3) Exit\n");
    scanf("%d",&x);
    switch(x)
    {
        case 1:
        printf("Enter the value:");
        scanf("%d",&val);
        push(val);
        break;

        case 2:
        printf("The poped value is : %d\n",pop());
        break;

        case 3:
        printf("Exiting....\n");
        exit(1);

    }}
}
