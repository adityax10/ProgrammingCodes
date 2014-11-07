#include<iostream>
#include<list>
#include<map>

using namespace std;
map <string,bool> visited_map;

long count;

void combinationUtil(char arr[],int n,int r)
{
	char data[r+1];
	unsigned int k;
   
	
	for(int i=0;i<=n-r;i++)
	{
		k=0;
		for(int j=i;j<i+r ;j++)
		{
	    	data[k++]=arr[j];
	    }
	    
	    data[r]='\0';
	   	string temp(data);
    	
    	if(!visited_map[temp])
    	{
    		//cout<<temp;
    		count++;
	        visited_map[temp]=1;
	       // cout<<endl;
        } 
    }
}

void findCombination(list<char> l, int n)
{
    // A temporary array to store all combination one by one
    char data[n],arr[n];
    int i=0;
    for(auto j=l.begin();j!=l.end();j++)
    {
    	arr[i++]=*j;
    }
    for(int r=1;r<=n;r++)
    {
    combinationUtil(arr, n,r);
    }
}

int main()
{
	list<char> str;
	char temp[3];
	int cases;
	unsigned int len=0;
	long ans=0;
	cin>>cases;
	while(cases)
	{
		count=0;
		cin>>temp[0];
		if(temp[0]=='+')
		cin>>temp[1];
		visited_map.clear();
		switch(temp[0])
		{
			case '+':
						len++;
						str.push_back(temp[1]);
						findCombination(str,len);
						break;
			case '-' :
						if(len)
						{
						len--;
						str.pop_front();
						findCombination(str,len);
					    }
						break;
		}
		cases--;
		ans+=count;
		ans=ans%1000000007;
	}
	cout<<ans<<"\n";
	return 0;
}
