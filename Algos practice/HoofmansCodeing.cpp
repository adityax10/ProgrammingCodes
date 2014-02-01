#include<iostream>
#include<queue>
#include<vector>
#include<conio.h>

using namespace std;

typedef struct node
{
	char a;
	int freq;
	node(const char &c,const int &f){a=c; freq=f; }
}node;

typedef struct treeNode
{
	int freq;
	struct treeNode *left,*right;
	treeNode()
	{
	}
	treeNode(const int &f,struct treeNode *l,struct treeNode *r)
	{
		freq=f;
		left=l;
		right=r;
	}
}treeNode;

class compareClass{
	public:
	bool operator() (struct treeNode &x,struct treeNode &y)
	{
		if(x.freq > y.freq)
		{
			return true;
		}
		return false;
	}
};

void inorder(treeNode *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->freq<<endl;
		inorder(root->right);
	//	getch();
	}
}

priority_queue<treeNode,vector<treeNode>,compareClass> Q;
	
treeNode hoffmans(vector<node> &words)
{
	
	for(int i=0;i<words.size();i++)
	Q.push(treeNode(words[i].freq,NULL,NULL));
	
	while(Q.size()!=1)
	{
		
		//poping out the 2 min nodes
		treeNode *f1=new treeNode();
		*f1=Q.top();
		Q.pop();
		treeNode *f2=new treeNode();
		*f2=Q.top();
		Q.pop();
		cout<<"Popped :"<<f1->freq<<" "<<f2->freq<<endl<<"Inserting :"<<f1->freq+f2->freq<<endl;
		treeNode t(f1->freq+f2->freq,f1,f2);
		Q.push(t);
	}
	
	return Q.top();
}
int main()
{
	vector<node> words;
	
	words.push_back(node('a',45));
	words.push_back(node('b',13));
	words.push_back(node('c',12));
	words.push_back(node('d',16));
	words.push_back(node('e',9));
	words.push_back(node('f',5));

	treeNode root = hoffmans(words);
	inorder(&root);
	
	return 0;
}
