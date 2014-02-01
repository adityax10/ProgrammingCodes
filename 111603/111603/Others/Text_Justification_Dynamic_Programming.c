#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

#define PAGELENGTH 10
#define MAX 32767

int text_justification_values[100];

//the more the value is closer to zero... lower the badness n  better the jstification
//badness tells how bad the justification is...
float badness(char words[],int i,int j)
{
	int linelength=0;
   while(i<=j)
   {
		//linelength = strlen(words[i])+linelength;
		i++;
   }
   if(linelength>PAGELENGTH)
   {
		return MAX;
   }
   else
   return pow((PAGELENGTH-linelength),3);
}


int text_justification(char words[],int i,int n)
{
  int j,q=MAX;
  if(i==n)
  return 0;
  
  
  for(j=i+1;j<=n;j++)
  {
	  q=min(q,text_justification(words,j,n)+badness(words,i,j));
  }
  text_justification_values[i]=q;
   return q;
}


int main()
{
	int i,k=0,j=0;
	char words[100][20];
	 char str[200]="Hello My Name Is Aditya Vats !! How Are you !! How do you Do ?? Do you like Android ! The latest version is Key Lime Pie";

	 for(i=0;i<strlen(str);i++)
	 {
			if(str[i]!=' ')
			{
				printf("%d ",i);
				words[k][j]=str[i];
				j++;
			}
			if(str[i]==' ' || i==strlen(str)-1)
			{
				words[k][j]='\0';
				printf("word  made = %s ,Length =  \n",words[k],strlen(words[k]));
							k++;j=0;
			}
  }
  
  
	for(i=0;i<100;i++)
	{
		text_justification_values[i]=MAX;
	}

	 
	 //text_justification(words,0,k-1);
	 getch();
}
