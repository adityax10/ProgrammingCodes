#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	map <string,int> name; //<key,value> pair
	
	name["Aditya"]=1;
	
	cout<<name["Aditya"];
	return 0;
}
