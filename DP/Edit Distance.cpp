#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<string>
using namespace std;




int cost[100][100];
int c_d,c_i,c_r;

int mini(int a,int b,int c)
{
	int temp = (a>b?b:a);
	return (temp>c?c:temp);
}

int edit_distance(string a,string b)  // Convert A => B
{
	for(int i=0;i<a.length();i++)
	cost[i][0]= i*c_d; //deleteion
	for(int i=0;i<b.length();i++)
	cost[0][i]=i*c_i; // insertion
	
	
	int left_corner=0,right_corner=0,top_corner=0;
	
	for(int i=1;i<a.length();i++)
	{
		for(int j=1;j<b.length();j++)
		{
			if(a[i]!=b[j])
			{
				cost[i][j] = mini( cost[i-1][j]+c_d , cost[i][j-1]+c_i , cost[i-1][j-1]+c_r );
			}
			else
			cost[i][j]=cost[i-1][j-1];
		}
	}
	
	for(int i=0;i<a.length();i++)
	{
		for(int j=0;j<b.length();j++)
		{
			cout<<" "<<cost[i][j];
		}
		cout<<"\n";
	}
	return cost[a.length()-1][b.length()-1];
}

int main()
{
	c_d=1;
	c_r=1;
	c_i=1;
	// Note About The Space !!
	// strings start at index 1
	string a(" Sunday");
	string b(" Saturday");
    cout<<edit_distance(a,b);
	return 0;
}


