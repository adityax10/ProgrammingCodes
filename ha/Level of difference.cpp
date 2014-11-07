#include<iostream>
#include<cstring>
using namespace std;

int check(char q[],char temp,int x)
{
    for(int i=0;i<x;i++)
    {
        if(temp==q[i])
        {
        return 0;
        }
    }
    return 1;
}

char *split(char c[],int j,int x,int gap)
{
    //cout<<"in split\n";
    int k=0;
    char temp[1000];
    for(int i=j;i<j+gap;i++)
    {
    temp[k]=c[i];
    k++;
    }
    temp[k]=NULL;
    cout<<"Split returnd is "<<temp<<"\n";
    return temp;//not able to return string..!!
}




void combs(char c[],int x,char *q)
{
    cout<<"Entered into combs\n";
    int gap,j,k=0;
    char *temp;
    q[0]=0;
    for(gap=1;gap<=x;gap++)
    {
        for(j=0;(j<x)&&(x-j+1)>gap;j++)
        {
            cout<<"Preparing to split with gap ="<<gap<<"\n";
            temp=split(c,j,x,gap);
              cout<<"temp recieved is =  "<<temp<<"  in combs\n";
             if(check(q,*temp,k))
             {q[k]=*temp;
             cout<<"Added in q ="<<q[k]<<"\n";
             k++;}

        }
    }

}

int main()
{
    char a[100000],b[100000],store[5000];
    cin>>a;
    int x=strlen(a);
    int y=strlen(b);

    combs(a,x,store);



 return 0;
}
