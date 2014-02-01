#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	int a,b,w,x,c;
	int sec = 0;
	cin>>a>>b>>w>>x>>c;
	while(c>a)
	{
	//	cout<<" a "<<a<<" b "<<b<<" c "<<c<<" sec "<<sec<<endl;
		if(b>=x)
		{
			if(c-a > b)
			{
			sec = sec + (b/x);
			c = c - (b/x);
			b = b - ((int)(b/x))*x;
		    }
		    else
		    {
		    	sec ++;
		    	c--;
		    	b -= x;
		    }
		//	cout<<"1\n";
		}
		else
		{
			c--;
			a--;
			b = w-(x-b);
			sec++;
		//	cout<<"2\n";
		}
	}
	cout<<sec<<endl;
	return 0;
}


