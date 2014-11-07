#include<bits/stdc++.h>
using namespace std;

class heap_min
{
	public : 
	bool operator() (int &x,int &y)
	{
		return x>y; // min
	}
	
};

class heap_max
{
	public : 
	bool operator() (int &x,int &y)
	{
		return x<y; // max
	}
	
};

priority_queue<int,vector<int>,heap_min> min_queue; // for upper sorted half
priority_queue<int,vector<int>,heap_max> max_queue; // for lower sorted half

void find_medians(int a[],int n)
{
	// initially push the first element to max_queue
	max_queue.push(a[0]);
	cout<<max_queue.top()<<endl;
	for(int i=1;i<n;i++)
	{
		
		if(max_queue.top() > a[i])
		{
		//	cout<<"Inserting in max "<<a[i]<<endl;
			max_queue.push(a[i]);
		}
		else if(min_queue.empty() || min_queue.top() < a[i] )
		{
		//	cout<<"Inserting in min "<<a[i]<<endl;
			min_queue.push(a[i]);
		}
		else
		{
		//	cout<<" DEF Inserting in max "<<a[i]<<endl;
			max_queue.push(a[i]);
		}
		
		// now balance
		// I will allow max_queue to hold max 1 element more than the min queue;
		// the tops of queues will hold the values as follows
		// max_queue => max element in lower half
		// min_queue => min element of the upper half
		//cout<<"MAAX SIZE "<<max_queue.size()<<" MIIN SIZE "<<min_queue.size()<<endl;
		if(max_queue.size() - min_queue.size() ==2 )
		{
		//	cout<<"C1"<<endl;
			int to_be_added_to_min_queue = max_queue.top();
			max_queue.pop();
			min_queue.push(to_be_added_to_min_queue);	
		}
		else if(min_queue.size() > max_queue.size())
		{
		//	cout<<"C2"<<endl;
			int to_be_added_to_max_queue = min_queue.top();
			min_queue.pop();
			max_queue.push(to_be_added_to_max_queue);
		}
		
		
		priority_queue<int,vector<int>,heap_min> tm = min_queue;
		// printinf the elemets
		cout<<"Min Q : ";
		while(!tm.empty())
		{
			int x = tm.top();
			cout<<x<<" ";
			tm.pop();
		}
		cout<<endl;
		priority_queue<int,vector<int>,heap_max> tn = max_queue;
		// printinf the elemets
		cout<<"Max Q : ";
		while(!tn.empty())
		{
			int x = tn.top();
			cout<<x<<" ";
			tn.pop();
		}
		cout<<endl;
		
		// now median
		if( (min_queue.size()+max_queue.size() )% 2)
		{
			cout<<max_queue.top();
		}
		else
		{
			cout<<(max_queue.top()+min_queue.top())/2;
		}
		cout<<endl;
	}
	
	
}

int main()
{
	int a[]={10,3,7,2,8,6,1};
	//int a[]={1,5,10,15};
	find_medians(a,sizeof(a)/sizeof(int));
}


