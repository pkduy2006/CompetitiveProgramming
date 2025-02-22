#include<bits/stdc++.h>
using namespace std;
int n,x[21];
void print(int n)
{
    for(int i=1;i<=n;i++)
        cout<<x[i];
    cout<<endl;
}
void xaunp(int i)
{
    for(int j=0;j<=1;j++)
    {
        x[i]=j;
        if(i==n) print(i);
        else xaunp(i+1);
    }
}
int main()
{
    cin>>n;
    xaunp(1);
    return 0;
}
