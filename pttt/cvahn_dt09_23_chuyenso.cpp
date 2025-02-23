#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,i,j,x;
queue<int>q;
main()
{
    freopen("chuyenso.inp","r",stdin);
    freopen("chuyenso.out","w",stdout);
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        q.push(x);
    }
    k%=n;
    for(i=1;i<=k;i++)
    {
        x=q.front();
        q.pop();
        q.push(x);
    }
    for(i=1;i<=n;i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
