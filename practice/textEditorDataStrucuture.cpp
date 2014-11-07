#include<bits/stdc++.h>
using namespace std;

class compClass
{
	public:
		bool operator()(const pair<int,int> &a,const pair<int,int> &b)
		{
			return a.first < b. first;
		}
	
};

class textEditorFile
{
	public:
		string text;
		priority_queue<pair<int,int>,vector<pair<int,int>> , compClass> bold;
		priority_queue<pair<int,int>,vector<pair<int,int>> , compClass> italics;
		
		textEditorFile(string s)
		{
			this->text = s;
		}
		
		void make_bold(int l,int r)
		{
			bold.push(make_pair(l,r));
		}
		
		void make_italics(int l,int r)
		{
			italics.push(make_pair(l,r));
		}
};

int main()
{
	textEditorFile *f = new textEditorFile("HELLO WORLD! THIS IS A TEXT FILE");
	cout<<f->text<<endl;
	
	f->make_bold(0,5);
	f->make_italics(9,12);
	
	return 0;
}


