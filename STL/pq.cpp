#include<iostream>
#include<queue>

using namespace std;

typedef struct node{
	int val;
	int array_no;
	int index;
	bool operator< (const node &x) const {if(x.val > x.val)
	return true;
	else
	return false;
	}
}
node;
int assign_heap(int n,int a[][4])
{
	priority_queue<node> x;
	node n1;
	int *ans,k=0;
	
	for(int i=0;i<n;i++)
	{
		cout<<a[i][0]<<"\n";
		n1.val=a[i][0];
		n1.array_no=i;
		n1.index=0;
		x.push(n1);
	}
	
	node temp;
	
	
	while(!x.empty())
	{
		temp = x.top();
		x.pop();
		cout<<"poped = "<<temp.val<<"\n";
		//ans[k]=temp.val;
		
		int index = temp.index;
		int array_no = temp.array_no;
		
		if(index+1<n)
		{
		n1.val=a[array_no][index+1];
		n1.array_no=array_no;
		n1.index=index+1;
		x.push(n1);
		//cout<<"Pushing "<<n1.val<<"\n";
	    }
		
	}
	
	return 1;
}

int main()
{
	//initalising
	int array[3][4]={{2,3,4,5},{77,88,99,188},{10,33,55,72}},n=3;//n = rows
	//int *ans;
	assign_heap(n,array);
	
	return 0;
}
