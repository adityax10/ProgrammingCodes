#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
#include<bitset>
using namespace std;

//BIT Binary Indexed Tree
class BIT{ 
	vector<int> *bitArray;
	int bitSize;
	//Initialisng BIT
	public :
	BIT(const vector<int> &x)
	{
		initaliseBIT(x);
	}
	//Making A BIT
	int initaliseBIT(const vector<int> &x)
	{
		bitSize = x.size()+1;
		
		bitArray = new vector<int>(bitSize);
		
		for(int i=0;i<=bitSize;i++)
		(*bitArray)[i]=0;
		
		for(int i=1;i<bitSize;i++)
		{
			int val = x[i-1];
			int idx = i;
			// log(n)
			while(idx<bitSize)
			{
				(*bitArray)[idx] += val;
				 idx += (idx&-idx);
			}
		}
		for(int i=1;i<bitSize;i++)
		cout<<(*bitArray)[i]<<" ";
		cout<<endl;
	}
	
	// Retrieving sum of range From Bit
	int retrieve(int s,int f)
	{
		int sum_s=0,sum_f=0;
	//	s++; then s--; 
		f++;
		while(s>0)
		{
			sum_s += (*bitArray)[s];
			s -= (s&-s);
		}
		while(f>0)
		{
			sum_f += (*bitArray)[f];
			f -= (f&-f);
			//cout<<sum_f<<" ";
		}
		return sum_f-sum_s;
	}
	
	//Retrive an element a bit faster
	int retrieve_element(int x)
	{
		x++;
		int sum_x=0;
		if(x>0)
		{
			int y = x-(x&-x);
			sum_x=(*bitArray)[x];// this sum will be reduced
			cout<<"VAl is "<<sum_x<<endl;
			x--;
			while(y!=x)
			{
				sum_x -= (*bitArray)[x];
				x -= x&-x;
			}
		}
		return sum_x;
	}
	
	//update a range
	void update_range(int s,int f,int val)
	{
		while(s<=f)
		{
			update_element(s,val);
			s++;
		}
	}
	
	// Updating an element in a BIT
	void update_element(int index,int val)
	{
		index++;
		while(index<bitSize)
		{
			(*bitArray)[index] += val;
			index+=(index&-index);
		//	cout<<"inc";
		}	
	}
	
	//Scale Tree
	void scale_tree(int scale)
	{
		for(int i=1;i<bitSize;i++)
		{
			(*bitArray)[i] /= scale;
			cout<<((*bitArray)[i])<<" ";
		}
		cout<<endl;
	}
	
	int find(int freq)
	{
		int idx=0,tidx;
		int bitMax = 0;
		//find max value corresponding to an index
		
		// bitMax - initialy, it is the greatest bit of MaxVal
		// bitMax store interval which should be searched
		for(int i=1;i<bitSize;i++)
		{
			if((*bitArray)[i] > (*bitArray)[bitMax])
			{
				bitMax = i;
			}
		}
		
		while((tidx < bitSize )&& (bitMax!=0))
		{
			//cout<<"L1 : "<<tidx<<" "<<bitMax<<endl;
			tidx = idx + bitMax;
			//cout<<"Lc :"<<tidx<<" "<<bitMax<<endl;
			if(freq >= (*bitArray)[tidx])
			{
				freq -= (*bitArray)[tidx]; //freq must include the elemnts upto tidx
				idx = tidx; //including tidx
				//cout<<"freq : "<<freq<<endl;
			}
				bitMax >>=1;
			//cout<<"L2 : "<<tidx<<" "<<bitMax<<endl;
		}
		if(freq !=0)
		return -1;
		else
		return idx;
	}
};

int main()
{
	int arr[] ={1,2,3,4,5,6};
	//int arr[] = {1,0,2,1,1,3,0,4,2,5,2,2,3,1,0,2};
	vector<int> a ( arr , arr + sizeof(arr)/sizeof(int));
	BIT b(a);
	cout << b.retrieve(0,5)<<endl; //indexes start from 0
	//b.update_range(0,5,1);
	cout << b.retrieve(0,5)<<endl;	
	//b.update_range(0,5,-1);
	cout<<b.retrieve_element(3)<<endl;
//	b.scale_tree(2);
	cout<<b.retrieve_element(3)<<endl; //NOTE : Retrieving vale 4 at index 3 is giving erorrs
	//cout<<b.retrieve(0,3)-b.retrieve(0,2);
	cout<<b.find(5)<<endl;
}


