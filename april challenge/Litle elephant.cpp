#include<iostream>
#include<stdio.h>
using namespace std;

struct song{
		int b;
		int l;
   };
   
   


int main()
{
   song s[100000];
   int cases,n,i,n_vary,sweetness=0,match=0,count_band=0,j,k;
   cin>>cases;
   while(cases>0)
   {
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>s[i].b>>s[i].l;
		}
		//Chnage the sorting algo to make it more faster.. currntly using bubble sort..:)
  /* n_vary=n;
	for(j=0;j<n;j++)
	{
		//song *temp = &(s[j]);
		for(k=0;k<n_vary-1;k++)
		{
			if(s[k].l>s[k+1].l)
			{
                song x;
				x=s[k];
				s[k]=s[k+1];
				s[k+1]=x;
				//cout<<"\nreplacing "<<s[k].l<<" & "<<s[k+1].l;
		}
		}
		n_vary--;
	}*/
	 for(k=0;k<n;k++)
	 {
		 for(j=k-1;j>=0;j--)
		 {
				if(s[j].b==s[k].b)
				{
				match=1;
				//cout<<"match found\n";
				break;
			    }
		 }
		 if(match==0)
		 {
				count_band++;
    //cout<<"incrementing at "<<s[k].b<<"&" <<s[k].l<<"bands_count = "<<count_band<<"\n";
		 }
		 sweetness=sweetness+s[k].l*count_band;
		 match=0;

	 }

	cout<<sweetness<<"\n";
	sweetness=0;
	match=0;
	count_band=0;
	cases--;
   }
   
   

   //getch();
   return 0;
}
