
//Complexity O( sqrt(n));

#include<stdio.h>
#include<math.h>

int main()
{
   int n;
   int i=2;
   scanf("%d",&n);
   while(i <= sqrt(n))
    {
        if(n%i==0) {
                  printf("%d,",i);
                  printf("%d,",n/i);
        }

        i++;
    }
  // if(i*i == n)
   //     printf("%d,",i);                                                                                                                                
}
