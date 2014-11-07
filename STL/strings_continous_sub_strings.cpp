// Program to print all combination of size r in an array of size n
#include <iostream>
#include<string>
#include<map>

using namespace std;

map <string,bool> visited_map;


void combinationUtil(char arr[],int n,int r)
{
	char data[r+1];
	unsigned int k;
	for(int i=0;i<=n-r;i++)
	{
		k=0;
		for(int j=i;j<i+r ;j++)
		{
		//	cout<<"Copy"<<arr[j]<<"\n";
	    	data[k++]=arr[j];
	    }
	    
	    data[r]=NULL;
	    //cout<<data<<endl;
	   	string temp(data);
    	
    	if(!visited_map[temp])
    	{
    		cout<<temp;
	        visited_map[temp]=1;
	        cout<<endl;
        } 
    }
}

void printCombination(char arr[], int n)
{
    for(int r=1;r<=n;r++)
    {
    // Print all combination using temprary array 'data[]'
    combinationUtil(arr,n,r);
    }
}

int main()
{
    char arr[] = {'1','1','3','4'};
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n);
}
