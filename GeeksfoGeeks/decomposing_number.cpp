    #include<iostream>
    using namespace std;
    void printArr(int p[],int ind)
    {
    for(int j=0;j<=ind;j++)
    cout<<p[j]<<" ";
    cout<<endl;
    }
    void partsRecur(int p[],int n,int ind)
    {
    int rem;
    if(n==0){
    printArr(p,ind-1);
    return;
    }
    for(int i=1;i<=n;i++)
    {
    rem=n-i;
    p[ind]=i;
    partsRecur(p,rem,ind+1);
    }
    }
    void parts(int n)
    {
    int p[n];
    partsRecur(p,n,0);
    }
    int main()
    {
    parts(2);
    cout<<endl;
    parts(3);
    cout<<endl;
    parts(4);
    return 0;
    }
