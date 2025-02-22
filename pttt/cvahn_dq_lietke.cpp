#include<bits/stdc++.h>
using namespace std;
fstream fi,fo;
int a[100],n,k,t;
void inkq(int k)
{
    if(k>1)
    {
        for(int i=1;i<=k;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
}
void lietke(int i,int t)
{
    for(int j=a[i-1];j<=n-t;j++)
    {
        a[i]=j;
        if(t+j==n) inkq(i);
        if(t<n) lietke(i+1,t+j);
    }
}
int main()
{
    cin>>n;
    a[0]=1;
    t=0;
    lietke(1,0);
    return 0;
}
