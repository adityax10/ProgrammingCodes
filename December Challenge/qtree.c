#include<stdio.h>
#include<vector>
#define GETCHAR getchar
#define PUTCHAR putchar
#ifdef ONLINE_JUDGE
#undef GETCHAR
#undef PUTCHAR
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif

inline long long int readLong() 
{
	int flag=1;
    long long int n = 0;
    char c;
    int parity=1;
    int i=0;
    while (1)
    { 
              c=GETCHAR();
              if(i==0&&c=='-') parity=-1;
              else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break; 
              i++;
    }
    return parity*n;
}

inline void writeInt(int x) 
{
     int i = 20;
     char buf[21];
     buf[20] = '\n';
     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
}

typedef struct node
{
	int nam;
	int color; //0->black,1->white
	vector< struct node* >link; //neighbours
}node;

node c[100010];
int n;
int visited[100010];

unsigned long long int ans;

void inline connected_colors(int x)
{
	if(!visited[x])
	{
		visited[x]=1;
		//cout<<"Inserted node : "<<x<<endl;
		for(int i=0;i<c[x].link.size();i++)
		{
			if(c[x].color == c[x].link[i]->color && !visited[c[x].link[i]->nam] )
			{
				//cout<<"Got ! : "<<c[x].link[i]->nam<<endl;
				ans++;
				connected_colors(c[x].link[i]->nam);
			}
		}
	}
	return ;
}

int main()
{
	n=readLong();
	int i = n;
	int c_n,c_l;
	while((i--)-1)
	{
		c_n=readLong();
		c_l=readLong();
	    c[c_l].nam=c_l;
		c[c_n].nam = c_n;
		//c[c_n].color = 0;
		//c[c_l].color = 0;
		c[c_n].link.push_back(&c[c_l]);
		c[c_l].link.push_back(&c[c_n]);
	}
	
	/*for(int i=1;i<=n;i++)
	{
		cout<<"Node : "<<c[i].nam<<endl;
		cout<<"Color : "<<c[i].color;
		cout<<"Links :\n";
		for(int j=0;j<c[i].link.size();j++)
		{
			cout<<c[i].link[j]->nam<<" ";
		}
		cout<<"\n";
	}*/
	int cases,x;
	cases=readLong();
	while(cases--)
	{
		x=readLong();
		i=readLong();
		if(x==0)
		{	
			ans=1;
			connected_colors(i);
			writeInt(ans);
			for(int i=1;i<=n;i++)
			visited[i]=0;
	    }
	    else
	    {
	    	c[i].color = !(c[i].color); //toggle
	    }
    }
	return 0;
}


