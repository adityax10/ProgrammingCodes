#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

//Basic Strucutre of Tries
typedef struct node{
	int num; //no of words in the tree at present node with prefixes equal to the prefix of the string word
	int words; //no of words in the grapn that exactly match the string word
	int prefixes;
    struct node* edges[10];
};

//initialising each vertex
void initialise(node **v,int num)
{
	*v = (node *)(malloc(sizeof(node)));
	node *vertex = *v;
	vertex->num=num;
	vertex->words=0;
	for(int i=0;i<10;i++)
	vertex->edges[i] = 0;  //Null
}

// add words to tree
int addWord(node &x,int i,string word)
{
	if(i<word.length())
	{	
		if((x.edges[word[i]-48]!=NULL) && (((x.edges[word[i]-48]->words))||((i==word.length()-1)&& x.edges[word[i]-48]->prefixes)))
		return -1;
		
	//	cout<<"Num :"<<word[i]<<" tree "<<x.num<<" "<<" words "<<x.words<<endl;
		if(i==word.length()-1)
		{
	//		cout<<"Adding 1 : "<<word[i]<<endl;
			if(x.edges[word[i]-48]==NULL)
	    	{	                
	//    	cout<<"Init "<<word[i]<<endl;
	    	initialise(&x.edges[word[i]-48],word[i]-48);
	        } 
			x.edges[word[i]-48]->words++;
	    }
	    else
	    {
	//    	cout<<"Adding 2 : "<<word[i]<<endl;
	    
	    	if(x.edges[word[i]-48]==NULL)
	    	{	                
	//    	cout<<"Init "<<word[i]<<endl;
	    	initialise(&x.edges[word[i]-48],word[i]-48);
	        }                                
	        x.edges[word[i]-48]->prefixes++;
	    	//now add alpabet recursively
	    	return addWord(*x.edges[word[i]-48],i+1,word);
	   }
   }
}


int main()
{
	freopen("input.txt","r",stdin);
	node *nd;
	string s[10005];
	int n,cases,i;
	cin>>cases;
	while(cases--)
	{
		initialise(&nd,-1);
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>s[i];
	//	sort(s,s+n);
		// adding Words
		bool flag=0;
		for(i=0;i<n;i++)
		{
			if(addWord(*nd,0,s[i])==-1)
			{
				flag = 1;
				break;
			}
		}
		if(flag==0)
		cout<<"YES\n";
		else
		cout<<"NO\n";
		free(nd);
    }
	return 0;
}


