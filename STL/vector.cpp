#include<iostream>
#include<vector>

using namespace std;

int main()
{
	//int arr[20];
	vector<int> arr;
	
    arr.push_back(30);
    arr.push_back(3);
    
    //cout<<arr[0];
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<endl;
	cout<<arr.back();
	
	return  0;
}
