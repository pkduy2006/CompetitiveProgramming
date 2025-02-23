#include<bits/stdc++.h>
using namespace std;
const int nm=1e6+1;
#define int long long
int n,i,j,a[nm],dmax=-nm,d[nm];
main()
{
    freopen("bai1.inp","r",stdin);
    freopen("bai1.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    d[0]=nm;
    for(i=1;i<=n;i++)
        d[i]=min(a[i],d[i-1]);
    for(j=2;j<=n;j++)
        dmax=max(dmax,a[j]-d[j-1]);
    cout<<dmax;
    return 0;
}
