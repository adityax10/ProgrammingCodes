#include <bits/stdc++.h>

#define d 256

using namespace std;

void RK_search(string &p,string &t,int q) // q is a prime number
{
	int n_p = p.size();
	int n_t = t.size();
	int h = 1;
	int h_p=0,h_t=0;
	// h = (d^(n_p-1)) % q;
	for(int i=0;i<n_p-1;i++)
		h = ( h*d ) % q;
	
	// preparing the hash for first window of size n_p
	for(int i=0;i<n_p;i++)
	{
		h_p = ((h_p * d) + p[i] ) % q;
		h_t = ((h_t* d) + t[i] ) % q;		
	}
		
	for(int i=0;i<n_t-n_p;i++)
	{
		cout<<"hp "<<h_p<<" ht "<<h_t<<endl;
		if(h_p == h_t)
		{
			int j=0;
			for(j=0;j<n_p;j++)
			{
				if(t[i+j]!=p[j])
				break;
			}
			if(j==n_p)
			cout<<"Found At  : "<<i<<endl;
		}
		// now rehash for next n_p length of t
		h_t =  (d*(h_t - t[i]*h) + t[i+n_p] ) % q;
		if(h_t<0)
		h_t+=q;
	}
}

int main(int argc, char** argv) {
	string t ="ADITYAVAVATS";
	string p = "AVA";
	RK_search(p,t,101);
	return 0;
}

