# include <stdio.h>

/* Function to swap values at two pointers */
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int s, int n)
{
   int j;
   if (s == n)
     printf("%s\n", a);
   else
   {
        for (j = s; j <= n; j++)
       {
          swap((a+s), (a+j));
          permute(a, s+1, n);
          swap((a+s), (a+j)); //backtrack
       }
   }
}

/* Driver program to test above functions */
int main()
{
   char a[] = "ABC";
   permute(a, 0, 2);
   getchar();
   return 0;
}


