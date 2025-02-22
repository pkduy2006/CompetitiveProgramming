#include<bits/stdc++.h>
using namespace std;
long n,m,i,j,a[10000];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        m=i; j=2;
        while(m>1)
        {
            if(m%j==0)
            {
                a[j]++;
                m/=j;
            }
            else
                j++;
        }
    }
    for(i=1;i<=n;i++)
        if(a[i]>0) cout<<a[i]<<' ';
    return 0;
}
