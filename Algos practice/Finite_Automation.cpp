#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int w[100];

int* compute_prefix_function(const string &p)
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
		cout<<" index :"<<q<<" val "<<w[q]<<" "<<"\n";
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
        cout<<" j "<<j<<" "<<in[j]<<"\n";
		if(p[i]==in[j])
		{
			i++;
			j++;
			if(i==m-1)
            {
        	cout<<"Match Found at "<<j-m+1 <<"\n";
        	    j = j - w[i-1];
				i=0;
            }
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
	string pattern,input;
	
	pattern = "123";
	input = "1237512321232143839123";
	//cout<<pattern[0];
	KMP_Matcher(input,pattern);
	
	return 0;
}
