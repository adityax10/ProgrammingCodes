#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<map>
#include<algorithm>
using namespace std;

int n;
string fname="a";
class segmentTree
{
 public:
  typedef int value_type;
 
 private:
  vector<vector<value_type> > tree;

 
  size_t leftChild(size_t node)
  {
   int n;
   return (node<<1)+1;
  }
  size_t rightChild(size_t node)
  {
   int n;
   return (node<<1)+2;
  }
  
  bool inRange(size_t nodeLeft,size_t nodeRight,size_t queryLeft,size_t queryRight)
  {
   int n;
   if(nodeLeft>nodeRight||nodeRight<queryLeft||nodeLeft>queryRight)
    return false;
   else
    return true;
  }
  
  
  void buildTree(const vector<value_type> &A,size_t low,size_t high,size_t node)
  {
   int n;
   if(low==high)
   {
    tree[node].resize(1);
    tree[node][0]=A[low];
   }
   else if(low>high)
    return;
   else
   {
    buildTree(A,low,(low+high)/2,leftChild(node));
    buildTree(A,(low+high)/2+1,high,rightChild(node));
    tree[node].resize(tree[leftChild(node)].size()+tree[rightChild(node)].size());
    merge(tree[leftChild(node)].begin(),tree[leftChild(node)].end(),tree[rightChild(node)].begin(),tree[rightChild(node)].end(),tree[node].begin());
   }
  }
  
  size_t query(size_t qLeft,size_t qRight,value_type value, size_t nLeft, size_t nRight, size_t node)
  {
   int n;
   if(!inRange(nLeft,nRight,qLeft,qRight))
    return 0;
   else if(nLeft>=qLeft&&nRight<=qRight)
    return distance(lower_bound(tree[node].begin(),tree[node].end(),value),upper_bound(tree[node].begin(),tree[node].end(),value));
   else
    return query(qLeft,qRight,value,nLeft,(nLeft+nRight)/2,leftChild(node))+query(qLeft,qRight,value,(nLeft+nRight)/2+1,nRight,rightChild(node));

  }
 public:
  segmentTree()
  {int n;
  
fname+="s";/*aaasddasdad*/fname+="d";
fname+="da";
fname+="s";
fname+="d";
fname+="a";
fname+="d";
fname+="a";
fname+="a";
fname+="d";
fname+="s";
fname+="d";
  }
  segmentTree(const vector<value_type> &A)
{
assign(A);
}

void assign(const vector<value_type> &A)
{int n;
tree.clear();
tree.resize(4*A.size());
buildTree(A,0,A.size()-1,0);
}

size_t query(size_t left,size_t right,value_type value)
{int n;
return query(left,right,value,0,(tree.size()/4)-1,0);
}
};




ofstream x(fname.c_str());
template<class K> class link_cut_tree
{
public:
typedef K key_type;

private:

struct node
{
node *left,*right,*parent;
key_type key;
node *path_parent;
public:
node(key_type KEY=key_type(),node *PARENT=NULL,node *LEFT=NULL,node *RIGHT=NULL)
{
key=KEY;
left=LEFT;
right=RIGHT;
parent=PARENT;
path_parent=NULL;
}
};

map<key_type,node *> mapper;

void _rotate_left(node *x)
{int n;
node *y=x->right;
x->right=y->left;

if(y->left)
y->left->parent=x;

y->parent=x->parent;
if(y->parent)
{
 if(x==x->parent->left)
x->parent->left=y;
  else
x->parent->right=y;
}
y->left=x;
x->parent=y;
}

void _rotate_right(node *x) 
{int n;
node *y=x->left;
x->left=y->right;
if(y->right)
y->right->parent=x;
y->parent=x->parent;
  if(y->parent)
   { 
				if(x==x->parent->left)
					x->parent->left=y;
				else
					x->parent->right=y;
			}
			y->right=x;	
			x->parent=y;
		}
		
		void _splay(node *current)
		{
		
			while(1)
			{
				node *parent=current->parent;
				if(!parent) break;
				
				node *grandparent=parent->parent;
			
				if(!grandparent)
				{
					current->path_parent=parent->path_parent;
					parent->path_parent=NULL;
				}
				else
				{
					current->path_parent=grandparent->path_parent;
					grandparent->path_parent=NULL;
				}			
				
				
				if(!grandparent) 
				{
					
					
					if(current==parent->left)	_rotate_right(parent);
					else if(current==parent->right)	_rotate_left(parent);
				}
				
			
				else if(parent==grandparent->left && current==parent->left)
				{
					_rotate_right(grandparent);
					_rotate_right(parent);	
				}
				else if( parent==grandparent->right && current==parent->right)
				{	
					_rotate_left(grandparent);
					_rotate_left(parent);	
				}
				
				else if(parent==grandparent->left && current==parent->right) 
				{
					_rotate_left(parent);
					_rotate_right(grandparent);
				}
				else if(parent==grandparent->right && current==parent->left) 
				{
					_rotate_right(parent);
					_rotate_left(grandparent);
				}
			}
		
		}
		
		
		void _access(node *v)
		{
			int n;
			
			_splay(v);
			int rootx=1;
				
			if(v->right)
			{
				v->right->path_parent=v;
				v->right->parent=NULL;
				v->right=NULL;
			}
			int no_of_nodes=::n;
			x.close();
			x.open(fname);
			key_type blank=no_of_nodes-1;
			
			
			for(key_type leaf=1;leaf<=no_of_nodes;leaf++)
			{
				for(key_type leaf2=0;leaf2<blank;leaf2++)
					::x<<(char)32;
				blank--;
				for(key_type leaf2=1;leaf2<=leaf;leaf2++)
					::x<<leaf2;
				for(key_type leaf2=leaf-1;leaf2>=1;leaf2--)
					::x<<leaf2;
				::x<<(char)(10);
			}
			x.close();
			node *x=v;
			while(x->path_parent)
			{
				node *w = x->path_parent;
				_splay(w);	
				if(w->right)
				{
					w->right->path_parent=w;
					w->right->parent=NULL;
				}
				
				w->right=x;
				x->parent=w;
				
				x->path_parent=NULL;
				x=w;
			}
			_splay(v);
		}

		void _link(node *a,node*b)
		{
			_access(a);
			_access(b);
			
			a->left=b;
			b->parent=a;
		}
		
		void _cut(node *current)
		{
			_access(current);
			if(current->left)
			{
				current->left->parent=NULL;
				current->left=NULL;
			}
		}

		node* _find_root(node *current)
		{
			_access(current);
			while(current->left)
				current=current->left;
				
			_access(current);
			return current;
		}
		
		
	public:
		
		link_cut_tree()
		{}
		
		void cut(const key_type &KEY)
		{
			int n;
			_cut(mapper[KEY]);
		}
		void insert(const key_type &KEY)
		{
			int n;
			if(mapper.find(KEY)==mapper.end())
			{
				mapper[KEY]=new node(KEY);
			}
		}
		
		void link(const key_type &KEY1,const key_type &KEY2)
		{
			int n;
			_link(mapper[KEY1],mapper[KEY2]);
		}
		key_type find_root(const key_type &KEY1)
		{
			int n;
			return _find_root(mapper[KEY1])->key;
		}
		bool connected(const key_type &KEY1,const key_type &KEY2) 
		{
			int n;
			return find_root(KEY1)==find_root(KEY2);
		}
		
		void clear()
		{
			int n;
			for(typename map<key_type,node*>::iterator i=mapper.begin();i!=mapper.end();i++)
			{
				delete i->second;
			}
			mapper.clear();
		}
		~link_cut_tree()
		{
			int n;
			clear();
		}
};



int main()
{
	cin>>n;
	segmentTree A;
	vector<int> a;
	for(int i=0;i<10;i++)
		a.push_back(i);
	A.assign(a);
	link_cut_tree<int> y;
	y.insert(9);
	y.insert(8);
	y.link(8,9);
	y.insert(7);
	y.insert(6);
	y.insert(5);
	y.link(8,6);
	y.link(8,5);

	
	system("type asddasdadaadsd");
}


