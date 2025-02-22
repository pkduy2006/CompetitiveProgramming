#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,tong,kq,l[30001],maxl;

bool catthu (long long m)
{
    long long tong=0;
    for (long long i=1;i<=n;i++)
    {
        tong = tong +l[i]/m;
    }
    if (tong >= k) return 1;
    return 0;

}
void tknp (long long l,long long r)
{
    long long mid;
    while (l<=r)
    {
        mid = (l+r)/2;
        if (catthu(mid))
        {
            kq=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout<<kq;
}
int main()
{
    cin>>n>>k;
    for (i=1;i<=n;i++)
    {
        cin>>l[i];
        maxl=max(maxl,l[i]);
    }
    tknp (1,maxl);
}
