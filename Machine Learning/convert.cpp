#include<bits/stdc++.h>
using namespace std;

int main()
{
	ifstream in("logistidata.txt");
	ofstream out("convert_file.txt");
	string x;
	int k=3;
	while(in >> x ) 
	{
		if(x=="Male")
		x="0";
		else if(x=="Female")
		x="1";
		out << x+" ";
		k--;
		if(k==0)
		{
		k=3;
		out << "\n";
		}
	}
	
	
	

	return 0;
}


