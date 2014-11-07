#include<iostream>
#include<string>
#include<math.h>

using namespace std;

void Matcher(string x)
{
	int m=x.length();
	cout<<"0 ";
	for(int i=1;i<m;)
	{
		if(x[i]!=x[0])
		{
			cout<<"0 ";
			i++;
			continue;
		}
		int j=0;
		int count=0;
		while(x[i]==x[j] && i<m)
		{
			i++;
			j++;
			count++;
			cout<<count<<" ";
		}
	}
	cout<<"";
}


int main()
{
	string input;
	
	while(1)
	{
	cin>>input;
	if(input == "End")
	break;
	Matcher(input);
    }
	
	return 0;
}
