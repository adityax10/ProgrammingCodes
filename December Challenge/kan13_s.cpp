#include<iostream>
#include<string>

using namespace std;

void Matcher(string x)
{
	long long int m=x.length();
	char s;
	if(m==1)
	cout<<"0\n";
	else
	cout<<"0 ";
	for(long long int i=1;i<m;)
	{
		if(i==m-1)
		s='\n';
		else
		s=' ';
		if(x[i]!=x[0])
		{
			cout<<"0"<<s;
			i++;
			continue;
		}
		long long int j=0;
		long long int count=0;
		while(x[i]==x[j] && i<m)
		{
			if(i==m-1)
		    s='\n';
		    else
		    s=' '; 
			i++;
			j++;
			count++;
			cout<<count<<s;
		}
	}
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
