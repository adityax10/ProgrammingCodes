#include<stdio.h>

int top=0,SIZE=4,prev=0;
void enqeue(int list[],int num)
{
    if((top+1)%SIZE!=prev)
    {
    top=(top+1)%SIZE;
    list[top]=num;
    }
    else{
        printf("NO Space avaliable!");
    }
}
int deqeue(int list[])
{
    if((prev!=top))
    {
        prev=(prev+1)%SIZE;
        printf("prev is %d\n",prev);
        return list[prev];
    }
    else{
        printf("No item to deqeue!\n");
    return -1;}
}

int main()
{
    int list[100],x=0,num;
    printf("Enter the operation:\n 1)enqeue \n 2)deqeue \n 3)-1 to exit\n");
    scanf("%d",&x);
while(x!=-1)
{
    switch(x)
    {
        case 1:
        printf("Enter the number :");
        scanf("%d",&num);
        enqeue(list,num);
        break;
        case 2:
        printf("Deqeueed item is :%d\n",deqeue(list));
        break;
    };
    fflush(stdin);
    scanf("%d",&x);

}
}
