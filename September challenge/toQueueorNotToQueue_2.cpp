#include<iostream>
#include<list>
#include<map>

using namespace std;
map <string,bool> visited_map;
map<string,long> counting_map;

long count;

void combinationUtil(char arr[],int n,int r,bool same_Q)
{
	
}

void findCombination(list<char> l, int n)
{
    // A temporary array to store all combination one by one
    char data[n],arr[n];
    int i=0;
	bool same_Q=0;
    char recent = l.back();
    //cout<<"back :"<<recent<<"\n";
    for(auto j=l.begin();j!=l.end();j++)
    {
    	arr[i]=*j;
    	if(recent == *j && i!=n-1)
    	same_Q=1;
    	i++;
    }
    //cout<<same_Q;
   // for(int r=1;r<=n;r++)
    {
    combinationUtil(arr, n,same_Q);
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
