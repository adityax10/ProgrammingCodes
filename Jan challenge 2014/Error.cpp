#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int w[10000000];

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
		//cout<<" index :"<<q<<" val "<<w[q]<<" "<<"\n";
	}
	return w;
}

bool KMP_Matcher(string in,string p)
{
	int m = p.length();
	int n =in.length();
	int i=0,j=0;
	int q;
	compute_prefix_function(p);
	
	while(j<n)
	{
       //cout<<" j "<<j<<" "<<in[j]<<"\n";
		if(p[i]==in[j])
		{
			if(i==m-1)
            {
        	   //cout<<"Match Found at "<<j-m+1 <<"\n";
        	    j = j - w[i-1];
				i=0;
				return 1;
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
	return 0;
}


int main()
{
	cout<<sizeof(long long int);
	string input;
	string p1="010";
	string p2="101";
	int cases;
	cin>>cases;
	while(cases--)
	{
	cin>>input;
	if(KMP_Matcher(input,p1)||KMP_Matcher(input,p2))
	cout<<"Good\n";
	else
	cout<<"Bad\n";
    }
	return 0;
}
