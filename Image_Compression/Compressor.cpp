#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<stdio.h>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

class node{
	public :
   int freq;
   struct node *left,*right;
   bool is_leaf; // character will be checked for a node only when is_leaf = true 
   int character;
   //constructors
   node(){
   };
   node(int x){
   };
   node(int f,node *l,node *r,bool leaf_status)
   {
   		freq = f;
   		left = l;
   		right = r;
   		is_leaf = leaf_status;
   }
};

vector<int> m(256);

class compare_class{
    public:
  bool operator() (const node &lhs, const node &rhs) const
  {
    return (lhs.freq > rhs.freq ); //min pq
  }
};

priority_queue<node,vector<node>,compare_class> pq; // pair<char,int>

void huffman()
{
    //Building priority_queue
    for(int i=0;i<256;i++)
    {
        node x;
        x.freq = m[i];
        x.left=NULL;
        x.right=NULL;   
		x.is_leaf=true;
        x.character = i; // using ansi code instead of char
        pq.push(x);
    }
    
    //See if root has been reached
    // building the huffmans tree
    while(pq.size()!=1)
    {
    	//findins 2 min freqs
        node *n1 = new node();
		*n1 = pq.top();
        pq.pop();
        node *n2 = new node();
		*n2 = pq.top();
        pq.pop();
        //pushing combined into pq
        node n(n1->freq + n2->freq,n1,n2,false);
        pq.push(n);
    }
}


int main()
{
    //freopen("//root//Desktop//img.jpg","r",stdin);
    FILE *f;
    f = fopen("abc.bmp","rb");
    int c;

    while((c=fgetc(f))!=EOF)
    {
       m[c]++;
    }
    //sort(m.begin(),m.end()); // No need.. pq will handel this
    
    for(int i=0;i<m.size();i++)
    {
        cout<<i<<" "<<m[i]<<endl;
    }
    huffman();
}

