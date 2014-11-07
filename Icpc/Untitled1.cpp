#include<iostream>
#include<string>
#include <sstream>

using namespace std;

long w[100];
long count;


long* compute_prefix_function(const string &p)
{
	int m = p.length();
	int k;
	w[0]=0;
	for(int q=1; q<m ;q++)
	{
		k=0; 
		int q_t = q;
		while(k <= q_t)
		{
			if(p[k]==p[q_t])
			{
				k++;
				q_t--;
			}
			else
			{
			break;
		    }
		}
		w[q]=k;
	}
	
	return w;
}

void KMP_Matcher(string in,string p)
{
	int m = p.length();
	int n =in.length();
	int i=0,j=0;
	int q;
	compute_prefix_function(p);
	
	while(j<n)
	{
		if(p[i]==in[j])
		{
			if(i==m-1)
            {
            	count++;
        	    j = j - w[i-1];
				i=0;
            }
            i++;
			j++;
		}
		else
		{
			if(i==0)
			{
			j++;
		    }
			else
			{
				j = j - w[i-1];
				i=0;
			}
		}
		
	}
}


int main()
{
	ostringstream s;
	long n,cases;
	cin>>cases;
	while(cases--)
	{
		count=0;
		string a;
		cin>>n;
		for(long i=1;i<=n;i++)
		{
			    s<<i;
				a.append(s.str());
				s.str("");
				s.clear();
		}
		string num;
		cin>>num;
		
		KMP_Matcher(a,num);
		cout<<count<<"\n";
    }
	
	return 0;
}
