#include<stdio.h>
int arr[100005][2];
void msort(int a[][2],int left,int right);
int main()
{
//	freopen("in.txy.cpp","r",stdin);
    int n,m,p,i,ans,j,dk,curr,next,no_curr,no_next,start,end,k;
    scanf("%d%d%d",&n,&m,&p);
    for(i=0;i<p;i++)
    {
       scanf("%d%d",&arr[i][0],&arr[i][1]);
    }
    msort(arr,0,p-1);
    //for(i=0;i<p;i++)
       //printf("%d  %d\n",arr[i][0],arr[i][1]);
    j=0;
    for(i=1;i<=n;i++)
    {
       start=1;
       end=m;
       ans=end-start;
       while(arr[j][0]<i)
       {
          j++;
       }
       k=j;
       if(arr[j][0]==i)
       {
          dk=k;
          while(4)
          {
             curr=no_curr=next=no_next=0;
             k=dk;
             curr=arr[k][1];
             while((arr[k][1]==curr)&&(arr[k][0]==i))
             {
                no_curr++;
                k++;
             }
             if(curr==1)
             {
                start=start+no_curr;
                //printf("Start is %d ",start);
             }
             if(curr==m)
             {
                end=end+no_curr;
             }
             dk=k;
             next=curr+1;
             if((arr[k][1]==next)&&(arr[k][0]==i))
             {
                while((arr[k][1]==next)&&(arr[k][0]==i))
                {
                   no_next++;
                   k++;
                }  
             }
             if(next==m)
             {
                end=end+no_next;
                //printf("end is %d ",end);
             }
             ans=end-start;
             if(((no_curr)-(no_next)>1)&&(curr!=m))
             {
                ans=-1;
                break;
             }
             if(arr[k][0]!=i)
                break;
          }
       }
       printf("%d\n",ans);
    }
    //getch();
    return 0;
}
void msort(int a[][2],int left,int right)
{
int temp[right-left+1][2],i=0,j,k=0,mid;
if(left<right)
{
mid=(left+right)/2; 
msort(a,left,mid); 
msort(a,mid+1,right);
}

mid=(left+right)/2;
i=left;
j=mid+1;
while((i<=mid)&&(j<=right))
{
if(a[i][0]<a[j][0])
{
temp[k][0]=a[i][0];
temp[k][1]=a[i][1];
k++;i++;
}
else if(a[i][0]==a[j][0])
{
   if(a[i][1]<a[j][1])
   {
      temp[k][0]=a[i][0];
      temp[k][1]=a[i][1];
      i++;k++;
   }
   else if(a[i][1]==a[j][1])
   {
      temp[k][0]=a[i][0];
      temp[k][1]=a[i][1];
      k++;i++;
      temp[k][0]=a[j][0];
      temp[k][1]=a[j][1];
      k++;j++;      
   }
   else if(a[i][1]>a[j][1])
   {
       temp[k][0]=a[j][0];
       temp[k][1]=a[j][1];
       j++;k++;
   }
}
else if(a[i][0]>a[j][0])
{
temp[k][0]=a[j][0];
temp[k][1]=a[j][1];    
k++;j++;    
}
}
while(i<=mid)
{
temp[k][0]=a[i][0];
temp[k][1]=a[i][1];             
i++;k++;             
}
while(j<=right)
{
temp[k][0]=a[j][0];
temp[k][1]=a[j][1];               
j++;               
k++;               
}
for(i=0;i<k;i++)
{
a[i+left][0]=temp[i][0];                
a[i+left][1]=temp[i][1];
//printf("VOLa    %d    %d\n",a[i+left][0],a[i+left][1]);
}
}
