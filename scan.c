#include<stdio.h>
#include<conio.h>

int main()
{
    int n,a[20],i,j,x,temp,loc,ini;

    printf("Enter the Number of requests");
    scanf("%d",&n);
    printf("Enter the terminal disk Loactions");
    scanf("%d %d",&a[0],&a[n+1]);

   printf("Enter the disk requests : ");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    x=n;
	while(x>0)
    {
        for(j=1;j<=x-1;j++)
        {
        if(a[j]>a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
        }
        x--;
    }

    for(i=1;i<=n;i++)
    printf("%d ",a[i]);

    printf("Enter the Initial Location of the disk head:");
    scanf("%d",&ini);
    for(i=1;i<=n;i++)
    {
        if(ini<a[i])
        {
            loc=i-1;
            break;
        }
    }
    printf("Is the disk head gonig to %d or %d\n",a[0],a[n+1]);
    scanf("%d",&ini);
    if(ini==a[0])
    {
    for(i=loc;i>=0;i--)
    printf("%d ->",a[i]);
    for(i=loc+1;i<=n+1;i++)
    printf("%d ->",a[i]);
    }
    else
    {
    for(i=loc+1;i<=n+1;i++)
    printf("%d ->",a[i]);
    for(i=loc;i>=0;i--)
    printf("%d ->",a[i]);
    }
   getch();
}
