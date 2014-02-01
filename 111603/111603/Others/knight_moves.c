#include<stdio.h>
#define SIZE 8
int visited[SIZE+1][SIZE+1];
int count;

refresh_board()
{
    int i,j;
    for(i=1;i<=SIZE;i++)
    {
        for(j=1;j<=SIZE;j)
                {
        visited[i][j]=0;
    }
}}

print_board(int x,int y)
{
    int i,j;
    for(i=1;i<=SIZE;i++)
    {
        for(j=1;j<=SIZE;j++)
        {
        if(visited[i][j]==0)
        printf("O ");
        else if(i==x&&j==y)
        printf("P ");
        else
        printf("X ");
        }
        printf("\n");
    }
    printf("\n");
}

void knight_mov(int x,int y,int moves)
{
   // printf("Before Move , x=%d y=%d\n",x,y);
    int i,j,s[4]={2,-2,1,-1};
    int ways=0;

    for(i=0;i<=3;i++)
    {
	 		   for(j=0;j<=3;j++)
	 		   {
			   					if(j==i || s[i]+s[j]==0)
			   					continue;

			   			  if(x+s[i]>=1&&x+s[i]<=SIZE&&y+s[j]>=1&&y+s[j]<=SIZE)
			   			  {
							  if(visited[x+s[i]][y+s[j]] == 0)
							  {
							  	  //getch();
							      visited[x+s[i]][y+s[j]]=1;
							      //printf("X = %d, Y = %d move= %d \n\n",x+s[i],y+s[j],moves+1);
							      print_board(x+s[i],y+s[j]);
	                              knight_mov(x+s[i],y+s[j],moves+1);
							  }
						  }

	 		   }
    }
    printf("Completed one !!,ways=%d\n",++count);
    visited[x][y]=0;
    //refresh_board();
}


int main()
{
 	int ways=0;
 	visited[1][1]=1;
 	knight_mov(1,1,1);
    printf("%d",count);
 	getch();
}
