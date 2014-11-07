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
	char c;
	node *parent;
	int prefixes; //no of words in the tree at present node with prefixes equal to the prefix of the string word
	int words; //no of words in the grapn that exactly match the string word
    struct node* edges[27];
};

//initialising each vertex
void initialise(node **v,node *parent,char c)
{
	*v = (node *)(malloc(sizeof(node)));
	node *vertex = *v;
	vertex->c=c;
	vertex->parent = parent;
	vertex->prefixes=0;
	vertex->words=0;
	for(int i=0;i<26;i++)
	vertex->edges[i] = NULL;  //Null
}

// add words to tree
void addWord(node &x,int i,string word)
{
	if(i==word.length()-1)
	{
		cout<<"Adding "<<word[i]<<endl;
		if(x.edges[word[i]-97]==NULL)
    	{	                
    	cout<<"Init "<<word[i]<<endl;
    	initialise(&x.edges[word[i]-97],&x,word[i]);
        } 
		x.edges[word[i]-97]->words++;
		cout<<"Prefixes "<<word[i]<<" "<<x.edges[word[i]-97]->prefixes<<endl;
		cout<<"Word "<<word[i]<<" "<<x.edges[word[i]-97]->words<<endl;
		return;
    }
    else
    {
    	cout<<"Adding "<<word[i]<<endl;
    
    	if(x.edges[word[i]-97]==NULL)
    	{	                
    	cout<<"Init "<<word[i]<<endl;
    	initialise(&x.edges[word[i]-97],&x,word[i]);
        }                                
		x.edges[word[i]-97]->prefixes++;
		cout<<"Prefixes "<<word[i]<<" "<<x.edges[word[i]-97]->prefixes<<endl;
    	//now add alpabet recursively
    	addWord(*x.edges[word[i]-97],i+1,word);
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
	else if(x.edges[word[i]-97]==NULL)
		return -1;
	else
		return getExactMatches(*x.edges[word[i]-97],i+1,word);
}

// Number of words having the string 'word' as their prefix
int getPrefixMatches(node x,int i,string word)
{
	freopen("out_trie.txt","w",stdout);
	cout<<"Checking i "<<i<<" "<<word[i]<<endl;
	if(i==word.size()-1)
	{
		cout<<"Returning "<<x.prefixes<<endl;
		return x.prefixes;
	}
	else if(x.edges[word[i]-97]==NULL)
		return 0;
	else
		return getPrefixMatches(*x.edges[word[i]-97],i+1,word);
}

//string 'word' if any exsting in the trie which is nearly same as the string 'node_word' 
// with 'missingLetter' number of alphabets
//  suppose that you want to find a word in a dictionary but a single letter was deleted from the word.
int findMWords(node *x,int i,string word,int missingLetter)
{
	if(i>=word.size() || missingLetter<0)
	{
	cout<<"return \n"<<endl;
	return 0;
	}
	cout<<"Letter "<<word[i]<<endl;
	if((i==word.size()-1) && x->edges[word[i]-97] )
	{
		cout<<"Case 1"<<endl;
		cout<<"Ret "<<x->edges[word[i]-97]->words;
		
		return x->edges[word[i]-97]->words;
	}
	else if( x->edges[word[i]-97] == NULL && missingLetter!=0)
	{
		cout<<"Case 2"<<endl;
		// if word doesnt exist in the trie
		cout<<"exclude in 2 "<<word[i]<<endl;
		cout<<"INFO : node "<<x->c<<endl;
		cout<<"INFO : parent "<<x->parent->c<<endl;
		for(int i=0;i<27;i++)
		{
			if(x->edges[i])
			cout<<(char)(i+97)<<" ";
		}
		return findMWords(x,i+1,word,missingLetter-1);	
	}
	else if(x->edges[word[i]-97] == NULL)
	{
		cout<<"Case 3"<<endl;
		return 0;
	}
	else
	{
		cout<<"Case 4a"<<endl;
		cout<<"exclude "<<word[i]<<endl;
		
		// String 'word' letter ith was a fault/Misspelling
		int r = findMWords(x->edges[word[i]-97],i+1,word,missingLetter-1);
		
		// wasn't a misspell
		cout<<"Case 4b"<<endl;
		cout<<"include "<<word[i]<<endl;
		
		r+=findMWords(x->edges[word[i]-97],i+1,word,missingLetter);
		cout<<"R : "<<r<<endl;
		return r;
	}
}

int main()
{
	node *nd;
	initialise(&nd,0,0);
	string s[7] = {"tree", "algo", "trie", "assoc", "all", "also","alse"};
	string word;
	// adding Words
	for(int i=0;i<7;i++)
	{
		cout<<"String : "<<s[i]<<endl;
		addWord(*nd,0,s[i]);
		cout<<"Added"<<endl;
	}
	cout<<endl;
	cout<<endl;
	word="also";
	//cout<<getExactMatches(*nd,0,word)<<endl;
	//cout<<getPrefixMatches(*nd,0,word)<<endl;
	
	cout<<findMWords(nd,0,word,1)<<endl;
	
	return 0;
}


