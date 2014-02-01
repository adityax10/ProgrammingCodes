#include<stdio.h>
#include<conio.h>

#define MAX 32767
#define SIZE 20

int m[SIZE][SIZE],s[SIZE][SIZE];

void print_Sol(int i,int j)
{
    //getch();
    if(i==j)
    printf("A%d " ,i);
    else if(j>i)
    {
    printf("(");
    print_Sol(i,s[i][j]);
    print_Sol(s[i][j]+1,j);
    printf(")");
    }
}

void matrix_multiply_parenthesis(int p[],int n)
{
	//matrix p has the dimensions of matrix => eg; p[i] & p[i+1] stores the dimens of matrix A[i]
    // m to store the minimum multiplcation cost eg; m[i][j] stores minimum multiplication cost for Ai X Aj
    //s[i][j] to store the value of index k giving least multiplication cost for ai x aj
    int i,j,k,l,q=MAX,q_min_prev=MAX;

    //minimum cost when A i...k and A k+1.....j are multiplied is sored in m[i][j]
    // A i...k cost = > m[i][k]
    // A k+1....j cost => m[k+1][j]
    //p[i-1]p[k]p[j] cost=> when A i...k and A k+1.....j are multiplied

   for(i=1;i<=n;i++)
   {
      // printf("Setting m");
       m[i][i] = 0;
   }


    for(l=2;l<=n;l++) //l is the length off the chain
    {
	    for(i=1;i<=n-l+1;i++)
	    {
	     j=i+l-1;
	     m[i][j] = MAX;
		     for(k=i;k<j;k++)
		     {
		       //printf("Finding q\n");
		       q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
		       //printf("q=%d\n",q);
		       if(q < m[i][j])
		       {
		           m[i][j] = q;
		           s[i][j] = k;
		       }
	     }
	    }
    }
}


int main()
{
    int p[SIZE]={30,35,15,5,10,20,25},n=6,i,j;
    /*printf("Number of Matrices : ? \n");
    scanf("%d",&n);
    printf("Enter the matrix sizes in order of A1 A2 A3.... AN\n :");
    //p[0] X p[1] represents the size of A1
    for(i=0;i<n+1;i++)
    scanf("%d",&p[i]);*/

    matrix_multiply_parenthesis(p,n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
           printf("%d ",s[i][j]);
        }
        printf("\n");
    }
    print_Sol(1,n);
}
