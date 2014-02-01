#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

int hash(char rstr[],int start,int end)
{
	int hash=0;
	for(int i=start;i<end;i++)
	{
		hash = hash+(int)rstr[i]*31;
	}
	return hash;
}

void append(char rd[],char doc[],int index)
{
	rd[index]=doc[index];
}

int main()
{
	int i=0;
	char c[100],rd[100000];
	char doc[100000]="abckjnvsanvanvaabcoanaiosnciovncidsnfgilhpghevgpeeeeeeegiherpvmiervhwijcgnewiorcgn;oocnasknfx;aafxkjnlajfangabcjnsdkjabcisn;vosnnabcisonvdfiabc\0";
	cout<<"Enter the String to be searched\n";
	cin>>c;
	int len = strlen(c);
	int cHValue = hash(c,0,len);
	for(i=0;i<len;i++)
	rd[i]=doc[i];
	
	int lendoc = strlen(doc);
	cout<<lendoc<<"\n";
	while(i!=lendoc+1)
	{
		cout<<"checking b/w "<<i-len<<"to"<<i<<"\n";
		if(hash(rd,i-len,i)==cHValue)
		{
			cout<<"Match Found at i " << i-len<<"\n";
			//cout<<" Between  => "<<doc[i-len-1];//<<"|"<<doc[i]<<"\n";
		}
		append(rd,doc,i);
		i++;
    }

	getch();
	return 0;
}
