/* Extended version of power function that can work
 for float x and negative y*/
#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;
 
float power(float x, int y)
{
    float temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);      
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
} 
 
int main()
{
    float x = 4;
    int y = -2;
    printf("%f", power(x, y));
}
