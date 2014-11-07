#include<bits/stdc++.h>
using namespace std;

int compare(const string &a,const string &b)
{
	string ab = a+b;
	string ba = b+a;
	
	if(ab.compare(ba)>0)
	return 1;
	else
	return 0;
}

int main()
{
	vector<string> arr;
	arr.push_back("1");
    arr.push_back("34");
    arr.push_back("3");
    arr.push_back("98");
    arr.push_back("9");
    arr.push_back("76");
    arr.push_back("45");
    arr.push_back("4");
    
    sort(arr.begin(),arr.end(),compare);
    
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i];
	}
	return 0;
}


