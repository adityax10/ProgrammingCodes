#include<stdio.h>
#include<string.h>
int main()
{
char str[1000];
int i=0,j,k,n,test=0,checked[500],found=0,count=0;
scanf("%d",&test);

while(test>0)
{
scanf("%s",&str);
n=strlen(str);

for(i=0;i<n/2;i++)
checked[i]=0;

if(n%2)
i=n/2+1;
else
i=n/2;

found=0;count=0;
k=i;j=0;
//printf("k = %d\n",k);
for(j=0;j<n/2;j++)
{
 while(k<n)
  {
	  //printf("comparing %c and %c\n",str[j],str[k]);
	  if((str[j]==str[k])&&(checked[k-i]==0))
	  {checked[k-i]=1;
	  //printf("%c matched with %c\n",str[j],str[k]);
	  found++;
	  count++;
	  break;
	  }
	  else
	  {
	  k++;
	  //printf("incrementing k for %c\n",str[j]);
	  }
  }
k=i;

if(found==0)
{printf("NO\n");
break;
}
found=0;
}
if(count==n/2)
printf("YES\n");
test--;
}
return 0;
}

