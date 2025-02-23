#include<bits/stdc++.h>
using namespace std;
void giaithua(long long int n){

      int a[500000],i,j,m=1;
      long long r=0,q;
      a[0]=1;
      for(i=2;i<=n;i++)
    {
        for(j=0;j<m;j++)
        {
           q=r;
           r=(a[j]*i+r)/10;
          a[j]=(a[j]*i+q)%10;
        }
        while(r>0)
        {
          a[m]=r%10;
          m++;
          r=r/10;
        }
    }
    for(i=m-1;i>=0;i--)cout<<a[i];
}
int main()
{
    freopen("gtsl.inp","r",stdin);
    freopen("gtsl.out","w",stdout);
    long long int n;
    cin>>n;
    giaithua(n);
    return 0;
}
