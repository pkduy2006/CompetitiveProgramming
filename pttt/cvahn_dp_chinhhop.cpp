#include<bits/stdc++.h>
using namespace std;
int n,a[100],k;
void inkq(int n)
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}
void chinhhop(int i)
{
    for(int j=1;j<=n;j++)
    {
        a[i]=j;
        if(i==k) inkq(i);
        else chinhhop(i+1);
    }
}
int main()
{
    cin>>n>>k;
    chinhhop(1);
    return 0;
}
