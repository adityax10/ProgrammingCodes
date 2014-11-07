#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;

int main()
{
	ofstream out("test.txt");
	
	srand(time(NULL));
	int t=1;
	out<<t<<endl;
	int a[20];
	while(t--)
	{
		int n=1+rand()%10;
		int m = 1+rand()%10;
		int k = rand()%10;
		out<<n<<" "<<m<<" "<<k<<endl;
		for(int i =0;i<n;i++)
		{
		a[i] = 1+rand()%m;
		out<<a[i]<<" ";
	    }
		out<<endl;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				out<<rand()%10<<" ";
			}
			out<<endl;
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(j==a[i])
				out<<"0 ";
				else
				out<<rand()%10<<" ";
			}
			out<<"\n";
		}
		
		cout<<"Done !";
		out<<endl;
	}
}

