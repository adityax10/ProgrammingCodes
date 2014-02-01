#include<iostream>
#include<string>
#include<math.h>

using namespace std;


//INclude mod by 13. i.e q=13.. ignored in this implemtation
void karp_ralbin(string p,string in,int q/*for mod*/,int d)
{
	int p_size = p.length();
	int i_size = in.length();
	
	int sub = ((int)pow(d,p_size-1));
	//cout<<"Sub is : "<<sub;
	
	int code_p=0,code_i=0;
	
	for(int i=0;i<p_size;i++)
	{
		code_p = (code_p*d + (int)p[i]-(48));
		code_i = (code_i*d + (int)in[i]-(48));
		//cout<<"c_p ="<<code_p <<" c_in = "<<code_i<<"\n";
	}

	
	for(int shift=0;shift <= i_size-p_size ;shift++)
	{
		//if codes match
		if(code_i == code_p)
		{
			int k=0;
			for(int i=shift;i<p_size+shift;i++)
			{
				//cout << "Comparing "<<p[k]<<" & "<<in[i]<<"\n";
				if(in[i]==p[k])
				{
					k++;
					continue;
				}
				else
				break;
			}
			if(k==p_size)
			cout<<"Match Found at SHift = "<<shift<<"\n";
		}
		//
		{
			code_i = ((code_i - ((int)in[shift] - 48)*sub)*d + (int)in[p_size+shift]-48 );
			//cout<<"New code_i = "<<code_i<<"\n";
		}
    }
	
	
}

int main()
{
	string pattern,input;
	
	pattern = "1234";
	input = "32756123412383591234";
	//cin<<pattern<<input;
	karp_ralbin(pattern,input,13,10);
	
	return 0;
}
