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
	//char a;
	//string node_word;  // word if any forming upto the current node
	int prefixes; //no of words in the tree at present node with prefixes equal to the prefix of the string word
	int words; //no of words in the grapn that exactly match the string word
    struct node* edges[27];
};

//initialising each vertex
void initialise(node **v)
{
	*v = (node *)(malloc(sizeof(node)));
	node *vertex = *v;
	//vertex->word =NULL;
	vertex->prefixes=0;
	vertex->words=0;
	for(int i=0;i<26;i++)
	vertex->edges[i] = NULL;  //Null
}

// add words to tree
void addWord(node &x,int i,string word)
{
	if(i==word.size()-1)
	{
	x.words++;
	return;
    }
    else
    {
    	cout<<"Adding "<<word[i]<<endl;
    	x.prefixes++;
    	cout<<"Prefixes "<<word[i]<<" "<<x.prefixes<<endl;
    	if(x.edges[word[i+1]-97]==NULL)
    	{	                
    	cout<<"Init "<<word[i+1]<<endl;
    	initialise(&x.edges[word[i+1]-97]);       
    	
        }                                  
    	//now add alpabet recursively
    	addWord(*x.edges[word[i+1]-97],i+1,word);
   }
}

// number of words that exctly match the string 'word'
int getExactMatches(node x,int i,string word)
{
	cout<<"Checking "<<(int)(word[i]-97)<<endl;
	if(i==word.size()-1)
	{
		cout<<"Returning "<<word[i]<<endl;
		return x.words;
	}
	else if(x.edges[word[i+1]-97]==NULL)
		return -1;
	else
		return getExactMatches(*x.edges[word[i+1]-97],i+1,word);
}

// Number of words having the string 'word' as their prefix
int getPrefixMatches(node x,int i,string word)
{
	cout<<"Checking i "<<i<<" "<<word[i]<<endl;
	if(i==word.size()-1)
	{
		cout<<"Returning "<<x.prefixes<<endl;
		return x.prefixes;
	}
	else if(x.edges[word[i+1]-97]==NULL)
		return 0;
	else
		return getPrefixMatches(*x.edges[word[i+1]-97],i+1,word);
}

int main()
{
	node *nd[27];
	for(int i=0;i<27;i++)
	initialise(&nd[i]);
	string s[6] = {"tree", "trie", "algo", "assoc", "all", "also"};
	string word;
	// adding Words
	for(int i=0;i<6;i++)
	{
		addWord(*nd[s[i][0]-97],0,s[i]);
	}
	
	word="tr";
	cout<<getExactMatches(*nd[word[0]-97],0,word);
	cout<<getPrefixMatches(*nd[word[0]-97],0,word);
	return 0;
}


