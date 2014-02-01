#include<iostream>

#define SIZE 6

using namespace std;

int MAX=-1;
int Money[SIZE][SIZE];

int max_money(int i,int j,int a[],int money)
{
	
	if(j<0 || i>=SIZE || i>j)
	{
	if(money > MAX)
	MAX=money;
	 return 0;	
	}
	cout<<"i "<<i<<" j "<<j<<" M : "<<money<<endl;
	
	if(Money[i][j]!=0)
	return Money[i][j];
	
	int x =  max(max(max_money(i+2,j,a,money+a[i]),max_money(i+1,j-1,a,money+a[i])),max(max_money(i+1,j-1,a,money+a[j]),max_money(i,j-2,a,money+a[j])));
	Money[i][j]=x;
	return x;
}

int main()
{
	int a[SIZE]={1,5,3,2,4,3};
	max_money(0,SIZE-1,a,0);	
    cout<<MAX;
}
