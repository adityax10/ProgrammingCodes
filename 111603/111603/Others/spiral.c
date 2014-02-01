#include<stdio.h>
#include<conio.h>

#define SIZE 10

int turn;

void spiral(int arr[10][10],int x,int y,int s,int n)
{
    if(x<s||x>n||y<s||y>n)
    {


        turn=(turn+1)%4;
        if(y<s)
        y++;
        if(x<s)
        x++;
        if(y>n)
        y--;
        if(x>n)
        x--;
        printf("s =%d,n=%d ",s,n);
    }

    if(turn==3 && x==s+1 )
    {
        s++;
        n--;
        turn = 0;
       // printf("Changing s =%d,n=%d ",s,n);
    }

    //if(x>=0&&x<=n&&y>=0&&y<=n)
    {
    printf("v=%d ",arr[x][y]);

    if(x==SIZE/2&&y==SIZE/2)
    return;

    //getch();
    if(turn==0)
    spiral(arr,x,y+1,s,n);
    else if(turn==1)
    spiral(arr,x+1,y,s,n);
    else if(turn == 2)
    spiral(arr,x,y-1,s,n);
    else if(turn == 3)
    spiral(arr,x-1,y,s,n);
    }

}

int main()
{
    int arr[SIZE][SIZE],i,j;
    int count=0;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
        arr[i][j]=count++;
        printf("%3d ",arr[i][j]);
        }
        printf("\n");
    }
    spiral(arr,0,0,0,SIZE-1);
}
