#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

struct node{
	int data;
	struct node *left,*right;
};

map<int,int> L; // For storing level of a node
map<int,int> P; // For storing the upper level(level means one of the sqrt(h) partitions) parents of the node in a lower level
map<int,int> T; // For storing the parents of a node
int max_level;

node* create_node(int data)
{
	node *n = (node *)malloc(sizeof(node));
	n->data = data;
	n->left=0;
	n->right=0;
	return n; 
}

void initialise_values(node *t,int level)
{
	if(t != NULL )
	{
		L[t->data]=level;
		max_level = max(level,max_level);
		if(level==0)
		T[t->data]=t->data;
		
		if(t->left)
		{
			T[t->left->data] = t->data;
			initialise_values(t->left,level+1);
		}
		if(t->right)
		{
			T[t->right->data] = t->data;
			initialise_values(t->right,level+1);
		}
	}
}

// using dfs approach on the tree to set the values of P

//T[i] is the father of node i in the tree,
// nr is [sqrt(H)] and
// L[i] is the level of the node i

void dfs(node *t,int nr)  
{
	if(t)
	{
		int node_d = t->data;
		//if node is situated in the first 
		//section then P[node] = 1
	    if (L[node_d] < nr)
	      P[node_d] = 1;
	    //if node is situated at the beginning
		//of some section then P[node] = T[node]
	  	else
	      if(!(L[node_d] % nr))
	          P[node_d] = T[node_d];
	    //if none of those two cases occurs, then 
		//P[node] = P[T[node]]
	      else
	          P[node_d] = P[T[node_d]];
		
	     dfs(t->left ,nr);
	     dfs(t->right,nr);
	}
}

int find_LCA(int x,int y)
{
  //as long as the node in the next section of 
  //x and y is not one common ancestor
  //we get the node situated on the smaller 
  //lever closer
  // in other words.. trying to bring the 2 nodes int the same section
  while(P[x]!=P[y])
  {
  	if(L[x]<L[y])
  	y = P[y];
  	else
  	x = P[x];
  }
  
  //now since we have reached the same section,
  // we will move slowly by using the parent array to find if we have reached
  // the same parent i.e. LCA
  while(x!=y)
  {
  	if(L[x]<L[y])
  	y = T[y];
  	else
  	x = T[x];
  }
  return x;
}

int main()
{
	node *t;
	t = create_node(20);
	t->left = create_node(8);
	t->right = create_node(22);
	t->left->left= create_node(4);
	t->left->right = create_node(12);
	t->left->right->left = create_node(10);
	t->left->right->right = create_node(14);
	t->right = create_node(22);
	
	
	//setting the level array
	initialise_values(t,0);
	dfs(t,sqrt(max_level+1));
//	for(auto i=T.begin();i!=T.end();i++)
//	cout<<i->first<<" "<<i->second<<endl;

	cout<<find_LCA(10,14);
	
	return 0;
}


