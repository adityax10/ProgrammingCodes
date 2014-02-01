#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

#define PAGELENGTH 15
#define MAX 32767

int split_text_word_number;

int min(int x,int y)
{
    return x>y?y:x;
}

//the more the value is closer to zero... lower the badness n  better the jstification
//badness tells how bad the justification is...
float badness(char *words,int i,int j)
{
	int linelength=0;
   while(i<=j)
   {
		linelength = strlen(words+20*i)+linelength;
		i++;
   }
   if(linelength>PAGELENGTH)
   {
		return MAX;
   }
   else
   return pow((PAGELENGTH-linelength),3);
}


int text_justification(char *words,int i,int n)
{
    if(i<n)
    {
  printf("word is %s \n",words+20*i);
  //getch();
  int j,q=0,prev_q=MAX;
  if(i==n)
  return 0;

  for(j=i+1;j<=n;j++)
  {
      printf("searching badness b/w %d to %d , ",i,j);
	  q=badness(words,i,j);
	  printf("q is %d\n",q);
	  if(q==MAX)
	  break;
	  if(q<prev_q)
	  {
	  split_text_word_number=j;
	  prev_q = q;
	  }
  }
  //text_justification_values[i]=q;
  printf("Split after %d and form the word %s\n",split_text_word_number,words+20*split_text_word_number);
  text_justification(words,split_text_word_number+1,n);
  return q;
    }
    else
    return -1;
}


int main()
{
	int i,k=0,j=0;
	char words[100][20];
	 char str[200]="Hello My Name Is Aditya Vats !! How Are you !! How do you Do ?? Do you like Android ! The latest version is Key Lime Pie";
    //char str[200] = "hey My Name Is Aditya";
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
				printf("word  made = %s ,Length =  %d\n",words[k],strlen(words[k]));
							k++;j=0;
			}
  }



	 text_justification(words,0,k-1);
	 //getch();
}
