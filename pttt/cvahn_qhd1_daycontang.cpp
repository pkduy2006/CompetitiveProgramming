#include <bits/stdc++.h>
using namespace std;
const int nm=10001;
int n,i,j,vtm, a[nm], b[nm], c[nm], d[nm], dem=0;
void taobang()
{
    c[1]=0;b[1]=1;
    for(i=2; i<=n; i++)
        {
        for(j=i-1; j>=1; j--)
            if(a[i]>a[j] && b[i]<b[j])
            {
            b[i]=b[j];
            c[i]=j;
            }
        b[i]++;
        }
}
void truyhoi()
{
    vtm=n;
    for(i=n-1; i>=1; i--)
        if(b[vtm]<b[i]) vtm=i;
    while(vtm>0)
    {
        dem++;
        d[dem]=a[vtm];
        vtm=c[vtm];
    }
    cout<<dem<<endl;
    for(i=dem; i>=1; i--)
        cout<<d[i]<<" ";
}
int main()
{
    freopen("daycont.inp","r",stdin);
    freopen("daycont.out","w",stdout);
    
    cin>>n;
    for(i=1; i<=n; i++)cin>>a[i];
    taobang();
    truyhoi();
    return 0;
}
