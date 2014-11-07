#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int PS[MAX];

void cal_prefix_function(string p)
{
	int n = p.size();
	int j=0;
	int i=1;
	while(i<n)
	{
		if(p[i]==p[j])
		{
			PS[i]=j+1;
			j++;
			i++;
		}
		else
		{
			if(j==0)
			{
				PS[i]=0;
				i++;
			}
			else
			{
				j=PS[j-1];
			}
		}
	}
}

int KMP(string p,string t)
{
	int i=0;
	int j=0;
	int n = t.size(); // i
	int m = p.size(); //  j
	
	while(i<n)
	{
		if(p[j]==t[i])
		{
			if(j==m-1)
			{
				cout<<"Found at "<<i-j<<endl;
				j=PS[j-1]; // For next Occurance
			}
			else
			{
				i++;
				j++;
			}
		}
		else
		{
			if(j==0)
			{
				i++;
			}
			else
			{
				j = PS[j-1];
			}
		}
	}
	return -1;
}

int main()
{
	string p = "ABAB"; // pattern
	string t = "BSAABABABCDACA";
	cal_prefix_function(p);
	
	for(int i=0;i<p.size();i++)
	{
		cout<<PS[i]<<" ";
	}
	cout<<endl;
	cout<<KMP(p,t);
	return 0;
}

