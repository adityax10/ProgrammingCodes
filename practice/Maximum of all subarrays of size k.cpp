#include<bits/stdc++.h>
using namespace std;

void max_element_in_k_length_interval(int a[],int k,int n)
{
	// deque
	// to support  deletions from both front and back => pop_back() and pop_front()
	// only allows insertion only at back => push_back()
	deque<int> v;
	
	for(int i=0;i<k;i++)
	{
		while(!v.empty()&&a[v.front()]<=a[i])
		v.pop_back();
		
		v.push_back(i);
	}
	int i = k;
	while(i<n)
	{
		cout<<a[v.front()]<<" ";
		
		while(!v.empty() && a[v.front()]<=a[i])
		v.pop_back();
		
		while(!v.empty() && i > v.front() + k - 1)
		v.pop_front();
		
		v.push_back(i);
		i++;
	}
	cout<<a[v.front()]<<" ";
}

int main()
{
	//int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
	int arr[] = {12, 1, 78, 90, 57, 89, 56};
	int k = 3;
	max_element_in_k_length_interval(arr,k,sizeof(arr)/sizeof(int));

	return 0;
}


